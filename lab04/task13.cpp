#include <iostream>

int divs(int num) {
    int sum = 0;

    for (int i = 1; i < num; i++) {
        if (num % i == 0) {sum += i;}
    }
    return sum;
}

int main() {
    long long n, m;
    bool found = false;
    std::cout << "Введите натуральные числа n и m через пробел: ";
    std::cin >> n >> m;

    for (int i = n; i <= m; i++) {
        for (int j = i + 1; j <= m; j++) {
            if (divs(i) == j && divs(j) == i) {
                if (!found) {
                    std::cout << "Пары дружественных чисел: " << '\n';
                    found = true;
                }
                std::cout << i << " " << j << '\n';
            }
        }
    }
    if (!found) {std::cout << "Нет пар чисел–дружиков";}
}