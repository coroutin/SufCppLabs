#pragma once

#include "../Employee.h"
#include <fstream>


//==============
//  ВВОД / ВЫВОД
//==============

void input_employees(Employee* employees, size_t size);

void print_employees(const Employee* employees, size_t size);


//=======
//  ПОИСК
//=======

int find_element(const Employee* employees,
                 size_t          size,
                 Condition       condition);

EmployeeArray find_all_elements(const Employee* employees,
                                size_t          size,
                                Condition       condition);

size_t needful_element(const Employee* employees,
                       size_t          size,
                       Comparator      comparator);

void get_males(const Employee* employees, size_t size);

void get_male_pensioners(const Employee* employees, size_t size);

void get_oldest_males(const Employee* employees, size_t size);

// Спец. поиск
EmployeeArray search_by_NSP(const Employee* employees,
                            size_t          size,
                            const std::string& query);


//=====================
//  ФАЙЛОВЫЙ ВВОД/ВЫВОД
//=====================

void write_to_txt(const Employee* employees, size_t size);
void write_to_bin(const Employee* employees, size_t size);

Employee* read_from_txt(size_t& size);
Employee* read_from_bin(size_t& size);