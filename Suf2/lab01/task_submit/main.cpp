#include <iostream>
#include <vector>
#include <string>
#include <limits>

#include "../Employee/Employee.h"
#include "Employee/Employees_predicates.h"
#include "Vector/Vector_func.h"
#include "Array/Array_func.h"

enum class MainMenu {
    ARRAY = 1,
    VECTOR = 2,
    EXIT = 0
};

enum class SubMenu {
    ADD =1,
    ADD_MANY = 2,
    PRINT = 3,
    SEARCH = 4,
    MALES = 5,
    MALES_PENSIONERS = 6,
    OLDEST = 7,
    WRITE_TO_TXT = 8,
    READ_FROM_TXT = 9,
    WRITE_TO_BIN = 10,
    READ_FROM_BIN = 11,
    BACK = 0
};

using enum MainMenu;
using enum SubMenu;

static void run_array_menu() {
    Employee* employees = nullptr;
    size_t size = 0;

    employees = read_from_txt(size);

    SubMenu choice;

    do {
        std::cout << "\n=== МЕНЮ: C-Array ===\n"
                  << "1 - Добавить сотрудника\n"
                  << "2 - Добавить группу\n"
                  << "3 - Вывести всех\n"
                  << "4 - Поиск по ФИО\n"
                  << "5 - Вывести мужчин\n"
                  << "6 - Вывести мужчин-пенсионеров\n"
                  << "7 - Самый старший мужчина\n"
                  << "8 - Сохранить в TXT\n"
                  << "9 - Загрузить из TXT\n"
                  << "10 - Сохранить в BIN\n"
                  << "11 - Загрузить из BIN\n"
                  << "12 - Назад\n"
                  << "Ваш выбор: ";

        int input;
        std::cin >> input;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        choice = static_cast<SubMenu>(input);

        switch (choice) {
            case ADD: {
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
            case ADD_MANY: {
                std::cout << "Количество сотрудников: ";
                std::cin >> size;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                delete[] employees;
                employees = new Employee[size];
                input_employees(employees, size);
                break;
            }
            case PRINT: {
                if (!employees || size == 0) std::cout << "Список пуст\n";
                else print_employees(employees, size);
                break;
            }
            case SEARCH: {
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
            case MALES: {
                if (!employees) { std::cout << "Список пуст\n"; break; }
                get_males(employees, size);
                break;
            }
            case MALES_PENSIONERS: {
                if (!employees) { std::cout << "Список пуст\n"; break; }
                get_male_pensioners(employees, size);
                break;
            }
            case OLDEST: {
                if (!employees) { std::cout << "Список пуст\n"; break; }
                get_oldest_males(employees, size);
                break;
            }
            case WRITE_TO_TXT: {
                if (!employees) { std::cout << "Список пуст\n"; break; }
                write_to_txt(employees, size);
                break;
            }
            case READ_FROM_TXT: {
                delete[] employees;
                employees = read_from_txt(size);
                break;
            }
            case WRITE_TO_BIN: {
                if (!employees) { std::cout << "Список пуст\n"; break; }
                write_to_bin(employees, size);
                break;
            }
            case READ_FROM_BIN: {
                delete[] employees;
                employees = read_from_bin(size);
                break;
            }
            case BACK: break;

            default: std::cout << "Неверный выбор\n";
        }
    }
    while (choice != BACK);

    delete[] employees;
}

static void run_vector_menu() {
    std::vector<Employee> employees;
    SubMenu choice;

    read_from_txt(employees);

    do {
        std::cout << "\n=== МЕНЮ: std::vector ===\n"
                  << "1 - Добавить сотрудника\n"
                  << "2 - Добавить группу\n"
                  << "3 - Вывести всех\n"
                  << "4 - Поиск по ФИО\n"
                  << "5 - Вывести мужчин\n"
                  << "6 - Вывести мужчин-пенсионеров\n"
                  << "7 - Самый старший мужчина\n"
                  << "8 - Сохранить в TXT\n"
                  << "9 - Загрузить из TXT\n"
                  << "10 - Сохранить в BIN\n"
                  << "11 - Загрузить из BIN\n"
                  << "12 - Назад\n"
                  << "Ваш выбор: ";
        int inp;
        std::cin >> inp;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        choice = static_cast<SubMenu>(inp);

        switch (choice) {
            case ADD: {
                Employee e = input_employee(get_next_id());
                employees.push_back(e);
                std::cout << "Сотрудник добавлен\n";
                print_employee(e);
                break;
            }
            case ADD_MANY: {
                input_employees(employees);
                break;
            }
            case PRINT: {
                if (employees.empty()) std::cout << "Список пуст\n";
                else print_employees(employees);
                break;
            }
            case SEARCH: {
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
            case MALES: {
                auto males = get_males(employees);
                if (males.empty()) std::cout << "Сотрудников-мужчин нет\n";
                else {
                    std::cout << "Мужчин: " << males.size() << "\n";
                    print_employees(males);
                }
                break;
            }
            case OLDEST: {
                if (get_males(employees).empty())
                    std::cout << "Сотрудников-мужчин нет\n";
                else {
                    size_t idx = get_oldest_male(employees, is_older_male);
                    std::cout << "Самый старший мужчина:\n";
                    print_employee(employees[idx]);
                }
                break;
            }
            case MALES_PENSIONERS: {
                auto pensioners = get_male_pensioners(employees);
                if (pensioners.empty()) std::cout << "Мужчин-пенсионеров нет\n";
                else {
                    std::cout << "Найдено: " << pensioners.size() << "\n";
                    print_employees(pensioners);
                }
                break;
            }
            case WRITE_TO_TXT:  write_to_txt(employees);    break;
            case READ_FROM_TXT:  read_from_txt(employees);   break;
            case WRITE_TO_BIN: write_to_binary(employees);  break;
            case READ_FROM_BIN: read_from_binary(employees); break;
            case BACK: break;
            default: std::cout << "Неверный выбор\n";
        }
    }
    while (choice != BACK);
}

int main() {
    MainMenu choice;

    do {
        std::cout << "\n=== ГЛАВНОЕ МЕНЮ ===\n"
                  << "1 - C-массив\n"
                  << "2 - std::vector\n"
                  << "0 - Выход\n"
                  << "Ваш выбор: ";

        int inp;
        std::cin >> inp;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        choice = static_cast<MainMenu>(inp);

        switch (choice) {
            case ARRAY: run_array_menu();  break;
            case VECTOR: run_vector_menu(); break;
            case EXIT: std::cout << "Выход\n"; break;
            default: std::cout << "Неверный выбор\n";
        }
    } while (choice != EXIT);

    return 0;
}