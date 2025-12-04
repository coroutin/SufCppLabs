#include <cmath>
#include <iostream>

int solution_quadratic(int a, int b, int c, double &x1, double &x2) {
    if (a == 0) {
        if (b == 0) {
            x1 = x2 = 0;
            return 0;
        }
        else {
            x1 = x2 = -double(c) / b;
            return 1;
        }
    }
    double D = (double(b) * b) - 4 * a * c;
    if (D > 0) {
        x1 = (-double(b) + std::sqrt(D)) / (2 * a);
        x2 = (-double(b) - std::sqrt(D)) / (2 * a);
        return (2);
    }
    if (D == 0) {
        x1 = x2 = -double(b) / (2 * a);
        return 1;
    }
    if (D < 0) {
        x1 = x2 = 0;
        x2 = 0;
        return 0;
    }
}

int main() {
    int a, b, c;
    double x1, x2;
    std::cin >> a >> b >> c;
    std::cout << solution_quadratic(a, b, c, x1, x2) << " ";
    std::cout << x1 << " " << x2;
}