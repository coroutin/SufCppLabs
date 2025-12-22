#include <iostream>
#include <fstream>

int main() {
    std::cout << "Программа: поиск максимальных элементов в каждой строке\n\n";

    std::ifstream fin("i_2.txt");

    int N, M;
    if (!(fin >> N >> M) || N < 1 || M < 1) {
        std::cout << "Не удалось считать размеры.\n\n";
        return 0;
    }

    std::cout << "Размер: " << N << " x " << M << "\n\n";
    std::cout << "Содержимое:\n";

    std::ofstream fout("o_2.txt");

    for (int i = 0; i < N; ++i) {
        int max_val;
        if (!(fin >> max_val)) {
            std::cout << "\nНедостаточно элементов в файле.\n\n";
            return 0;
        }

        std::cout << max_val << " ";
        for (int j = 1; j < M; ++j) {
            int x;
            if (!(fin >> x)) {
                std::cout << "\nНедостаточно элементов в файле.\n\n";
                return 0;
            }
            std::cout << x << " ";
            if (x > max_val) {
                max_val = x;
            }
        }

        fout << max_val;
        if (i != N - 1) {
            fout << " ";
        }

        std::cout << "\n";
    }

    std::cout << "\nМаксимальные элементы каждой строки записаны в файл 0_2.txt.\n";
    return 0;
}
