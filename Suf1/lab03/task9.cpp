#include <iostream>

int main() {
    int inp;
    std::cin >> inp;
    while (inp < 1000 || 9999 < inp) {
        std::cin >> inp;
    }
    if (inp / 1000 + inp / 100 % 10 == inp % 100 / 10 + inp % 10) {std::cout << "YES";}
    else {std::cout << "NO";}
    return 0;
}