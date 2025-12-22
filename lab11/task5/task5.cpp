#include <iostream>
#include <fstream>
#include <string>

bool check_file_data(const std::string& filename, int& row, int& col) {
    std::ifstream fin(filename);

    if (!(fin >> row >> col)) return false;
    if (row <= 0 || col <= 0) return false;

    int required = row * col;
    int count = 0;
    int temp;

    while (fin >> temp) {
        ++count;
    }

    return count >= required;
}


template<typename T>
T** init_file(std::string filename, int& row, int& col) {
    std::ifstream fin(filename);

    fin >> row >> col;

    T** array = new T*[row];
    for (int i = 0; i < row; ++i) {
        array[i] = new T[col];
        for (int j = 0; j < col; ++j) {
            fin >> array[i][j];
        }
    }

    return array;
}

template<typename T>
void print_file(std::string filename, T** array, int row, int col) {
    std::ofstream fout(filename);

    fout << row << " " << col << '\n';

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            fout << array[i][j];
            if (j + 1 < col) {
                fout << " ";
            }
        }
        if (i + 1 < row) {
            fout << '\n';
        }
    }
}

int main() {
    std::cout << "Программа: работа с двумерным массивом из файла\n\n";

    int row = 0, col = 0;

    if (!check_file_data("i_5.txt", row, col)) {
        std::cout << "Файл содержит некорректные данные.\n";
        std::cout << "Проверьте размеры массива и количество элементов.\n\n";
        return 0;
    }

    int** array = init_file<int>("i_5.txt", row, col);

    std::cout << "Размер массива: " << row << " x " << col << "\n\n";

    std::cout << "Содержимое массива:\n";
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            std::cout << array[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";

    print_file<int>("o_5.txt", array, row, col);

    std::cout << "Массив записан в файл o_5.txt.\n\n";

    for (int i = 0; i < row; ++i) {
        delete[] array[i];
    }
    delete[] array;
    return 0;
}