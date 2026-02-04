#include <iostream>

int main() {
    int row, col;
    std::cin >> row >> col;

    int** a = new int*[row];
    for (int i = 0; i < row; ++i) {
        a[i] = new int[col];
        for (int j = 0; j < col; ++j) {
            std::cin >> a[i][j];
        }
    }

    for (int i = 0; i < row / 2; ++i) {
        int* temp = a[i];
        a[i] = a[row - 1 - i];
        a[row - 1 - i] = temp;
    }

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < row; ++i) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}