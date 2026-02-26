#include <iostream>
#include <vector>
#include <string>
#include <limits>

#include "Employee.h"
#include "Vector/Vector_func.h"
#include "Array/Array_func.h"

static int read_choice() {
    int choice;
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return choice;
}

static void run_array_menu() {
    Employee* employees = nullptr;
    size_t size = 0;
    int choice;

    do {
        std::cout << "\n=== МЕНЮ: C-МАССИВ ===\n"
                  << "1  - Добавить сотрудника\n"
                  << "2  - Добавить сотрудников\n"
                  << "3  - Вывести всех сотрудников\n"
                  << "4  - Поиск по ФИО\n"
                  << "5  - Вывести мужчин\n"
                  << "6  - Вывести мужчин-пенсионеров\n"
                  << "7  - Самый старший мужчина\n"
                  << "8  - Записать в текстовый файл\n"
                  << "9  - Прочитать из текстового файла\n"
                  << "10 - Записать в бинарный файл\n"
                  << "11 - Прочитать из бинарного файла\n"
                  << "0  - Назад\n"
                  << "Ваш выбор: ";
        choice = read_choice();

        switch (choice) {
            case 1: {
                Employee* new_employees = new Employee[size + 1];

                for (size_t i = 0; i < size; ++i) {
                    new_employees[i] = employees[i];
                }

                new_employees[size] = input_employee(get_next_id());

                delete[] employees;
                employees = new_employees;
                size++;

                std::cout << "Сотрудник добавлен.\n";
                print_employee(employees[size - 1]);
                break;
            }
            case 2: {
                std::cout << "Количество сотрудников: ";
                std::cin >> size;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                delete[] employees;
                employees = new Employee[size];
                input_employees(employees, size);
                break;
            }
            case 3: {
                if (!employees || size == 0) std::cout << "Список пуст\n";
                else print_employees(employees, size);
                break;
            }
            case 4: {
                std::cout << "Запрос для поиска по ФИО: ";
                std::string query;
                std::getline(std::cin, query);
                EmployeeArray result = search_by_NSP(employees, size ,query);
                if (result.data == nullptr) std::cout << "Ничего не найдено";
                else {
                    std::cout << "Найдено: " << result.size << "\n";
                    print_employees(result.data, result.size);
                }
                break;
            }
            case 5: {
                if (!employees) { std::cout << "Список пуст\n"; break; }
                get_males(employees, size);
                break;
            }
            case 6: {
                if (!employees) { std::cout << "Список пуст\n"; break; }
                get_male_pensioners(employees, size);
                break;
            }
            case 7: {
                if (!employees) { std::cout << "Список пуст\n"; break; }
                get_oldest_males(employees, size);
                break;
            }
            case 8: {
                if (!employees) { std::cout << "Список пуст\n"; break; }
                write_to_txt(employees, size);
                break;
            }
            case 9: {
                delete[] employees;
                employees = read_from_txt(size);
                break;
            }
            case 10: {
                if (!employees) { std::cout << "Список пуст\n"; break; }
                write_to_bin(employees, size);
                break;
            }
            case 11: {
                delete[] employees;
                employees = read_from_bin(size);
                break;
            }
            case 0: break;
            default: std::cout << "Неверный выбор\n";
        }
    } while (choice != 0);

    delete[] employees;
}

static void run_vector_menu() {
    std::vector<Employee> employees;
    int choice;

    do {
        std::cout << "\n=== МЕНЮ: std::vector ===\n"
                  << "1  - Добавить сотрудника\n"
                  << "2  - Добавить сотрудников\n"
                  << "3  - Вывести всех сотрудников\n"
                  << "4  - Поиск по ФИО\n"
                  << "5  - Вывести мужчин\n"
                  << "6  - Самый старший мужчина\n"
                  << "7  - Вывести мужчин-пенсионеров\n"
                  << "8  - Записать в текстовый файл\n"
                  << "9  - Прочитать из текстового файла\n"
                  << "10 - Записать в бинарный файл\n"
                  << "11 - Прочитать из бинарного файла\n"
                  << "0  - Назад\n"
                  << "Ваш выбор: ";
        choice = read_choice();

        switch (choice) {
            case 1: {
                Employee e = input_employee(get_next_id());
                employees.push_back(e);
                std::cout << "Сотрудник добавлен\n";
                print_employee(e);
                break;
            }
            case 2: {
                input_employees(employees);
                break;
            }
            case 3: {
                if (employees.empty()) std::cout << "Список пуст\n";
                else print_employees(employees);
                break;
            }
            case 4: {
                std::cout << "Запрос для поиска по ФИО: ";
                std::string query;
                std::getline(std::cin, query);
                auto result = search_by_NSP(employees, query);
                if (result.empty()) std::cout << "Ничего не найдено.\n";
                else {
                    std::cout << "Найдено: " << result.size() << "\n";
                    print_employees(result);
                }
                break;
            }
            case 5: {
                auto males = get_males(employees);
                if (males.empty()) std::cout << "Сотрудников-мужчин нет\n";
                else {
                    std::cout << "Мужчин: " << males.size() << "\n";
                    print_employees(males);
                }
                break;
            }
            case 6: {
                if (get_males(employees).empty())
                    std::cout << "Сотрудников-мужчин нет\n";
                else {
                    size_t idx = get_oldest_male(employees, is_older_male);
                    std::cout << "Самый старший мужчина:\n";
                    print_employee(employees[idx]);
                }
                break;
            }
            case 7: {
                auto pensioners = get_male_pensioners(employees);
                if (pensioners.empty()) std::cout << "Мужчин-пенсионеров нет\n";
                else {
                    std::cout << "Найдено: " << pensioners.size() << "\n";
                    print_employees(pensioners);
                }
                break;
            }
            case 8:  write_to_text(employees);    break;
            case 9:  read_from_text(employees);   break;
            case 10: write_to_binary(employees);  break;
            case 11: read_from_binary(employees); break;
            case 0: break;
            default: std::cout << "Неверный выбор\n";
        }
    } while (choice != 0);
}

int main() {
    int choice;
    do {
        std::cout << "\n=== ГЛАВНОЕ МЕНЮ ===\n"
                  << "1 - C-массив\n"
                  << "2 - std::vector\n"
                  << "0 - Выход\n"
                  << "Ваш выбор: ";
        choice = read_choice();

        switch (choice) {
            case 1: run_array_menu();  break;
            case 2: run_vector_menu(); break;
            case 0: std::cout << "Выход\n"; break;
            default: std::cout << "Неверный выбор\n";
        }
    } while (choice != 0);

    return 0;
}