#include <iostream>

bool Prime(long long x) {
    if (x < 2) {return false;}
    for (long long i = 2; i * i <= x; i++) {
        if (x % i == 0) {return false;}
    }
    return true;
}

int main() {

    long long n;
    bool perviiiiiiiiy = true;

    std::cin >> n;

    if (n % 2 == 0) {
        if (!perviiiiiiiiy) {std::cout << " ";}
        std::cout << 2;
        perviiiiiiiiy = false;
        while (n % 2 == 0) {n /= 2;}
    }

    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0 && Prime(i)) {
            if (!perviiiiiiiiy) {std::cout << " ";}
            std::cout << i;
            perviiiiiiiiy = false;
            while (n % i == 0) {n /= i;}
        }
    }
    if (n > 1) {
        if (!perviiiiiiiiy) {std::cout << " ";}
        std::cout << n;
    }

    return 0;
}