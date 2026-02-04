#include <iostream>
#include <cmath>

int solve_quadratic(int a, int b, int c, double &x1, double &x2) {
    const double eps = pow(10, -10);

    if (a == 0) {
        if (b == 0) {
            return 0;
        }
        else {
            x1 = x2 = -double(c) / b;
            return 1;
        }
    }

    double D = double(b) * b - 4.0 * a * c;

    if (D > eps) {
        x1 = (-double(b) + std::sqrt(D)) / (2 * a);
        x2 = (-double(b) - std::sqrt(D)) / (2 * a);
        return 2;
    }
    else if (D < -eps) {
        return 0;
    }
    else {
        x1 = x2 = -double(b) / (2 * a);
        return 1;
    }
}

int main() {
    int a, b, c;
    double x1 = 0, x2 = 0;

    std::cout << "Введите коэффициенты квадратного уравнения: ";
    std::cin >> a >> b >> c;

    int kor = solve_quadratic(a, b, c, x1, x2);

    if (kor == 0) {
        std::cout << "Корней нет в множестве действительных чисел.\n";
    } else if (kor == 1) {
        std::cout << "Один корень: x = " << x1 << "\n";
    } else {
        std::cout << "Два корня: x1 = " << x1 << ", x2 = " << x2 << "\n";
    }

    return 0;
}
