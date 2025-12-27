#include <iostream>
#include <climits>

int main() {
    int N;
    std::cin >> N >> N;

    int** a = new int*[N];
    for (int i = 0; i < N; ++i)
        a[i] = new int[N];

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            std::cin >> a[i][j];

    int max_val = INT_MIN;
    int max_row = -1;
    int max_col = -1;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (j <= i && j <= N-1-i || j >= i && j >= N-1-i) {
                if (a[i][j] > max_val) {
                    max_val = a[i][j];
                    max_row = i;
                    max_col = j;
                }
            }
        }
    }

    std::cout << max_val << " " << max_row << " " << max_col << '\n';

    for (int i = 0; i < N; ++i)
        delete[] a[i];
    delete[] a;

    return 0;
}