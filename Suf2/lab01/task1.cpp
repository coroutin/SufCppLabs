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
