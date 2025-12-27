#include <algorithm>

int** init_snake(int row, int col) {
    int** array = new int*[row];
    for (int i = 0; i < row; ++i) {
        array[i] = new int[col];
    }

    int value = 1;
    for (int j = 0; j < col; ++j) {
        if (j % 2 == 0) {
            for (int i = 0; i < row; ++i) {
                array[i][j] = value++;
            }
        } else {
            for (int i = row - 1; i >= 0; --i) {
                array[i][j] = value++;
            }
        }
    }

    return array;
}