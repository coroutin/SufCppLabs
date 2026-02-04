#include <iomanip>
#include <iostream>

double f(double x, double eps) {

    double tochn = pow(10.0, eps);

    if (fabs(x - (-1.0)) <= tochn) {return 0.0;}

    double result = x * x - fabs(x + 1.0) / (x + 1.0) - 1.0;
    return result;
}

int main() {
    double a, b, step;
    int eps;

    std::cin >> a >> b;
    std::cin >> step;
    std::cin >> eps;

    std::cout << std::fixed << std::setprecision(5);

    for (double i = a; i <= b; i += step) {
        std::cout << f(i, eps) << std::endl;
    }
    return 0;
}