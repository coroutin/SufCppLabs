#include <iostream>

int main() {
    long long n;
    std::cin >> n;
    if (n < 4) {std::cout << "-1";}
    else {std::cout << (n-1 + 4) / 5;}
    return 0;
}