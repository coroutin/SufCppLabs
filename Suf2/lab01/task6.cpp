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

struct Employees {
    Employee* employees = nullptr;
    int size = 0;
};

Employees find_all_elements(Employee* employee,
                            size_t size,
                            bool(*condition)(Employee))
{
    Employees result;

    for (size_t i = 0; i < size; ++i) {
        if (condition(employee[i])) {
            result.size++;
        }
    }

    if (result.size == 0) {
        result.employees = nullptr;
        return result;
    }

    result.employees = new Employee[result.size];

    int index = 0;
    for (size_t i = 0; i < size; ++i) {
        if (condition(employee[i])) {
            result.employees[index++] = employee[i];
        }
    }

    return result;
}