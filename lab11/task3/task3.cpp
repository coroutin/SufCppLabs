#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::cout << "Программа: подсчёт количества и суммы чисел из файла\n\n";

    std::ifstream fin("i_3.txt");

    long long sum = 0;
    int count = 0;
    int x;
    bool empty = true;

    if (fin >> x) {empty = false;}

    if (empty) {
        std::cout << "Файл не содержит целых чисел.\n";
        std::cout << "Результат не будет записан.\n\n";
        return 0;
    }

    std::cout << "Содержимое файла:";

    bool first = true;
    while (fin >> x) {
        if (!first) std::cout << " ";
        std::cout << x;
        first = false;

        sum += x;
        ++count;
    }
    std::cout << "\n\n";

    std::ofstream fout("o_3.txt");

    fout << "count = " << count << '\n';
    fout << "sum = " << sum << '\n';

    std::cout << "Количество чисел: " << count << "\n";
    std::cout << "Сумма чисел: " << sum << "\n\n";

    std::cout << "Результат записан в файл o_3.txt.\n";

    return 0;
}

