#include <iostream>
#include <cmath>

int compare_to(double num1, double num2, double eps) {
    if (fabs(num1 - num2) <= pow(10, eps)) return 0;
    else if (num1 < num2 ) return -1;
    else return 1;
}

double f(double x) {return x * cos(x);}

int main() {
    double a, b, eps, step;

    std::cin >> a >> b;
    std::cin >> step;
    std::cin >> eps;

    double prev_y = f(a);

    for (double i = a + step; i <= b; i += step) {

        double cur_x = (i > b) ? b : i;
        double cur_y = f(cur_x);

        if (compare_to(prev_y, cur_y, eps) >= 0) {
            std::cout << "NO" << std::endl;
            return 0;
        }

        prev_y = cur_y;
    }

    std::cout << "YES" << std::endl;
    return 0;
}