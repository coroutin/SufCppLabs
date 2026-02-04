#include <iostream>

int main() {
    long long n, n1;
    int k = 0;
    std::cin >> n;
    n1 = n;
    while (n1 > 0) {
        k++;
        n1 /= 10;
    }
    long long p = 1;
    for (int i = 1; i < k;) {
        p *= 10;
        i++;
    }
    int fd = n / p;
    int ld = n % 10;
    long long md = n % p;
    md /= 10;
    long long nn = ld * p + md * 10 + fd;
    std::cout << nn << std::endl;
    std::cout << nn * 2;
    return 0;
}