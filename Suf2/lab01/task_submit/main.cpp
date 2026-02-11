#include <iostream>
#include <vector>
#include <string>
#include "Employee.h"

int main() {
    std::vector<Employee> vector_employee;
    int choice;

    do {
        std::cout << "\n=== МЕНЮ ===\n"
                  << "1 - Ввести одного сотрудника\n"
                  << "2 - Ввести список сотрудников\n"
                  << "3 - Вывести всех сотрудников\n"
                  << "4 - Поиск по ФИО\n"
                  << "5 - Вывести сотрудников - мужчин \n"
                  << "6 - Вывести самого старого сотрудника - мужчину \n"
                  << "7 - Вывести сотрудников - мужчин - пенсионеров \n"
                  << "8 - Запись в файл\n"
                  << "9 - Чтение из файла\n"
                  << "10 - Запись в бинарный файл\n"
                  << "11 - Чтение из бинарного файла\n"
                  << "0 - Выход\n"
                  << "Ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                static unsigned int next_id = 1;
                Employee employee = input_employee(next_id++);
                vector_employee.push_back(employee);
                std::cout << "Сотрудник добавлен.\n";
                print_employee(employee);
                break;
            }

            case 2: {
                input_employee(vector_employee);
                std::cout << "Сотрудники добавлены.\n";
                break;
            }

            case 3: {
                if (vector_employee.empty()) {
                    std::cout << "Список сотрудников пуст.\n";
                } else {
                    print_employee(vector_employee);
                }
                break;
            }

            case 4: {
                std::cout << "Введите запрос для поиска по ФИО: ";
                std::string query;
                std::cin >> query;
                std::vector<Employee> result = search_by_NSP(vector_employee, query);
                if (result.empty()) {
                    std::cout << "Ничего не найдено.\n";
                } else {
                    std::cout << "Найдено " << result.size() << " сотрудник(ов):\n";
                    print_employee(result);
                }
                break;
            }

            case 5: {
                if (get_males(vector_employee).empty()) std::cout << "Сотрудников-мужчин нет.";
                else {
                    std::vector<Employee> result = get_males(vector_employee);
                    std::cout << "Найдено " << result.size() << " сотрудник(ов):\n";
                    print_employee(result);
                }
                break;
            }

            case 6: {
                if (get_oldest(vector_employee) == nullptr) std::cout << "Сотрудников-мужчин нет.";
                else {
                    print_employee(*get_oldest(vector_employee));
                }
                break;
            }

            case 7: {
                if (get_male_pensioners(vector_employee).empty()) std::cout << "Сотрудников-мужчин-пенсионеров нет.";
                else {
                    std::vector<Employee> result = get_male_pensioners(vector_employee);
                    std::cout << "Найдено " << result.size() << " сотрудник(ов):\n";
                    print_employee(result);
                }
                break;
            }

            case 8: {
                write_to_text(vector_employee);
                break;
            }

            case 9: {
                read_from_text(vector_employee);
                break;
            }

            case 10: {
                write_to_binary(vector_employee);
                break;
            }

            case 11: {
                read_from_binary(vector_employee);
                break;
            }

            case 12: {
                std::cout << "Введите ID: ";
                unsigned int id;
                std::cin >> id;
                Employee* emp = find_by_id(vector_employee, id);
                if (emp) {
                    print_employee(*emp);
                } else {
                    std::cout << "Сотрудник с ID " << id << " не найден.\n";
                }
                break;
            }

            case 0: {
                std::cout << "Выход из программы.\n";
                break;
            }

            default: {
                std::cout << "Неверный выбор. Попробуйте снова.\n";
                break;
            }
        }
    } while (choice != 0);

    return 0;
}