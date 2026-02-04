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

size_t needful_element(Employee* employee,
                       size_t size,
                       bool(*comparator)(Employee, Employee))
{
    size_t index = 0;

    for (size_t i = 1; i < size; ++i) {
        if (comparator(employee[i], employee[index])) {
            index = i;
        }
    }

    return index;
}