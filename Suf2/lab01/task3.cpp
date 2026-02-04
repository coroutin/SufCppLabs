#include <iostream>
#include <string>

struct Fullname {
    std::string surname = "";
    std::string name = "";
    std::string patronymic = "";
};

struct Employee {
    Fullname fullname;
    unsigned int age = 0;
    std::string passport = "";
    std::string phone = "";
    char gender;
};

void print(Employee* employee, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        std::cout << employee[i].fullname.surname << " "
                  << employee[i].fullname.name << " "
                  << employee[i].fullname.patronymic << " "
                  << employee[i].age << " "
                  << employee[i].passport << " "
                  << employee[i].phone << " "
                  << employee[i].gender << std::endl;
    }
}

void init(Employee* employee, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        std::cin >> employee[i].fullname.surname
                 >> employee[i].fullname.name
                 >> employee[i].fullname.patronymic
                 >> employee[i].age
                 >> employee[i].passport
                 >> employee[i].phone
                 >> employee[i].gender;
    }
}

Employee* init(size_t size) {
    Employee* employee = new Employee[size];
    for (size_t i = 0; i < size; ++i) {
        std::cin >> employee[i].fullname.surname
                 >> employee[i].fullname.name
                 >> employee[i].fullname.patronymic
                 >> employee[i].age
                 >> employee[i].passport
                 >> employee[i].phone
                 >> employee[i].gender;
    }
    return employee;
}