#include <iostream>

int main() {
    int N;

    std::cout << "Введите N: ";
    while (!(std::cin >> N) || N < 1) {
        std::cout << "Ошибка! Введите целое положительное число: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    int* arr[N];

    for (int i = 0; i < N; ++i) {
        int row_length = i + 1;
        arr[i] = new int[row_length];

        for (int j = 0; j < row_length; ++j) {
            arr[i][j] = i + 1;
        }
    }

    std::cout << "\nСозданный массив для N = " << N << ":\n\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= i; ++j) {
            std::cout << arr[i][j] << "\t";
        }
        std::cout << "\n";
    }

    for (int i = 0; i < N; ++i) {
        delete[] arr[i];
    }

    return 0;
}