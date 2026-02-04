#include <iostream>

int main() {
    long long n, k = 0;
    std::cin >> n;

    if (n < 2) {
        std::cout << "NO";
        return 0;
    }
    if (n == 2) {
        std::cout << "YES";
        return 0;
    }
    if (n % 2 == 0) {
        std::cout << "NO";
        return 0;
    }

    bool isPrime = true;
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            isPrime = false;
        }
    }

    if (isPrime) {std::cout << "YES";}
    else {std::cout << "NO";}

    return 0;
}