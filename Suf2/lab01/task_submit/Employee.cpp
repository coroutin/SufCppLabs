#include "Employee.h"
#include <vector>
#include <cctype>
#include <limits>
#include <fstream>

// Валидность телефона
bool is_valid_phone(const std::string& phone) {
    if (phone.length() != 11 && phone.length() != 12) return false;

    if (phone.length() == 11) {
        for (int i = 0; i < 11; ++i)
            if (!std::isdigit(phone[i])) return false;
    }

    if (phone.length() == 12) {
        if (phone[0] != '+') return false;
        for (int i = 1; i < 12; ++i)
            if (!std::isdigit(phone[i])) return false;
    }

    return true;
}
// Валидность паспорта
bool is_valid_passport(const std::string& passport) {
    if (passport.length() != 11) return false;
    for (int i = 0; i < 4; ++i)
        if (!std::isdigit(passport[i])) return false;
    if (passport[4] != ' ') return false;
    for (int i = 5; i < 11; ++i)
        if (!std::isdigit(passport[i])) return false;
    return true;
}

std::string input_phone() {
    std::string phone;
    bool valid = false;
    std::cout << "Номер телефона (+XXXXXXXXXXX или XXXXXXXXXXX): ";
    std::getline(std::cin, phone);
    while (!valid) {
        if (is_valid_phone(phone)) {
            valid = true;
        }
        else {
            std::cout << "Номер телефона должен быть в формате: +XXXXXXXXXXX или XXXXXXXXXXX\n";
            std::cout << "Номер телефона (+XXXXXXXXXXX или XXXXXXXXXXX): ";
            std::getline(std::cin, phone);
        }
    }
    return phone;
}

std::string input_passport() {
    std::string passport;
    bool valid = false;
    std::cout << "Паспорт (формат: XXXX YYYYYY): ";
    std::getline(std::cin, passport);
    while (!valid) {
        if (is_valid_passport(passport)) {
            valid = true;
        }
        else {
            std::cout << "Паспорт должен быть в формате XXXX YYYYYY\n";
            std::cout << "Паспорт (XXXX YYYYYY): ";
            std::getline(std::cin, passport);
        }
    }
    return passport;
}

std::string input_gender() {
    std::string gender;
    bool valid = false;
    std::cout << "Пол (М/Ж): ";
    std::getline(std::cin, gender);
    while (!valid) {
        if (is_valid_gender(gender)) {
            valid = true;
        }
        else {
            std::cout << "Пол должен быть М или Ж\n";
            std::cout << "Пол (М/Ж): ";
            std::getline(std::cin, gender);
        }
    }
    return gender;
}

std::ostream& operator<<(std::ostream& out, const Employee& employee) {
    out << "ФИО: " << employee.surname << " " << employee.name << " " << employee.patronymic << "\n"
        << "Возраст: " << employee.age << "\n"
        << "Паспорт: " << employee.passport << "\n"
        << "Телефон: " << employee.phone << "\n"
        << "Пол: " << employee.gender << "\n";
    return out;
}

std::istream& operator>>(std::istream& in, Employee& emp) {
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Фамилия: ";
    std::getline(in, emp.surname);
    std::cout << "Имя: ";
    std::getline(in, emp.name);
    std::cout << "Отчество: ";
    std::getline(in, emp.patronymic);
    std::cout << "Возраст: ";
    in >> emp.age;
    in.ignore();
    emp.passport = input_passport();
    emp.phone = input_phone();
    emp.gender = input_gender();
    return in;
}

Employee input_employee(unsigned int id) {
    Employee employee;
    employee.id = id;
    std::cin >> employee;
    return employee;
}

