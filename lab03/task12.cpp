#include <iostream>

int main() {
    long long m, f1 = 0, f2 = 1, n;
    std::cin >> m;
    while (m >= f2) {
        n = f1 + f2;
        f1 = f2;
        f2 = n;
    }
    std::cout << f2;
}