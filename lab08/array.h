#pragma once
#include <cmath>
#include <random>

typedef bool (*condition)(int);


// ===== СТАНДАРТНЫЕ ФУНКЦИИ ===== //

// 1 Чтение элементов массива с клавиатуры.
void input_array(int*& arr, int& size);

//2 Вывод элементов массива на экран.
void print_array(const int* arr, int size);

//3 Поиск заданного элемента.
int find_element(const int* arr, int size, int value);

//4 Поиск количества элементов, равных заданному.
int count_element(const int* arr, int size, int value);

//5 Поиск элемента, удовлетворяющего условию.
int find_by_condition(const int* arr, int size, condition cond);

//6 Поиск количества элементов, удовлетворяющих условию.
int count_by_condition(const int* arr, int size, condition cond);

// 7 Поиск номера максимального/минимального элемента в массиве.
int find_max_index(const int* arr, int size);
int find_min_index(const int* arr, int size);

// 8 Поиск номера минимального/максимального элемента в массиве, удовлетворяющего заданному условию.
int find_max_by_condition(const int* arr, int size, condition cond);
int find_min_by_condition(const int* arr, int size, condition cond);

// 9 Поиск всех вхождений заданного элемента.
int* find_all_indices(const int* arr, int size, int value, int& out_size);

// 10 Сформировать массив из элементов исходного, удовлетворяющих заданному условию.
int* filter_by_condition(const int* arr, int size, condition cond, int& out_size);

// 11 Удаление элемента с заданным индексом.
void remove_at(int*& arr, int& size, int index);

// 12 Вставка нового элемента на заданное место.
void insert_at(int*& arr, int& size, int index, int value);

// 13 Удаление из массива K элементов, начиная с заданного индекса.
void remove_k(int*& arr, int& size, int index, int k);

// 14 Заполнение массива из случайных чисел.
void fill_random(int*& arr, int& size);

// 15 Удаление всех элементов, равных заданному.
void remove_all_equal(int*& arr, int& size, int value);

// 16 Удаление элементов массива, удовлетворяющих заданному условию.
void remove_by_condition(int*& arr, int& size, condition cond);

// 17 Вставка в массив K элементов, начиная с заданного номера.
void insert_k(int*& arr, int& size, int index, int k, int value = 0);

// Вывод меню выбора условия
void print_condition_menu();

// Выбор условия
condition choose_condition();


// ===== УСЛОВИЯ ===== //
inline bool is_positive(int x) { return x > 0; }

inline bool is_negative(int x) { return x < 0; }

inline bool is_odd(int x) { return x % 2 != 0; }

inline bool is_even(int x) { return x % 2 == 0; }

inline bool sum_digits_at_least_5(int x) {
    x = std::abs(x);
    int sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum >= 5;
}