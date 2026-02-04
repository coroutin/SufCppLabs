#include <iostream>

int main() {
    int n, an, k = 0, min2 = 10001, messenger_max = -10001, messenger_max2 = -10001, max3 = -10001;

    std::cin >> n;

    for (int i = 1; i <= n; i++) {
        std::cin >> an;
        k++;
        if (k % 2 == 0 && an < min2) {min2 = an;}
        if (k % 2 != 0 && an > max3) {max3 = an;}
        if (an > messenger_max) {messenger_max2 = messenger_max, messenger_max = an;}
        else if (an < messenger_max && an > messenger_max2) {messenger_max2 = an;}
    }

    std::cout << min2 + max3 << std::endl;
    std::cout << messenger_max2 << std::endl;
    return 0;
}