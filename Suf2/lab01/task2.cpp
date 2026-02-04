#include <iostream>
#include <string>

struct Fullname {
    std::string surname = "";
    std::string name = "";
    std::string patronymic = "";
};

std::ostream& operator<<(std::ostream& out, const Fullname& fullname) {
    out << fullname.surname << " " << fullname.name << " " << fullname.patronymic;
    return out;
}

std::istream& operator>>(std::istream& in, Fullname& fullname) {
    in >> fullname.surname;
    in >> fullname.name;
    in >> fullname.patronymic;
    return in;
}

struct Employee {
    Fullname fullname;
    unsigned int age = 0;
    std::string passport = "";
    std::string phone = "";
    char gender;
};

std::ostream& operator<<(std::ostream& out, Employee& employee) {
    out << employee.fullname << " "
        << employee.age << " "
        << employee.passport << " "
        << employee.phone;
    return out;
}

std::istream& operator>>(std::istream& in, Employee& employee) {
    in >> employee.fullname;
    in >> employee.age;
    in >> employee.passport;
    in >> employee.phone;
    return in;
}
