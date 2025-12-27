#include <algorithm>
#include <cmath>

int** init_frame(int n) {
    int** array = new int*[n];
    for (int i = 0; i < n; ++i) {
        array[i] = new int[n];
    }

    int center = n / 2;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int dist = std::max(std::abs(i - center), std::abs(j - center));
            array[i][j] = dist;
        }
    }

    return array;
}