#include <iostream>

bool Prime(long long x) {
    if (x < 2) {return false;}
    for (long long i = 2; i * i <= x; i++) {
        if (x % i == 0) {return false;}
    }
    return true;
}

int main() {
    long long a, b;
    std::cin >> a >> b;

    bool found = false;
    long long prev_prime = -1;

    for (long long i = a; i <= b; i++) {
        if (Prime(i)) {
            if (prev_prime != -1 && i - prev_prime == 2) {
                std::cout << prev_prime << " " << i << "\n";
                found = true;
            }
            prev_prime = i;
        }
    }

    if (!found) {
        std::cout << "NO";
    }

    return 0;
}


