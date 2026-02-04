#include <iostream>

int main() {
    long long n, fn, fac = 1;
    std::cin >> n;
    if (n % 2 != 0) {
        for (int i = 1; i <= n; i += 2) {
            fac *= i;
        }
    }
    if (n % 2 == 0) {
        for (int i = 2; i <= n; i += 2) {
            fac *= i;
        }
    }
    std::cout << fac;
    return 0;
}