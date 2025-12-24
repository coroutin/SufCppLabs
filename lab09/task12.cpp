#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    int cols;
    int rows;

    std::cout << "Введите размер массива (строки, столбцы): ";
    std::cin >> rows >> cols;

    while (cols < 1 || rows < 1) {
        std::cout << "Ошибка! Введите размер массива заново:\n";
        std::cin >> rows >> cols;
    }

    int arr[rows][cols];

    srand(time(nullptr));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            arr[i][j] = rand() % 100;
        }
    }

    std::cout << "\nИсходный массив (" << rows << " x " << cols << "):\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << arr[i][j] << "\t";
        }
        std::cout << "\n";
    }

    int delete_row;
    std::cout << "Введите строку для удаления (нумерация с 0): ";
    std::cin >> delete_row;

    while (delete_row < 0 || delete_row >= rows) {
        std::cout << "Неверно введена строка для удаления.\n";
        std::cout << "Введите строку для удаления заново: ";
        std::cin >> delete_row;
    }

    for (int i = delete_row; i < rows - 1; ++i) {
        for (int j = 0; j < cols; ++j) {
            arr[i][j] = arr[i + 1][j];
        }
    }

    rows--;

    std::cout << "\nМассив после удаления строки " << delete_row
              << " (" << rows << " x " << cols << "):\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << arr[i][j] << "\t";
        }
        std::cout << "\n";
    }

    return 0;
}
