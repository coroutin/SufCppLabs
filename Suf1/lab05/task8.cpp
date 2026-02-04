#include <iostream>

long long first_prime(long long num) {
    if (num % 2 == 0) {return 2;}

    for (long long i = 3; i * i <= num; i += 2) {
        if (num % i == 0) {return i;}
    }
    return num;
}

int main() {
    long long num;
    std::cin >> num;

    while (num > 1) {
        long long prime = first_prime(num);

        if (num % (prime * prime) == 0) {
            std::cout << "NO";
            return 0;
        }

        num /= prime;
    }

    std::cout << "YES";
    return 0;
}