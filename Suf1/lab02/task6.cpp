#include <iostream>

int main() {
    int x1, x2, y1, y2, c1, c2;
    std::cin >> x1 >> y1;
    std::cin >> x2 >> y2;

    if (x1 % 2 != 0 && y1 % 2 != 0) {c1 = 0;}
    if (x1 % 2 != 0 && y1 % 2 == 0) {c1 = 1;}
    if (x1 % 2 == 0 && y1 % 2 != 0) {c1 = 1;}
    if (x1 % 2 == 0 && y1 % 2 == 0) {c1 = 0;}

    if (x2 % 2 != 0 && y2 % 2 != 0) {c2 = 0;}
    if (x2 % 2 != 0 && y2 % 2 == 0) {c2 = 1;}
    if (x2 % 2 == 0 && y2 % 2 != 0) {c2 = 1;}
    if (x2 % 2 == 0 && y2 % 2 == 0) {c2 = 0;}

    if (c1 == c2) {std::cout << "1";}
    else {std::cout << "0";}

    return 0;
}