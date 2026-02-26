#include "Array_func.h"
#include <iostream>
#include <fstream>
#include "../Employees_predicates.h"


//==============
//  ВВОД / ВЫВОД
//==============

void input_employees(Employee* employees, const size_t size) {
    for (size_t i = 0; i < size; ++i) {
        std::cout << "\nСотрудник №" << (i + 1) << "\n";
        employees[i] = input_employee(get_next_id());
    }
}

void print_employees(const Employee* employees, const size_t size) {
    for (size_t i = 0; i < size; ++i) {
        std::cout << "-----------------\n";
        std::cout << employees[i];
    }
}


//=======
//  ПОИСК
//=======

int find_element(const Employee* employees, size_t size, Condition condition) {
    for (size_t i = 0; i < size; ++i)
        if (condition(employees[i])) return static_cast<int>(i);
    return -1;
}

EmployeeArray find_all_elements(const Employee* employees, size_t size, Condition condition) {
    EmployeeArray result;
    for (size_t i = 0; i < size; ++i)
        if (condition(employees[i])) ++result.size;
    if (result.size == 0) return result;
    result.data = new Employee[result.size];
    size_t idx = 0;
    for (size_t i = 0; i < size; ++i)
        if (condition(employees[i])) result.data[idx++] = employees[i];
    return result;
}

size_t needful_element(const Employee* employees, size_t size, Comparator comparator) {
    size_t best = 0;
    for (size_t i = 1; i < size; ++i)
        if (comparator(employees[i], employees[best])) best = i;
    return best;
}

void get_males(const Employee* employees, size_t size) {
    EmployeeArray males = find_all_elements(employees, size, is_male);

    if (males.data == nullptr || males.size == 0) {
        std::cout << "Сотрудников мужкого пола нет.\n";
        return;
    }

        std::cout << "Сотрудников-мужчин: " << males.size << "\n";
        print_employees(males.data, males.size);
}

void get_male_pensioners(const Employee* employees, size_t size) {
    EmployeeArray pensioners = find_all_elements(employees, size, is_male_pensioner);

    if (pensioners.data == nullptr || pensioners.size == 0) {
        std::cout << "Пенсионеров-мужчин нет.\n";
        return;
    }

    std::cout << "Найдено пенсионеров: " << pensioners.size << "\n";
    print_employees(pensioners.data, pensioners.size);
}

void get_oldest_males(const Employee* employees, size_t size) {
    EmployeeArray males = find_all_elements(employees, size, is_male);

    if (males.data == nullptr || males.size == 0) {
        std::cout << "Сотрудники мужского пола не найдены.\n";
        return;
    }

    size_t res_idx = needful_element(males.data, males.size, is_older_male);

    std::cout << "Самый старый мужчина:\n";
    print_employee(males.data[res_idx]);
}

/**
 * Спец. поиск
 * @param employees Массив сотрудников
 * @param size Размер массива сотрудников
 * @param query Подстрока с частью ФИО
 * @return Массив сотрудников, содержащих подстроку в ФИО
 */
EmployeeArray search_by_NSP(const Employee* employees, size_t size, const std::string& query) {
    EmployeeArray result;

    for (size_t i = 0; i < size; ++i) {
        if (employees[i].fullname.surname.find(query) != std::string::npos ||
            employees[i].fullname.name.find(query) != std::string::npos ||
            employees[i].fullname.patronymic.find(query) != std::string::npos)
        {
            ++result.size;
        }
    }

    if (result.size == 0) return result;

    result.data = new Employee[result.size];
    size_t idx = 0;
    for (size_t i = 0; i < size; ++i) {
        if (employees[i].fullname.surname.find(query) != std::string::npos ||
            employees[i].fullname.name.find(query) != std::string::npos ||
            employees[i].fullname.patronymic.find(query) != std::string::npos)
        {
            result.data[idx++] = employees[i];
        }
    }
    return result;
}


//====================================
//  ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ ДЛЯ ФАЙЛОВ
//====================================

static void write_str(std::ostream& out, const std::string& s) {
    size_t len = s.size();
    out.write(reinterpret_cast<const char*>(&len), sizeof(len));
    out.write(s.c_str(), len);
}

static std::string read_str(std::istream& in) {
    size_t len = 0;
    in.read(reinterpret_cast<char*>(&len), sizeof(len));
    std::string s(len, '\0');
    in.read(&s[0], len);
    return s;
}


//  ФАЙЛОВЫЙ ВВОД/ВЫВОД

void write_to_txt(const Employee* employees, size_t size) {
    std::ofstream file("employees.txt");

    file << size << "\n";
    for (size_t i = 0; i < size; ++i) {
        const Employee& e = employees[i];
        file << e.id << "\n" << e.fullname.surname << "\n" << e.fullname.name << "\n" << e.fullname.patronymic << "\n"
             << e.age << "\n" << e.passport   << "\n" << e.phone << "\n" << e.gender << "\n";
    }
    std::cout << "Данные записаны\n";
}

Employee* read_from_txt(size_t& size) {
    std::ifstream file("employees.txt");

    file >> size;
    Employee* employees = new Employee[size];

    for (size_t i = 0; i < size; ++i) {
        Employee& e = employees[i];
        file >> e.id;
        file.ignore();
        std::getline(file, e.fullname.surname);
        std::getline(file, e.fullname.name);
        std::getline(file, e.fullname.patronymic);
        file >> e.age;
        file.ignore();
        std::getline(file, e.passport);
        std::getline(file, e.phone);
        std::getline(file, e.gender);
    }
    std::cout << "Загружено " << size << " сотрудников из employees.txt\n";
    return employees;
}

void write_to_bin(const Employee* employees, size_t size) {
    std::ofstream file("employees.bin", std::ios::binary);

    file.write(reinterpret_cast<const char*>(&size), sizeof(size));
    for (size_t i = 0; i < size; ++i) {
        const Employee& e = employees[i];
        file.write(reinterpret_cast<const char*>(&e.id),  sizeof(e.id));
        file.write(reinterpret_cast<const char*>(&e.age), sizeof(e.age));
        write_str(file, e.fullname.surname);
        write_str(file, e.fullname.name);
        write_str(file, e.fullname.patronymic);
        write_str(file, e.passport);
        write_str(file, e.phone);
        write_str(file, e.gender);
    }
    std::cout << "Данные записаны в employees.bin\n";
}

Employee* read_from_bin(size_t& size) {
    std::ifstream file("employees.bin", std::ios::binary);

    file.read(reinterpret_cast<char*>(&size), sizeof(size));
    Employee* employees = new Employee[size];

    for (size_t i = 0; i < size; ++i) {
        Employee& e = employees[i];
        file.read(reinterpret_cast<char*>(&e.id),  sizeof(e.id));
        file.read(reinterpret_cast<char*>(&e.age), sizeof(e.age));
        e.fullname.surname = read_str(file);
        e.fullname.name = read_str(file);
        e.fullname.patronymic = read_str(file);
        e.passport = read_str(file);
        e.phone = read_str(file);
        e.gender = read_str(file);
    }
    std::cout << "Загружено " << size << " сотрудников из employees.bin\n";
    return employees;
}