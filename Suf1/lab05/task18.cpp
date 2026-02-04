#include <iostream>

int zero_digits_count(long long n) {
    int cnt = 0;
    int pos = 0;
    n = llabs(n);

    while (n > 0) {
        if (pos % 2 == 0 && (n & 1) == 1) cnt++;
        n >>= 1;
        pos++;
    }
    return cnt;
}

int main() {
    long long n;
    std::cout << "Введите число: ";
    std::cin >> n;
    std::cout << "Количество ненулевых разрядов, стоящих на чётных местах в двоичной записи числа " << n << ": " << zero_digits_count(n) << std::endl;
}