#pragma once

#include <iostream>
#include <vector>

struct Employee {
    unsigned int id;
    std::string surname = "";
    std::string name = "";
    std::string patronymic = "";
    mutable unsigned int age;
    std::string passport = "";
    std::string phone = "";
    std::string gender;
};

std::ostream& operator<<(std::ostream& out, const Employee& employee);
std::istream& operator>>(std::istream& in, Employee& emp);

inline bool contains(const std::string& text, const std::string& part) {
    return text.find(part) != std::string::npos;
}

inline bool is_valid_gender(const std::string& gender) {
    return gender == "М" || gender == "Ж";
}

bool is_valid_phone(const std::string& phone);
bool is_valid_passport(const std::string& passport);
std::string input_phone();
std::string input_passport();
std::string input_gender();
void print_employee(const Employee& employee);
Employee input_employee(unsigned int id);
std::vector<Employee> input_employee(std::vector<Employee>& vector_employee);
void print_employee(const std::vector<Employee>& vector_employee);
Employee* find_by_id(std::vector<Employee>& vector_employee, unsigned int id);
std::vector<Employee> search_by_NSP(const std::vector<Employee>& vector_employee, const std::string& query);
std::vector<Employee> get_males(const std::vector<Employee>& vector_employee);
Employee* get_oldest(std::vector<Employee>& vector_employee);
std::vector<Employee> get_male_pensioners(const std::vector<Employee>& vector_employee);
void write_to_text(const std::vector<Employee>& vector_employee);
void read_from_text(std::vector<Employee>& vector_employee);
void write_to_binary(const std::vector<Employee>& vector_employee);
void read_from_binary(std::vector<Employee>& vector_employee);
