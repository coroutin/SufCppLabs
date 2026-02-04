#include <iostream>

int main() {
    long long n, fn, sum = 0;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            fn = 1;
            std::cout << fn;
        }
        if (i > 1) {
            fn = (i * 2) - 1;
            std::cout << " " << "+" << " " << fn;
        }
        sum += fn;
    }
    std::cout << " " << "=" << " " << sum;
    return 0;
}