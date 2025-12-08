#include <iostream>

int lesinke(int n, int last) {
    if (n == 0) return 1;

    int ways = 0;

    int max = (last < n + 1 ? last - 1 : n);

    for (int k = 1; k <= max; k++) {
        ways += lesinke(n - k, k);
    }

    return ways;
}

int main() {
    int n;
    std::cout << "Пожалуйста, будьте так добры, введите число от 1 до 100. 🌟🙏";
    std::cin >> n;
    while (n < 1 || n > 100) {std::cin >> n;}

    std::cout << R"(🎯 Ваше число: )" << n << R"(
    🪜🔚 Всего набралось )" << lesinke(n, n) << R"( вариантов.
    Больше — нельзя, математика не позволит.)";

    return 0;
}