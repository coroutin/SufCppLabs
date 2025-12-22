#include <iostream>
#include "array.h"

using namespace std;

int main() {
    int* arr = nullptr;
    int size = 0;
    int choice;

    do {
        cout << "\n===== МЕНЮ =====\n";
        cout << "1. Чтение элементов массива с клавиатуры.\n";
        cout << "2. Вывод элементов массива на экран.\n";
        cout << "3. Поиск заданного элемента.\n";
        cout << "4. Поиск количества элементов, равных заданному.\n";
        cout << "5. Поиск элемента, удовлетворяющего условию.\n";
        cout << "6. Поиск количества элементов, удовлетворяющих условию.\n";
        cout << "7. Поиск номера максимального/минимального элемента в массиве.\n";
        cout << "8. Поиск номера минимального/максимального элемента в массиве, удовлетворяющего заданному условию.\n";
        cout << "9. Поиск всех вхождений заданного элемента.\n";
        cout << "10. Сформировать массив из элементов исходного, удовлетворяющих заданному условию.\n";
        cout << "11. Удаление элемента с заданным индексом.\n";
        cout << "12. Вставка нового элемента на заданное место.\n";
        cout << "13. Удаление из массива K элементов, начиная с заданного индекса.\n";
        cout << "14. Заполнение массива из случайных чисел.\n";
        cout << "15. Удаление всех элементов, равных заданному.\n";
        cout << "16. Удаление элементов массива, удовлетворяющих заданному условию.\n";
        cout << "17. Вставка в массив K элементов, начиная с заданного номера.\n";
        cout << "0. Выход\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        // Защита от операций с пустым массивом
        if (arr == nullptr && choice >= 2 && choice <= 18 && choice != 15 && choice != 14) {
            cout << "Ошибка: сначала создайте массив (пункт 1 или 15)!\n";
            continue;
        }

        switch (choice) {
            case 1:
                input_array(arr, size);
                print_array(arr, size);
                break;

            case 2:
                print_array(arr, size);
                break;

            case 3: {
                cout << "Введите искомый элемент: ";
                int value;
                cin >> value;
                int idx = find_element(arr, size, value);
                if (idx == -1) cout << "Элемент не найден.\n";
                else cout << "Первый индекс: " << idx << "\n";
                break;
            }

            case 4: {
                cout << "Введите элемент: ";
                int value;
                cin >> value;
                int cnt = count_element(arr, size, value);
                cout << "Количество вхождений: " << cnt << "\n";
                break;
            }

            case 5: {
                condition cond = choose_condition();
                int idx = find_by_condition(arr, size, cond);
                if (idx == -1) cout << "Элемент по условию не найден.\n";
                else cout << "Первый подходящий элемент: " << arr[idx] << " (индекс " << idx << ")\n";
                break;
            }

            case 6: {
                condition cond = choose_condition();
                int cnt = count_by_condition(arr, size, cond);
                cout << "Количество элементов по условию: " << cnt << "\n";
                break;
            }

            case 7: {
                int sub;
                bool valid = false;
                while (!valid) {
                    cout << "Что искать?\n";
                    cout << "1 — максимальный элемент\n";
                    cout << "2 — минимальный элемент\n";
                    cout << "Ваш выбор (1 или 2): ";
                    if (cin >> sub && (sub == 1 || sub == 2)) {
                        valid = true;
                    } else {
                        cout << "Ошибка: введите 1 или 2!\n";
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }
                }

                int idx = (sub == 1) ? find_max_index(arr, size) : find_min_index(arr, size);
                // find_max_index и find_min_index уже возвращают -1 при size <= 0, но мы защищены выше
                cout << (sub == 1 ? "Максимальный" : "Минимальный")
                     << " элемент: " << arr[idx] << " (индекс " << idx << ")\n";
                break;
            }

            case 8: {
                condition cond = choose_condition();

                int sub;
                bool valid = false;
                while (!valid) {
                    cout << "Что искать по условию?\n";
                    cout << "1 — максимальный элемент\n";
                    cout << "2 — минимальный элемент\n";
                    cout << "Ваш выбор (1 или 2): ";
                    if (cin >> sub && (sub == 1 || sub == 2)) {
                        valid = true;
                    } else {
                        cout << "Ошибка: введите 1 или 2!\n";
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }
                }

                int idx = (sub == 1) ? find_max_by_condition(arr, size, cond)
                                    : find_min_by_condition(arr, size, cond);

                if (idx == -1) {
                    cout << "Подходящих элементов не найдено.\n";
                } else {
                    cout << (sub == 1 ? "Максимальный" : "Минимальный")
                         << " элемент по условию: " << arr[idx]
                         << " (индекс " << idx << ")\n";
                }
                break;
            }

            case 9: {
                cout << "Введите элемент: ";
                int value;
                cin >> value;
                int out_size;
                int* indices = find_all_indices(arr, size, value, out_size);
                if (indices == nullptr) {
                    cout << "Элемент не найден.\n";
                }
                else {
                    cout << "Индексы: ";
                    for (int i = 0; i < out_size; ++i) {
                        cout << indices[i] << " ";
                    }
                    cout << "\n";
                    delete[] indices;
                }
                break;
            }

            case 10: {
                condition cond = choose_condition();
                int out_size;
                int* filtered = filter_by_condition(arr, size, cond, out_size);
                if (filtered == nullptr) {
                    cout << "Нет элементов, удовлетворяющих условию.\n";
                }
                else {
                    cout << "Новый массив (" << out_size << " элементов): ";
                    for (int i = 0; i < out_size; ++i) {
                        cout << filtered[i] << " ";
                    }
                    cout << "\n";
                    delete[] filtered;
                }
                break;
            }

            case 11: {
                if (size != 0) {
                    int idx;
                    bool valid = false;
                    while (!valid) {
                        cout << "Введите индекс для удаления (0.." << size - 1 << "): ";
                        if (cin >> idx && idx >= 0 && idx < size) {
                            valid = true;
                        } else {
                            cout << "Ошибка: индекс должен быть от 0 до " << size - 1 << "!\n";
                            cin.clear();
                            cin.ignore(10000, '\n');
                        }
                    }
                    remove_at(arr, size, idx);
                    cout << "Элемент по индексу " << idx << " удалён.\n";
                    print_array(arr, size);
                    break;
                }
                else {
                    std::cout << "Нельзя удалять элемент пустого массива!"; break;
                }
            }

            case 12: {
                int idx;
                bool valid = false;
                while (!valid) {
                    cout << "Введите индекс вставки (0.." << size << "): ";
                    if (cin >> idx && idx >= 0 && idx <= size) {
                        valid = true;
                    } else {
                        cout << "Ошибка: индекс должен быть от 0 до " << size << "!\n";
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }
                }

                cout << "Введите значение: ";
                int val;
                cin >> val;

                insert_at(arr, size, idx, val);
                cout << "Элемент " << val << " вставлен на позицию " << idx << ".\n";
                print_array(arr, size);
                break;
            }

            case 13: {
                if (size != 0) {
                    int idx, k;
                    bool valid_idx = false;
                    while (!valid_idx) {
                        cout << "Введите начальный индекс (0.." << size - 1 << "): ";
                        if (cin >> idx && idx >= 0 && idx < size) {
                            valid_idx = true;
                        } else {
                            cout << "Ошибка: индекс должен быть от 0 до " << size - 1 << "!\n";
                            cin.clear();
                            cin.ignore(10000, '\n');
                        }
                    }

                    bool valid_k = false;
                    while (!valid_k) {
                        cout << "Введите количество K (1.." << size - idx << "): ";
                        if (cin >> k && k > 0 && idx + k <= size) {
                            valid_k = true;
                        } else {
                            cout << "Ошибка: K должно быть от 1 до " << size - idx << "!\n";
                            cin.clear();
                            cin.ignore(10000, '\n');
                        }
                    }

                    remove_k(arr, size, idx, k);
                    cout << "Удалено " << k << " элементов начиная с индекса " << idx << ".\n";
                    print_array(arr, size);
                    break;
                }
                else {
                    std::cout << "Нельзя удалять элемент пустого массива!"; break;
                }
            }

            case 14:
                fill_random(arr, size);
                print_array(arr, size);
                break;

            case 15: {
                if (size != 0) {
                    cout << "Введите значение для удаления: ";
                    int value;
                    cin >> value;
                    remove_all_equal(arr, size, value);
                    cout << "Все вхождения " << value << " удалены.\n";
                    print_array(arr, size);
                    break;
                }
                else {
                    std::cout << "Нельзя удалять элемент пустого массива!"; break;
                }

            }

            case 16: {
                if (size != 0) {
                    condition cond = choose_condition();
                    remove_by_condition(arr, size, cond);
                    cout << "Элементы, удовлетворяющие условию, удалены.\n";
                    print_array(arr, size);
                    break;
                }
        else {
            std::cout << "Нельзя удалять элемент пустого массива!"; break;
        }
            }

            case 17: {  // Вставка K элементов
                int idx, k;
                bool valid_idx = false;
                while (!valid_idx) {
                    cout << "Введите индекс вставки (0.." << size << "): ";
                    if (cin >> idx && idx >= 0 && idx <= size) {
                        valid_idx = true;
                    } else {
                        cout << "Ошибка: индекс должен быть от 0 до " << size << "!\n";
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }
                }

                bool valid_k = false;
                while (!valid_k) {
                    cout << "Введите количество K (>=1): ";
                    if (cin >> k && k >= 1) {
                        valid_k = true;
                    } else {
                        cout << "Ошибка: количество должно быть положительным!\n";
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }
                }

                cout << "Введите значение (по умолчанию 0): ";
                int val = 0;
                string temp;
                getline(cin >> ws, temp);
                if (!temp.empty()) {
                    val = stoi(temp);
                }

                insert_k(arr, size, idx, k, val);
                cout << "Вставлено " << k << " элементов со значением " << val << " на позицию " << idx << ".\n";
                print_array(arr, size);
                break;
            }

            case 0:
                cout << "Выход из программы.\n";
                break;

            default:
                cout << "Неверный пункт меню!\n";
        }
    } while (choice != 0);

    delete[] arr; // Освобождение памяти перед завершением
    return 0;
}