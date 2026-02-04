#include <iostream>
#include <cmath>

int main() {
    long long n = 0;
    std::cin >> n;
    double s;
    s = sqrt(n);
    if (pow(round(s), 2) == n) {std::cout << "1";}
    else {std::cout << "0";}
    return 0;
}