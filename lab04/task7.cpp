#include <iostream>

int main() {
    long long n;
    std::cin >> n;

    for (long long a = 1; a < n; a++) {
        for (long long b = a + 1; b < n; b++) {
            for (long long c = 1; c <= n; c++) {
                if (a * a + b * b == c * c) {std::cout << a << " " << b << " " << c << '\n';}
            }
        }
    }
    return 0;
}