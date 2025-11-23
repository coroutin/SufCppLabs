#include <iostream>

int div(long long num) {
    int c = 0;
    for (long long i = 1; i <= num; i++) {
        if (num % i == 0) {
            c++;
        }
    }
    return c;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << div(n);
}