#include <iostream>
#include <string>
#include <fstream>

struct Fullname {
    std::string surname;
    std::string name;
    std::string patronymic;
};

struct Employee {
    Fullname fullname;
    unsigned int age;
    std::string passport;
    std::string phone;
    char gender;
};

struct Employees {
    Employee* employees = nullptr;
    int size = 0;
};

void print(Employee* employee, size_t size, std::string filename) {
    std::ofstream output(filename);
    output << size << std::endl;
    for (size_t i = 0; i < size; ++i) {
        output << employee[i].fullname.surname << " "
               << employee[i].fullname.name << " "
               << employee[i].fullname.patronymic << " "
               << employee[i].age << " "
               << employee[i].passport << " "
               << employee[i].phone << " "
               << employee[i].gender << std::endl;
    }
    output.close();
}

Employees init(std::string filename) {
    std::ifstream input(filename);
    Employees employees;

    input >> employees.size;

    employees.employees = new Employee[employees.size];

    for (int i = 0; i < employees.size; ++i) {
        input >> employees.employees[i].fullname.surname
              >> employees.employees[i].fullname.name
              >> employees.employees[i].fullname.patronymic
              >> employees.employees[i].age
              >> employees.employees[i].passport
              >> employees.employees[i].phone
              >> employees.employees[i].gender;
    }
    input.close();
    return employees;
}