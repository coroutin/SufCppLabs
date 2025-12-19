#include <iostream>
#include "array.h"

using namespace std;

void print_condition_menu() {
    cout << "\nВыберите условие:\n";
    cout << "1. Положительный элемент\n";
    cout << "2. Отрицательный элемент\n";
    cout << "3. Чётный элемент\n";
    cout << "4. Нечётный элемент\n";
    cout << "5. Сумма цифр >= 5\n";
    cout << "Ваш выбор: ";
}

condition choose_condition() {
    int choice;
    bool valid = false;

    while (!valid) {
        print_condition_menu();

        if (cin >> choice) {
            if (choice >= 1 && choice <= 5) {
                valid = true;
            } else {
                cout << "Неверный выбор! Введите число от 1 до 5.\n";
            }
        } else {
            cout << "Ошибка ввода! Введите целое число от 1 до 5.\n";
            cin.clear();
        }

        cin.ignore(10000, '\n');
    }

    switch (choice) {
        case 1: return is_positive;
        case 2: return is_negative;
        case 3: return is_even;
        case 4: return is_odd;
        case 5: return sum_digits_at_least_5;
        default: return nullptr; // Не достигается из-за проверки выше
    }
}

void input_array(int*& arr, int& size) {
    delete[] arr;
    arr = nullptr;

    cout << "Введите размер массива: ";
    while (!(cin >> size) || size < 1 || size > 100) {
        cout << "Неверный размер массива (должен быть от 1 до 100).\n";
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Введите размер массива заново: ";
    }

    arr = new int[size];

    cout << "Введите " << size << " целых чисел:\n";

    for (int i = 0; i < size; i++) {
        while (!(cin >> arr[i])) {
            cout << "Ошибка ввода! Введите целое число для элемента " << i << ": ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }

    // Очищаем буфер после успешного ввода всех элементов
    cin.ignore(10000, '\n');
}

void print_array(const int* arr, int size) {
    if (size == 0) {
        cout << "Массив пуст.\n";
        return;
    }
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int find_element(const int* arr, int size, int value) {
    for (int i = 0; i < size; i++)
        if (arr[i] == value)
            return i;
    return -1;
}

int count_element(const int* arr, int size, int value) {
    int count = 0;
    for (int i = 0; i < size; i++)
        if (arr[i] == value)
            count++;
    return count;
}

int find_by_condition(const int* arr, int size, condition cond) {
    for (int i = 0; i < size; i++)
        if (cond(arr[i]))
            return i;
    return -1;
}

int count_by_condition(const int* arr, int size, condition cond) {
    int count = 0;
    for (int i = 0; i < size; i++)
        if (cond(arr[i]))
            count++;
    return count;
}

// 7. Поиск индекса максимального / минимального элемента
int find_max_index(const int* arr, int size) {
    if (size <= 0) return -1;
    int max_idx = 0;
    for (int i = 1; i < size; ++i) {
        if (arr[i] > arr[max_idx]) {
            max_idx = i;
        }
    }
    return max_idx;
}

int find_min_index(const int* arr, int size) {
    if (size <= 0) return -1;
    int min_idx = 0;
    for (int i = 1; i < size; ++i) {
        if (arr[i] < arr[min_idx]) {
            min_idx = i;
        }
    }
    return min_idx;
}

int find_max_by_condition(const int* arr, int size, condition cond) {
    if (size <= 0 || cond == nullptr) return -1;
    int max_idx = -1;
    for (int i = 0; i < size; ++i) {
        if (cond(arr[i])) {
            if (max_idx == -1 || arr[i] > arr[max_idx]) {
                max_idx = i;
            }
        }
    }
    return max_idx;
}

int find_min_by_condition(const int* arr, int size, condition cond) {
    if (size <= 0 || cond == nullptr) return -1;
    int min_idx = -1;
    for (int i = 0; i < size; ++i) {
        if (cond(arr[i])) {
            if (min_idx == -1 || arr[i] < arr[min_idx]) {
                min_idx = i;
            }
        }
    }
    return min_idx;
}

int* find_all_indices(const int* arr, int size, int value, int& out_size) {
    out_size = 0;
    int* temp = new int[size];
    for (int i = 0; i < size; ++i) {
        if (arr[i] == value) {
            temp[out_size++] = i;
        }
    }
    if (out_size == 0) {
        delete[] temp;
        return nullptr;
    }
    return temp;
}

int* filter_by_condition(const int* arr, int size, condition cond, int& out_size) {
    if (cond == nullptr) {
        out_size = 0;
        return nullptr;
    }
    out_size = 0;
    int* temp = new int[size];
    for (int i = 0; i < size; ++i) {
        if (cond(arr[i])) {
            temp[out_size++] = arr[i];
        }
    }
    if (out_size == 0) {
        delete[] temp;
        return nullptr;
    }
    return temp;
}

void remove_at(int*& arr, int& size, int index) {
    if (index < 0 || index >= size) return;
    for (int i = index; i < size - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    --size;
}

void insert_at(int*& arr, int& size, int index, int value) {
    if (index < 0 || index > size) return;
    int* new_arr = new int[size + 1];
    for (int i = 0; i < index; ++i) new_arr[i] = arr[i];
    new_arr[index] = value;
    for (int i = index; i < size; ++i) new_arr[i + 1] = arr[i];
    delete[] arr;
    arr = new_arr;
    ++size;
}

void remove_k(int*& arr, int& size, int index, int k) {
    if (index < 0 || k <= 0 || index + k > size) return;
    for (int i = index; i < size - k; ++i) {
        arr[i] = arr[i + k];
    }
    size -= k;
}

void fill_random(int*& arr, int& size) {
    delete[] arr;
    arr = nullptr;

    cout << "Введите размер массива: ";
    while (!(cin >> size) || size < 1 || size > 1000) {
        cout << "Размер должен быть от 1 до 1000: ";
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Введите размер массива заново: ";
    }

    int min_val, max_val;
    cout << "Минимальное значение: ";
    while (!(cin >> min_val)) {
        cout << "Ошибка ввода минимального значения: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    cout << "Максимальное значение: ";
    while (!(cin >> max_val)) {
        cout << "Ошибка ввода максимального значения: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    if (min_val > max_val) {
        std::swap(min_val, max_val);
        cout << "Минимальное и максимальное значения были поменяны местами.\n";
    }

    arr = new int[size];

    // Вихрь Мерсенна
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(min_val, max_val);

    for (int i = 0; i < size; ++i) {
        arr[i] = distrib(gen);
    }

    cout << "Массив успешно заполнен случайными числами в диапазоне ["
         << min_val << ", " << max_val << "].\n";
}

void remove_all_equal(int*& arr, int& size, int value) {
    int new_size = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] != value) {
            arr[new_size++] = arr[i];
        }
    }
    size = new_size;
}

void remove_by_condition(int*& arr, int& size, condition cond) {
    if (cond == nullptr) return;
    int new_size = 0;
    for (int i = 0; i < size; ++i) {
        if (!cond(arr[i])) {
            arr[new_size++] = arr[i];
        }
    }
    size = new_size;
}

void insert_k(int*& arr, int& size, int index, int k, int value) {
    if (index < 0 || index > size || k <= 0) return;
    int* new_arr = new int[size + k];
    for (int i = 0; i < index; ++i) new_arr[i] = arr[i];
    for (int i = 0; i < k; ++i) new_arr[index + i] = value;
    for (int i = index; i < size; ++i) new_arr[index + k + i - index] = arr[i];
    delete[] arr;
    arr = new_arr;
    size += k;
}