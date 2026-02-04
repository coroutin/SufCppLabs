#include "task14.h"
#include <iostream>
#include <random>

void init_game(long &pile, int &max_stones, bool &computer_mode)
{
    std::cout << "Введите количество камней: ";
    std::cin >> pile;
    while (pile <= 0){
        std::cout << "Неадекватное число камней, введите число ещё раз.";
        std::cin >> pile;
    }

    std::cout << "Введите максимум камней за ход: ";
    std::cin >> max_stones;
    while (max_stones <= 0 || max_stones > pile) {
        std::cout << "Неадекватное число камней, введите число ещё раз.";
        std::cin >> max_stones;
    }

    int mode;
    std::cout << "Режим (1 — компьютер знает стратегию, 2 — компьютер не знает стратегии): ";
    std::cin >> mode;
    while (mode != 1 && mode != 2) {
        std::cout << "Неадекватное число выбора режима, введите число ещё раз.";
        std::cin >> mode;
    }

    computer_mode = (mode == 1);
}

void pile_current(long pile, int max_stones)
{
    std::cout << '\n' << "В куче " << pile << " камней (максимум взять: " << max_stones << ")" <<'\n';
}

void player_move(long &pile, int max_stones)
{
    int take;
    std::cout << "Ваш ход. Введите число камней: ";
    std::cin >> take;
    while (take <= 0 || take > max_stones || take > pile) {
        std::cout << "Неадекватное число камней, введите число ещё раз.";
        std::cin >> take;
    }
    pile -= take;
    std::cout << "Вы взяли " << take << '\n';
}

int computer_move_strategy(long &pile, int max_stones)
{
    int take;
    long mod  = pile % (max_stones + 1);    // Остаток от деления количества камней на максимально возможное количество камней + 1
    if (mod == 0) take = 1;    // Остаток = 0 означает проигрышную позицию, берём 1, чтобы продолжить игру
    else take = mod;    // Остаток != = означает выйгрышную позицию, берём mod камней чтобы у противника осталось количество камней кратное max_stones + 1

    if (take > pile) take = pile;

    pile -= take;
    std::cout << "Компьютер (знает стратегию) взял " << take << '\n';
    return take;
}

int computer_move_no_strategy(long &pile, int max_stones)
{
    static std::mt19937 gen(std::random_device{}());    // Генератор случайных чисел
    int limit = std::min(pile, (long)max_stones);   // Лимит для выбора
    std::uniform_int_distribution<int> dist(1, limit);  //Распределение (преобразование числа из генератора в диапазон для одинаковой вероятности выбора любого камня)

    int take = dist(gen);   // Генерация случайного числа – количество камней которое возьмёт компьютер
    pile -= take;
    std::cout << "Компьютер (не знает стратегию) взял " << take << '\n';
    return take;
}
