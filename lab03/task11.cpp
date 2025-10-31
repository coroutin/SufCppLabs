#include <iostream>

int main() {
    int n, nn;
    int k = 0;

    std::cin >> nn;

    if (nn == 100) {
        std::cout << 0 << std::endl;
        return 0;
    }

    k = 1;

    while (std::cin >> n && n != 100 && n > nn) {
        nn = n;
        k++;
    }

    std::cout << k << std::endl;

    return 0;
}