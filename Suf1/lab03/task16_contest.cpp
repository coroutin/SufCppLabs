#include <iostream>
#include <cmath>

int main() {
    long long n, del;
    std::cin >> n;
    for (int i = 1; i <= pow(n, 0.5); i ++) {
        del = n /i;
        if (n % i == 0) {
            std::cout << i << " " << del << std::endl;
        }
    }
    return 0;
}