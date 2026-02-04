#include <cmath>

int* row_elements(int** array, int row, int col) {
    int min_row = 0;
    int min_rum = 0;

    for (int j = 0; j < col; ++j) {
        min_rum += abs(array[0][j]);
    }

    for (int i = 1; i < row; ++i) {
        int sum = 0;
        for (int j = 0; j < col; ++j) {
            sum += abs(array[i][j]);
        }
        if (sum <= min_rum) {
            min_rum = sum;
            min_row = i;
        }
    }

    int* result = new int[col];
    for (int j = 0; j < col; ++j) {
        result[j] = array[min_row][j];
    }

    return result;
}

int* col_elements(int** array, int row, int col) {
    int maxCol = 0;
    int maxSum = 0;

    for (int i = 0; i < row; ++i) {
        maxSum += abs(array[i][0]);
    }

    for (int j = 1; j < col; ++j) {
        int sum = 0;
        for (int i = 0; i < row; ++i) {
            sum += abs(array[i][j]);
        }
        if (sum > maxSum) {
            maxSum = sum;
            maxCol = j;
        }
    }

    int* result = new int[row];
    for (int i = 0; i < row; ++i) {
        result[i] = array[i][maxCol];
    }

    return result;
}