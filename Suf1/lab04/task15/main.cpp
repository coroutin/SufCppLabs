#include "task15.h"
#include <iostream>


int main() {
    int num;
    std::cout << "Введите длину числа (1..100): ";
    std::cin >> num;

    while (num < 1 || num > 100) {
        std::cout << "Неверная длина числа." << '\n';
        std::cin >> num;
    }

    game(num);
    return 0;
}
