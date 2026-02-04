#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;

    int kvadrob = 0;

    while (a > 0 && b > 0) {
        if (a >= b) {
            int k = a / b;
            std::cout << b << " " << k << std::endl;
            kvadrob += k;
            a = a % b;
        }
        else {
            int k = b / a;
            std::cout << a << " " << k << std::endl;
            kvadrob += k;
            b = b % a;
        }
    }
    std::cout << kvadrob << std::endl;
    return 0;
}