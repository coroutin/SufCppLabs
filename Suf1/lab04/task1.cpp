#include <iostream>

int n;

int main() {

    std::cin >> n;

    for (int i = n; i >= 0; i--) {
        for (int d = 1; d <= n - i; d++) {
            std::cout << " ";
        }
        for (int j = i; j > 0; j--) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    return 0;
}