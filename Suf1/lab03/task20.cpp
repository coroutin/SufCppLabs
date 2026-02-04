#include <iostream>

int main() {
    int n, an, kakaha2 = 0, kakaha3 = 99999, k = 0, chupep = 0;

    std::cin >> n;

    for (int i = 1; i <= n; i++) {
        std::cin >> an;
        k++;

        if (an % 3 == 0 && an < kakaha3) {kakaha3 = an;}
        if (an % 2 == 0 && chupep <= k) {kakaha2 = an; chupep = 99999;}
    }
    if (kakaha2 != 0 && kakaha3 != 99999) {std::cout << kakaha2 * kakaha3<< std::endl;}
    else if (kakaha2 == 0 && kakaha3 != 99999) {std::cout << "NO " << kakaha3 << std::endl;}
    else if (kakaha2 != 0 && kakaha3 == 99999) {std::cout << kakaha2 << " NO" << std::endl;}
    else {std::cout << "NO NO" << std::endl;}
    return 0;
}