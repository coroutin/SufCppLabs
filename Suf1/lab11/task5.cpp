#include <fstream>
#include <string>

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