#include <iostream>
#include <cmath>

int main() {
    int n;
    std::cin >> n;

    int sum = 0;
    int im = 0;

    for (int i = 1; i <= n; i++) {
        int ms = 0;
        for (int j = 1; j <= sqrt(i); j++) {
            if (i % j == 0) {
                ms += j;
                if (j != i / j)
                    ms += i / j;
            }
            if (ms > sum) {
                sum = ms;
                im = i;
            }
        }
    }
    std::cout << im << " " << sum;
}