#include <iostream>

int main() {
    long long a, b;
    std::cin >> a >> b;
    while (b != 0) {
        long long kami = b;
        b = a % b;
        a = kami;
    }
    if (a == 1) {std::cout << "YES" << std::endl;}
    else {std::cout << "NO" << std::endl;}
    return 0;
}