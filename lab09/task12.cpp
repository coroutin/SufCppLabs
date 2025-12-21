#include <iostream>

int main() {
    int cols;
    int rows;

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

    std::cout << "Исходный массив (" << rows << " x " << cols << "):\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << arr[i][j] << "\t";
        }
        std::cout << "\n";
    }

    int delete_row;
    std::cout << "Введите строку для удаления: ";
    std::cin >> delete_row;

    while (delete_row > rows || delete_row < 0) {
        std::cout << "Неверно введена строка для удаления.\n";
        std::cout << "Введите строку для удаления заново: ";
        std::cin >> delete_row;
    }

    // Удаление строки: сдвигаем все строки ниже на одну позицию вверх
    for (int i = delete_row; i < rows - 1; ++i) {
        for (int j = 0; j < cols; ++j) {
            arr[i][j] = arr[i + 1][j];
        }
    }

    rows--;

    std::cout << "\nМассив после удаления строки " << delete_row << " ("
              << rows << " x " << cols << "):\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << arr[i][j] << "\t";
        }
        std::cout << "\n";
    }

    return 0;
}