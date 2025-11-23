#include <iostream>

int divs(int num) {
    long sum = 0;

    for (int i = 1; i < num; i++) {
        if (num % i == 0) {sum += i;}
    }
    return sum;
}

int main() {
    int n, m;
    std::cout << "Введите натуральные числа n и m через пробел";
    std::cin >> n >> m;

    for (int i = n; i <= m; i++) {
        for (int j = n; j <= m; j++) {
            if (divs(i) == j && divs(j) == i && i != j) {std::cout << "Пары дружественных чисел: "; std::cout << i << " " << j << '\n';}
        }
    }
}