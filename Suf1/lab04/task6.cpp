#include <iostream>

int anal_torment_for_finding_gcd (long long x, long long y) {
    while (y != 0) {
        long long temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

int main() {
    long long n;

    std::cin >> n;

    for (long long i = 2; i <= n; i++) {
        for (long long j = 1; j < i; j++) {
            if (anal_torment_for_finding_gcd(i, j) == 1) {std::cout << j << "/" << i << " ";}
        }
        std::cout << '\n';
    }
    return 0;
}