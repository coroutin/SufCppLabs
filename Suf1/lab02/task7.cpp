#include <iostream>

int main() {
    int x1, x2, y1, y2;
    std::cin >> x1 >> y1;
    std::cin >> x2 >> y2;

    if ((x1 == x2) || (y1 == y2) || (abs(x1 - x2) == abs(y1 - y2))) {
        std::cout << "1";
    }
    else {std::cout << "0";}
    return 0;
}