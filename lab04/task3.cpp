#include <iostream>
#include <cmath>
#include <string>

int main() {
    long long n;
    std::cin >> n;

    for (long long i = 1; i <= n; i++) {
        int c = 0;
        for (long long j = 1; j <= sqrt(i); j++) {
            if (i % j == 0) {
                c++;
                if (j != i / j)
                    c++;
            }
        }

        std::cout << i << std::string(c, '+') << '\n';
    }
}