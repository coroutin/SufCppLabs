#include <iostream>

void init_console(int* array, int size) {
    for (int i = 0; i < size; i++) {
        std::cin >> array[i];
    }
}

int* init_console(int size) {
    int* array = new int[size];

    for (int i = 0; i < size; i++) {
        std::cin >> array[i];
    }

    return array;
}

void print_console(int* array, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}