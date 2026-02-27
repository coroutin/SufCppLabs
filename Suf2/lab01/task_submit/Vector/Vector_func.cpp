#include "Vector_func.h"
#include "../Employees_predicates.h"
#include <iostream>
#include <limits>

//==============
//  ВВОД / ВЫВОД
//==============

void input_employees(std::vector<Employee>& employees) {
    int n;
    std::cout << "Количество сотрудников для добавления: ";
    std::cin >> n;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i = 0; i < n; ++i) {
        std::cout << "\nСотрудник №" << (i + 1) << "\n";
        employees.push_back(input_employee(get_next_id()));
    }
}

void print_employees(const std::vector<Employee>& employees) {
    for (const auto& e : employees) {
        print_employee(e);
    }
}

//=======
//  ПОИСК
//=======

/**
 * Спец. поиск
 * @param employees Вектор сотрудников
 * @param query Подстрока с частью ФИО
 * @return Вектор сотрудников, содержащих подстроку в ФИО
 */
std::vector<Employee> search_by_NSP(const std::vector<Employee>& employees,
                                    const std::string& query)
{
    std::vector<Employee> result;
    for (const auto& e : employees) {
        if (contains(e.fullname.surname, query) ||
            contains(e.fullname.name, query) ||
            contains(e.fullname.patronymic, query))
        {
            result.push_back(e);
        }
    }
    return result;
}

std::vector<Employee> get_males(const std::vector<Employee>& employees) {
    std::vector<Employee> result;
    for (const auto& e : employees) {
        if (is_male(e)) result.push_back(e);
    }
    return result;
}

std::vector<Employee> get_male_pensioners(const std::vector<Employee>& employees) {
    std::vector<Employee> result;
    for (const auto& e : employees) {
        if (is_male_pensioner(e)) result.push_back(e);
    }
    return result;
}

size_t get_oldest_male(const std::vector<Employee>& employees,
                       bool(*comparator)(const Employee&, const Employee&)) {
    size_t best = 0;
    for (size_t i = 1; i < employees.size(); ++i) {
        if (comparator(employees[i], employees[best])) {
            best = i;
        }
    }
    return best;
}


//  Вспомогательные функции для бинарного файла
static void write_str(std::ofstream& file, const std::string& s) {
    size_t len = s.size();
    file.write(reinterpret_cast<const char*>(&len), sizeof(len));
    file.write(s.c_str(), len);
}

static std::string read_str(std::ifstream& file) {
    size_t len = 0;
    file.read(reinterpret_cast<char*>(&len), sizeof(len));
    std::string s(len, '\0');
    file.read(&s[0], len);
    return s;
}

//=====================
//  ФАЙЛОВЫЙ ВВОД/ВЫВОД
//=====================

void write_to_txt(const std::vector<Employee>& employees) {
    std::ofstream file("employees.txt");

    file << employees.size() << "\n";
    for (const auto& e : employees) {
        file << e.id << "\n" << e.fullname.surname << "\n" << e.fullname.name << "\n" << e.fullname.patronymic << "\n"
             << e.age << "\n" << e.passport << "\n" << e.phone << "\n" << e.gender << "\n";
    }
    std::cout << "Данные записаны в employees.txt\n";
}

void read_from_txt(std::vector<Employee>& employees) {
    std::ifstream file("employees.txt");

    size_t count = 0;
    file >> count;
    employees.clear();

    for (size_t i = 0; i < count; ++i) {
        Employee e;
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
        employees.push_back(e);
    }
    std::cout << "Загружено " << employees.size() << " сотрудников из employees.txt\n";
}

void write_to_binary(const std::vector<Employee>& employees) {
    std::ofstream file("employees.bin", std::ios::binary);

    size_t count = employees.size();
    file.write(reinterpret_cast<const char*>(&count), sizeof(count));
    for (const auto& e : employees) {
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

void read_from_binary(std::vector<Employee>& employees) {
    std::ifstream file("employees.bin", std::ios::binary);

    size_t count = 0;
    file.read(reinterpret_cast<char*>(&count), sizeof(count));
    employees.clear();

    for (size_t i = 0; i < count; ++i) {
        Employee e;
        file.read(reinterpret_cast<char*>(&e.id),  sizeof(e.id));
        file.read(reinterpret_cast<char*>(&e.age), sizeof(e.age));
        e.fullname.surname    = read_str(file);
        e.fullname.name       = read_str(file);
        e.fullname.patronymic = read_str(file);
        e.passport = read_str(file);
        e.phone    = read_str(file);
        e.gender   = read_str(file);
        employees.push_back(e);
    }
    std::cout << "Загружено " << employees.size() << " сотрудников из employees.bin\n";
}