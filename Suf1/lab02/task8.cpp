#include <iostream>

int main() {
    int x1, x2, y1, y2;
    std::cin >> x1 >> y1;
    std::cin >> x2 >> y2;

    if (abs(x2 - x1) == 2 && abs(y2 - y1) == 1 || abs(x2 - x1) == 1 && abs(y2 - y1) == 2) {
        std::cout << "1";
    }
    else {std::cout << "0";}
    return 0;
}