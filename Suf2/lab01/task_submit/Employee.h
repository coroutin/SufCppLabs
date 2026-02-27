#pragma once

#include <iostream>
#include <string>


//===========
//  СТРУКТУРЫ
//===========

//ФИО сотрудника

struct Fullname {
    std::string surname;
    std::string name;
    std::string patronymic;
};

std::ostream& operator<<(std::ostream& out, const Fullname& fullname);

// Сотрудник

struct Employee {
    unsigned int id;
    Fullname fullname;
    unsigned int age;
    std::string passport;
    std::string phone;
    std::string gender;
};

//Массив сотрудников

struct EmployeeArray {
    Employee* data = nullptr;
    size_t size = 0;
    
    ~EmployeeArray() { clear(); }

    void clear() {
        delete[] data;
        data = nullptr;
        size = 0;
    }
};


//==================
//  ПСЕВДОНИМЫ ТИПОВ
//==================

using Condition = bool(*)(const Employee&);
using Comparator = bool(*)(const Employee&, const Employee&);


//==============
//  ГЕНЕРАТОР ID
//==============

unsigned int get_next_id();


//=================
//  ВАЛИДАЦИЯ ПОЛЕЙ
//=================

bool is_valid_phone(const std::string& phone);
bool is_valid_passport(const std::string& passport);
inline bool is_valid_gender(const std::string& gender) {
    return gender == "М" || gender == "Ж";
}


//========================
//  ВВОД ПОЛЕЙ С ПРОВЕРКОЙ
//========================

std::string input_phone();
std::string input_passport();
std::string input_gender();


//=====================================
//  ОПЕРАТОРЫ И ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ
//=====================================

std::ostream& operator<<(std::ostream& out, const Employee& employee);
std::istream& operator>>(std::istream& in,  Employee& employee);

void print_employee(const Employee& employee);
Employee input_employee(unsigned int id);