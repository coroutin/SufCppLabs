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

int find_element(Employee* employee, size_t size,
                 bool(*condition)(Employee))
{
    for (size_t i = 0; i < size; ++i) {
        if (condition(employee[i])) {
            return static_cast<int>(i);
        }
    }
    return -1;
}