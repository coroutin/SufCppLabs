#include <iostream>

int del_count(long long num) {
    if (num <= 0) return 0;

    int c = 0;
    for (long long i = 1; i * i <= num; i++) {
        if (num % i == 0) {
            c += (i == num / i) ? 1 : 2;
        }
    }
    return c;
}

int main() {
    long long n;
    std::cin >> n;
    std::cout << del_count(n);
}