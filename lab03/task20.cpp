#include <iostream>

int main() {
    int n, an, kakaha2 = 0, kakaha3 = 9999999, k = 0;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> an;
        k++;

        if (an % 3 == 0) {if (an < kakaha3) {kakaha3 = an;}}
        if (an % 2)
    }
    std::cout << kakaha3 << std::endl;
    return 0;
}