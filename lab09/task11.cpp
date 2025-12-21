#include <iostream>

int main() {
    int M = 6;
    int N = 6;

    int arr[M][N];

    int num = 1;
    int top = 0;
    int bottom = M - 1;
    int left = 0;
    int right = N - 1;

    while (top <= bottom && left <= right) {
        // Вправо по верхней строке
        for (int j = left; j <= right; ++j) {
            arr[top][j] = num++;
        }
        top++;

        // Вниз по правому столбцу
        for (int i = top; i <= bottom; ++i) {
            arr[i][right] = num++;
        }
        right--;

        // Влево по нижней строке, если остались строки
        if (top <= bottom) {
            for (int j = right; j >= left; --j) {
                arr[bottom][j] = num++;
            }
            bottom--;
        }

        // Вверх по левому столбцу, если остались столбцы
        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                arr[i][left] = num++;
            }
            left++;
        }
    }


    std::cout << "Массив 6 x 6, заполненный спиралью по часовой стрелке:\n";
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << arr[i][j] << "\t";
        }
        std::cout << "\n";
    }

    return 0;
}