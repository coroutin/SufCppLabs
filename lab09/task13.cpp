#include <iostream>

int main() {
    int rows, cols;

    std::cout << "Введите размер массива (строки, столбцы): ";
    std::cin >> rows >> cols;

    while (cols < 1 || rows < 1) {
        std::cout << "Ошибка! Введите размер масссива заново: \n";
        std::cin >> rows >> cols;
    }

    int arr[rows][cols];

    std::cout << "\nВведите элементы массива (" << rows << " x " << cols << "):\n";
    for (int i = 0; i < rows; ++i) {
        std::cout << "Строка " << (i + 1) << ": ";
        for (int j = 0; j < cols; ++j) {
            while (!(std::cin >> arr[i][j])) {
                std::cout << "Ошибка! Введите целое число для позиции [" << i << "][" << j << "]: ";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            }
        }
    }

    std::cout << "\nИсходный массив (" << rows << " x " << cols << "):\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << arr[i][j] << "\t";
        }
        std::cout << "\n";
    }
    std::cout << "\n";

    int target;
    std::cout << "Введите элемент, строки с которым нужно удалить: ";
    while (!(std::cin >> target)) {
        std::cout << "Ошибка! Введите целое число: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    int deleted_count = 0;

    int i = 0;
    while (i < rows) {
        bool contains = false;
        for (int j = 0; j < cols; ++j) {
            if (arr[i][j] == target) {
                contains = true;
                break;
            }
        }

        if (contains) {
            for (int k = i; k < rows - 1; ++k) {
                for (int j = 0; j < cols; ++j) {
                    arr[k][j] = arr[k + 1][j];
                }
            }
            rows--;
            deleted_count++;
        }
        else {
            i++;
        }
    }

    if (deleted_count == 0) {
        std::cout << "Сообщение: строки, содержащие элемент " << target << ", не найдены.\n";
    }
    else {
        std::cout << "Удалено строк: " << deleted_count << "\n";
        std::cout << "Массив после удаления (" << rows << " x " << cols << "):\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << arr[i][j] << "\t";
            }
            std::cout << "\n";
        }
    }

    return 0;
}