void input_employee(std::vector<Employee>& vector_employee) {
    int n;
    std::cout << "Количество сотрудников (>=8): ";
    std::cin >> n;

    static unsigned int next_id = 1;

    for (int i = 0; i < n; ++i) {
        std::cout << "\nСотрудник №" << i + 1 << "\n";
        vector_employee.push_back(input_employee(next_id++));
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void print_employee(const Employee& employee) {
    std::cout << "-----------------\n";
    std::cout << employee;
}

void print_employee(const std::vector<Employee>& vector_employee) {
    for (const auto& employee : vector_employee)
        print_employee(employee);
}

std::vector<Employee> search_by_NSP(const std::vector<Employee>& vector_employee, const std::string& query) {
    std::vector<Employee> result;
    for (const auto& employee : vector_employee) {
        if (contains(employee.surname, query) || contains(employee.name, query) || contains(employee.patronymic, query))
            result.push_back(employee);
    }
    return result;
}

Employee* find_by_id(std::vector<Employee>& vector_employee, unsigned int id) {
    for (auto& employee : vector_employee)
        if (employee.id == id) return &employee;
    return nullptr;
}

std::vector<Employee> get_males(const std::vector<Employee>& vector_employee) {
    std::vector<Employee> males;
    for (const auto& employee : vector_employee) {
        if (employee.gender == "М") {
            males.push_back(employee);
        }
    }
    return males;
}

Employee* get_oldest(std::vector<Employee>& vector_employee) {
    if (vector_employee.empty()) return nullptr;

    Employee* oldest = &vector_employee[0];

    for (auto& employee : vector_employee) {
        if (employee.gender == "М" && employee.age > oldest->age) {
            oldest = &employee;
        }
    }
    return oldest;
}

std::vector<Employee> get_male_pensioners(const std::vector<Employee> &vector_employee) {
    std::vector<Employee> male_pensioners;
    for (const auto& employee : vector_employee) {
        if (employee.gender == "М" && employee.age >= 65) {
            male_pensioners.push_back(employee);
        }
    }
    return male_pensioners;
}

static void write_string_binary(std::ofstream& file, const std::string& str) {
    size_t len = str.size();
    file.write(reinterpret_cast<const char*>(&len), sizeof(len));
    file.write(str.c_str(), len);
}

static std::string read_string_binary(std::ifstream& file) {
    size_t len;
    file.read(reinterpret_cast<char*>(&len), sizeof(len));
    std::string str(len, '\0');
    file.read(&str[0], len);
    return str;
}

void write_to_text(const std::vector<Employee>& vector_employee) {
    std::ofstream file("employees.txt");
    for (const auto& emp : vector_employee) {
        file << emp.id << "\n" << emp.surname << "\n" << emp.name << "\n"
             << emp.patronymic << "\n" << emp.age << "\n"
             << emp.passport << "\n" << emp.phone << "\n" << emp.gender << "\n";
    }
    std::cout << "Данные записаны в employees.txt " << "\n";
}

void read_from_text(std::vector<Employee>& vector_employee) {
    std::ifstream file("employees.txt");
    vector_employee.clear();
    Employee emp;
    while (file >> emp.id) {
        file.ignore();
        std::getline(file, emp.surname);
        std::getline(file, emp.name);
        std::getline(file, emp.patronymic);
        file >> emp.age;
        file.ignore();
        std::getline(file, emp.passport);
        std::getline(file, emp.phone);
        std::getline(file, emp.gender);
        vector_employee.push_back(emp);
    }
    std::cout << "Загружено " << vector_employee.size() << " сотрудников из employees.txt" << "\n";
}

void write_to_binary(const std::vector<Employee>& vector_employee) {
    std::ofstream file("employees.bin", std::ios::binary);
    size_t count = vector_employee.size();
    file.write(reinterpret_cast<const char*>(&count), sizeof(count));
    for (const auto& emp : vector_employee) {
        file.write(reinterpret_cast<const char*>(&emp.id),  sizeof(emp.id));
        file.write(reinterpret_cast<const char*>(&emp.age), sizeof(emp.age));
        write_string_binary(file, emp.surname);
        write_string_binary(file, emp.name);
        write_string_binary(file, emp.patronymic);
        write_string_binary(file, emp.passport);
        write_string_binary(file, emp.phone);
        write_string_binary(file, emp.gender);
    }
    std::cout << "Данные записаны в employees.bin" << "\n";
}

void read_from_binary(std::vector<Employee>& vector_employee) {
    std::ifstream file("employees.bin", std::ios::binary);
    vector_employee.clear();
    size_t count;
    file.read(reinterpret_cast<char*>(&count), sizeof(count));
    for (size_t i = 0; i < count; ++i) {
        Employee emp;
        file.read(reinterpret_cast<char*>(&emp.id),  sizeof(emp.id));
        file.read(reinterpret_cast<char*>(&emp.age), sizeof(emp.age));
        emp.surname    = read_string_binary(file);
        emp.name       = read_string_binary(file);
        emp.patronymic = read_string_binary(file);
        emp.passport   = read_string_binary(file);
        emp.phone      = read_string_binary(file);
        emp.gender     = read_string_binary(file);
        vector_employee.push_back(emp);
    }
    std::cout << "Загружено " << vector_employee.size() << " сотрудников из employees.bin" << "\n";
}