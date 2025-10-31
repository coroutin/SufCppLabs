#include <iostream>

int main() {
    long long n, sum = 0;
    std::cin >> n;//Получаем число от пользователя
    for (int i = 1; i < n; i ++) {
        if (n % i == 0) {sum += i;}//Проверяем что i – делитель числа n
    }
    if (sum == n) {std::cout << sum << std::endl; std::cout << "YES";}//Проверяем, что сумма делителей числа равна числу
    else if (n == 1) {std::cout << 1 << std::endl; std::cout << "NO";}//Проверка особого случяя, когла число равно единице
    else {std::cout << sum << std::endl; std::cout << "NO";}//Иначе вывводим сумму делителей числа, и то что оно является несоверщенным

    return 0;
}