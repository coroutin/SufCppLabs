#include <iostream>
#include <fstream>

int main() {
    std::cout << "Программа: вывод положительных чисел из файла\n\n";

    std::ifstream fin("i_1.txt");

    int N;
    if (!(fin >> N)) {
        std::cout << "Не удалось считать количество чисел.\n";
        return 0;
    }

    if (N <= 0) {
        std::cout << "Количество чисел должно быть положительным.\n";
        return 0;
    }

    int* numbers = new int[N];
    int count = 0;
    int x;
    while (count < N && fin >> x) {
        numbers[count++] = x;
    }
    fin.close();

    if (count < N) {
        std::cout << "В файле меньше " << N << " чисел.\n";
        delete[] numbers;
        return 0;
    }

    std::cout << "Количество чисел: " << N << "\n";
    std::cout << "Содержимое файла:\n";
    for (int i = 0; i < N; ++i) {
        std::cout << numbers[i] << (i + 1 < N ? " " : "\n");
    }

    std::cout << "\nРезультат: ";
    bool found = false;
    for (int i = 0; i < N; ++i) {
        if (numbers[i] > 0) {
            if (found) std::cout << " ";
            std::cout << numbers[i];
            found = true;
        }
    }

    if (!found) {
        std::cout << "NO";
    }
    std::cout << "\n";

    delete[] numbers;
    return 0;
}
