#include <iostream>

bool is_prime(long long x) {
    if (x < 2) { std::cout << "NO";}
    for (long long i = 2; i * i <= x; i++) {
        if (x % i == 0) {std::cout << "NO";}
    }
    std::cout << "YES";
}
