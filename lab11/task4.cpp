#include <fstream>
#include <string>

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