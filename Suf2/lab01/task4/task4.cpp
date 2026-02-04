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