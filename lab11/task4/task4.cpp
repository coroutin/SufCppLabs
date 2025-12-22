#include <iostream>
#include <fstream>
#include <string>

bool check_file_data(const std::string& filename, int& size) {
    std::ifstream fin(filename);

    if (!(fin >> size)) return false;
    if (size <= 0) return false;

    int count = 0;
    int temp;
    while (fin >> temp) {
        ++count;
    }

    return count >= size;
}

template<typename T>
T* init_file(std::string filename, int &size) {
    std::ifstream fin(filename);

    fin >> size;
    T* array = new T[size];

    for (int i = 0; i < size; ++i) {
        fin >> array[i];
    }

    return array;
}

template<typename T>
void print_file(std::string filename, T* array, int size) {
    std::ofstream fout(filename);

    fout << size << '\n';
    for (int i = 0; i < size; ++i) {
        fout << array[i];
        if (i + 1 < size) {
            fout << " ";
        }
    }
}

int main() {
    std::cout << "Программа: работа с одномерным массивом из файла\n\n";

    int size = 0;

    if (!check_file_data("i_4.txt", size)) {
        std::cout << "Файл содержит некорректные данные.\n";
        std::cout << "Проверьте размер массива и количество элементов.\n\n";
        return 0;
    }

    int* array = init_file<int>("i_4.txt", size);

    std::cout << "Размер массива: " << size << "\n\n";

    std::cout << "Содержимое массива:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n\n";

    print_file<int>("o_4.txt", array, size);
    std::cout << "Массив записан в файл o_4.txt.\"\n\n";

    delete[] array;

    return 0;
}
