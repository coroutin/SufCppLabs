#include "task15.h"
#include <iostream>
#include <random>

int player_move(int move) {
    int dig;
    bool first = true;

    std::cout << "Ход " << move << " — введите цифру (0..9): ";
    std::cin >> dig;

    if (first) {
        while (dig <= 0 || 9 < dig) {
            std::cout << "Неадекватное число, ведите число ещё раз: ";
            std::cin >> dig;
        }
        first = false;
    }

    while (dig < 0 || 9 < dig) {
        std::cout << "Неадекватное число, ведите число ещё раз: ";
        std::cin >> dig;
        first = false;
    }

    return dig;
}

int computer_move(int current_remainder, int moves_left) {
    int dig;
    static std::mt19937 gen(std::random_device{}());    // Cтатический генератор случайных чисел
    std::uniform_int_distribution<int> dist(0, 9);    // Распределение на диапазон 0-9

    if (moves_left == 0) {
        // На последнем ходе пытается выиграть
        dig = (9 - current_remainder) % 9;
    } else {
        dig = dist(gen);    // Генерация случайного числа которое выберет компьютер
    }

    std::cout << "Компьютер выбрал: " << dig << '\n';
    return dig;
}

void check_winner(int num, int remainder) {
    bool end = (remainder == 0);
    bool last_player = (num % 2 == 1);

    std::cout << '\n';

    if (end) {
        std::cout << "Число делится на 9. Победил последний игрок: "
                  << (last_player ? "Вы" : "Компьютер");
    } else {
        std::cout << "Число не делится на 9. Проиграл последний игрок: "
                  << (last_player ? "Вы" : "Компьютер");
    }
}

void game(int num) {
    int remainder = 0;
    int number = 0;

    std::cout << '\n' << "Число: ";

    for (int move = 1; move <= num; move++) {
        int dig;
        bool user_turn = (move % 2 == 1);

        if (user_turn) {
            dig = player_move(move);
        } else {
            int moves_left = num - move;
            dig = computer_move(remainder, moves_left);
        }
        number = number * 10 + dig;
        std::cout << number<< "\n";

        // Обновляем остаток числа по модулю 9
        remainder = (remainder + dig) % 9;
    }

    check_winner(num, remainder);
}