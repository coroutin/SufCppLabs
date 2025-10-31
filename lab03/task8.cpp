#include <iostream>

int main() {
    int inp, k=0;
    std::cin >> inp;
    if (inp % 7 != 0 && inp > 0) { k++; }
    while (inp % 7 != 0) {
        std::cin >> inp;
        if (inp > 0 && inp % 7 != 0) { k++; }
    }
    std::cout << k;
}