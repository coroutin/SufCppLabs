#include <iostream>

int main() {
    long long a, b, t;
    std::cin >> a;
    std::cin >> b;
    std::cin >> t;
    if (t % a == 0 || t % b == 0) {std::cout << "0";}
    else {std::cout << std::min(a - t % a, b - t % b);}
    return 0;
}