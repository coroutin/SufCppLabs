#pragma once

#include "../Employee.h"
#include <vector>
#include <string>
#include <fstream>


//============
//  ВВОД/ВЫВОД
//============

void input_employees(std::vector<Employee>& employees);

void print_employees(const std::vector<Employee>& employees);


//=======
//  ПОИСК
//=======

std::vector<Employee> search_by_NSP(const std::vector<Employee>& employees,
                                    const std::string& query);

std::vector<Employee> get_males(const std::vector<Employee>& employees);

std::vector<Employee> get_male_pensioners(const std::vector<Employee>& employees);


size_t get_oldest_male(const std::vector<Employee>& employees,
                       bool(*comparator)(const Employee&, const Employee&));


//=====================
//  ФАЙЛОВЫЙ ВВОД/ВЫВОД
//=====================

void write_to_txt  (const std::vector<Employee>& employees);
void read_from_txt (std::vector<Employee>& employees);
void write_to_binary(const std::vector<Employee>& employees);
void read_from_binary(std::vector<Employee>& employees);


//================
//  ВСПОМОГАТЕЛЬНЫЕ
//================

//Содержит ли строка подстроку
inline bool contains(const std::string& text, const std::string& part) {
    return text.find(part) != std::string::npos;
}