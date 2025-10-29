#include <iostream>

int main() {
    long long n, n1;
    int d;
    int s = 0;
    std::cin >> n;
    n1 = n;
    while (n1 > 0) {
        d = n1 % 10;
        if (d % 2 != 0) {
            s += d;
        }
        n1 /= 10;
    }
    std::cout << s << std::endl;
    if (s == 0) {std::cout << "NO";}
    else if (n % s == 0) {std::cout << 1 << std::endl;}
    else {std::cout << 0 << std::endl;}
    return 0;
}