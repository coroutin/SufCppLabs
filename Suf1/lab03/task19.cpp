#include <iostream>

int main() {
    int n, an, otr = 0, pol = 0, b = 0, c = 0, k = 0, sum = 0;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> an;
        k++;
        if (an < 0) {otr++;}
        if (an > 0) {pol++;}
        if (k % 2 == 0 && an % 2 != 0) {b++;}
        if (abs(an) < k * k) {c++; sum += an;}
    }
    if (otr > pol) {std::cout << "-" << std::endl;}
    else if (otr < pol) {std::cout << "+" << std::endl;}
    else if (otr == pol) {std::cout << "0" << std::endl;}
    std::cout << b << std::endl;
    if (c != 0) {std::cout << sum << std::endl;}
    else if (c == 0) {std::cout << "NO" << std::endl;}
}