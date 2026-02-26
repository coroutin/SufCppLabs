#include "Employee.h"
#include <cctype>
#include <limits>


//==============
//  ГЕНЕРАТОР ID
//==============

static unsigned int next_id = 1;

unsigned int get_next_id() { return next_id++; }


//===========
//  ВАЛИДАЦИИ
//===========

bool is_valid_phone(const std::string& phone) {
    if (phone.length() == 11) {
        for (char c : phone)
            if (!std::isdigit(c)) return false;
        return true;
    }
    if (phone.length() == 12 && phone[0] == '+') {
        for (size_t i = 1; i < phone.length(); ++i)
            if (!std::isdigit(phone[i])) return false;
        return true;
    }
    return false;
}

bool is_valid_passport(const std::string& passport) {
    if (passport.length() != 11) return false;
    for (int i = 0; i < 4; ++i)
        if (!std::isdigit(passport[i])) return false;
    if (passport[4] != ' ') return false;
    for (int i = 5; i < 11; ++i)
        if (!std::isdigit(passport[i])) return false;
    return true;
}


//==================
//  ВВОД С ПРОВЕРКОЙ
//==================

std::string input_phone() {
    std::string phone;
    std::cout << "Телефон (+XXXXXXXXXXX или XXXXXXXXXXX): ";
    std::getline(std::cin, phone);
    while (!is_valid_phone(phone)) {
        std::cout << "Неверный формат. Попробуйте снова: ";
        std::getline(std::cin, phone);
    }
    return phone;
}

std::string input_passport() {
    std::string passport;
    std::cout << "Паспорт (XXXX YYYYYY): ";
    std::getline(std::cin, passport);
    while (!is_valid_passport(passport)) {
        std::cout << "Неверный формат. Попробуйте снова: ";
        std::getline(std::cin, passport);
    }
    return passport;
}

std::string input_gender() {
    std::string gender;
    bool valid = false;
    std::cout << "Пол (М/Ж): ";
    std::getline(std::cin, gender);
    while (!valid) {
        if (is_valid_gender(gender)) {
            valid = true;
        }
        else {
            std::cout << "Пол должен быть М или Ж\n";
            std::cout << "Пол (М/Ж): ";
            std::getline(std::cin, gender);
        }
    }
    return gender;
}


//==================
//  ОПЕРАТОРЫ ВЫВОДА
//==================

std::ostream& operator<<(std::ostream& out, const Fullname& f) {
    out << f.surname << " " << f.name << " " << f.patronymic;
    return out;
}

std::ostream& operator<<(std::ostream& out, const Employee& e) {
    out << "ФИО: " << e.fullname << "\n"
        << "Возраст: " << e.age << "\n"
        << "Паспорт: " << e.passport << "\n"
        << "Телефон: " << e.phone << "\n"
        << "Пол: " << e.gender << "\n";
    return out;
}


//================
//  ОПЕРАТОР ВВОДА
//================

std::istream& operator>>(std::istream& in, Employee& e) {
    std::cout << "Фамилия: "; std::getline(in, e.fullname.surname);
    std::cout << "Имя: "; std::getline(in, e.fullname.name);
    std::cout << "Отчество: "; std::getline(in, e.fullname.patronymic);
    std::cout << "Возраст: "; in >> e.age;
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    e.passport = input_passport();
    e.phone = input_phone();
    e.gender = input_gender();
    return in;
}


//=========================
//  ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ
//=========================

void print_employee(const Employee& e) {
    std::cout << "--------------------\n" << e;
}


Employee input_employee(unsigned int id) {
    Employee e;
    e.id = id;
    std::cin >> e;
    return e;
}