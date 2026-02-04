#include <iostream>
#include <cmath>

int main() {
    double a, b, c;
    std::cin >> a >> b >> c;
    if (fabs(a) < pow(10, -10)) {
        if (fabs(b) > pow(10, -10)) {std::cout << "1";}
        else {std::cout << "0";}
    }
    else{
        if (fabs(pow(b, 2) - 4 * a * c) < pow(10, -10)) {std::cout << "1";}
        else {std::cout << "0";}
    }
    return 0;
}