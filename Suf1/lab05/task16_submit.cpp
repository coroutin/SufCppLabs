#include <iostream>

template <typename T> // Шаблон

// Убогий аналог swap()
void exchange(T &x, T &y) {
    T temp = x;
    x = y;
    y = temp;
}

void vivo(int &choose) {
    std::cout << R"(Выберите какой тип данный вы хотите ввести🤩:
1 – целочисленное число🔢
2 – число с плавающей точкой🥲
3 – строка🈳)";
    std::cout << std::endl;

    while (!(std::cin >> choose) || choose < 1 || choose > 3) {
        std::cout << "Неверный ввод🤬. Введите ещё раз💀: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
}

template <typename T>
void vivo2(T &a, T &b) {
    while (!(std::cin >> a >> b)) {
        std::cout << "Неверный ввод🤬. Введите ещё раз💀: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
}

int main() {
    int choose;

    vivo(choose);

    if (choose == 1) {
        long long a, b;
        std::cout << "Введите 2 целочисленных числа🔢: ";
        vivo2(a, b);
        exchange(a, b);

        std::cout << "Магия🪄: ";
        std::cout << a << ", " << b << '.' << std::endl;
    }

    if (choose == 2) {
        double a, b;
        std::cout << "Введите 2 числа с плавающей точкой🥲: ";
        vivo2(a, b);
        exchange(a, b);

        std::cout << "Магия🪄: ";
        std::cout << a << ", " << b << '.' << std::endl;
    }

    if (choose == 3) {
        std::string a, b;
        std::cout << "Введите 2 строки㊙️: ";
        vivo2(a, b);
        exchange(a, b);

        std::cout << "Магия🪄: ";
        std::cout << a << ", " << b << '.' << std::endl;
    }
}