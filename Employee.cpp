#include "Employee.h"
#include <fstream>
#include <iomanip>

using namespace std;

istream& operator>>(istream& in, Fullname& fn) {
    in >> fn.surname >> fn.name >> fn.patronymic;
    return in;
}

ostream& operator<<(ostream& out, const Fullname& fullname) {
    out << fullname.surname << " " << fullname.name << " " << fullname.patronymic;
    return out;
}

ostream& operator<<(ostream& out, const Employee& employee) {
    out << employee.fullname << " "
        << employee.age << " "
        << employee.passport << " "
        << employee.phone << " "
        << employee.gender;
    return out;
}

istream& operator>>(istream& in, Employee& employee) {
    in >> employee.fullname
        >> employee.age
        >> employee.passport
        >> employee.phone
        >> employee.gender;
    return in;
}

void print(Employee* employee, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        cout << i + 1 << ". " << employee[i] << endl; //вывод сотрудников 
    }
}

void init(Employee* employee, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        cout << "Введите данные сотрудника (Фамилия Имя Отчество возраст паспорт телефон пол M/F):\n";
        cin >> employee[i];
       // cin >> employee[i].age;
       ///cin >> employee[i].passport;
       // cin >> employee[i].phone;
       // cin >> employee[i].gender;
    }
}

Employee* init(size_t size) {
    Employee* arr = new Employee[size];
    init(arr, size);
    return arr;
}

void init_From_Text_File(Employee* employee, size_t size, const string& filename) {
    ifstream in(filename);
    for (size_t i = 0; i < size; ++i) {
        in >> employee[i];
    }
    in.close();
    cout << "Загружено " << size << " сотрудников из " << filename << endl;
}

void print_To_Text_File(Employee* employee, size_t size, const string& filename) {
    ofstream out(filename);
    for (size_t i = 0; i < size; ++i) {
        out << employee[i] << endl;
    }
    out.close();
    cout << "Сохранено " << size << " сотрудников в " << filename << endl;
}

void write_bin_str(ostream& out, const string& s) {
    size_t len = s.length();
    out.write((char*)&len, sizeof(len)); // адрес на байты длина 
    out.write(s.c_str(), len); // длина стр сначала - 2.символы  запись симв 
}

void read_bin_str(istream& in, string& s) {
    size_t len;
    in.read((char*)&len, sizeof(len));
    s.resize(len);
    in.read(&s[0], len);
}

void save_to_binary(Employee* employee, size_t size, const string& filename) {
    ofstream out(filename, ios::binary);
    out.write((char*)&size, sizeof(size));

    for (size_t i = 0; i < size; i++) {
        write_bin_str(out, employee[i].fullname.surname);
        write_bin_str(out, employee[i].fullname.name);
        write_bin_str(out, employee[i].fullname.patronymic);
        write_bin_str(out, employee[i].passport);
        write_bin_str(out, employee[i].phone);
        out.write((char*)&employee[i].age, sizeof(employee[i].age));
        out.write(&employee[i].gender, sizeof(employee[i].gender));
    }

    out.close();
    cout << "Сохранено " << size << " сотрудников в " << filename << endl;
}
/*
* сщхр весь масс в бин  иос открыв в бин 
* 1 кол эл


*/

Employee* load_from_binary(const string& filename, size_t& size) {
    ifstream in(filename, ios::binary);

    if (!in) {
        cout << "Ошибка: файл " << filename << " не найден!\n";
        size = 0;
        return nullptr;
    }
    in.read((char*)&size, sizeof(size));
    Employee* arr = new Employee[size];

    for (size_t i = 0; i < size; i++) {
        read_bin_str(in, arr[i].fullname.surname);
        read_bin_str(in, arr[i].fullname.name);
        read_bin_str(in, arr[i].fullname.patronymic);
        read_bin_str(in, arr[i].passport);
        read_bin_str(in, arr[i].phone);
        in.read((char*)&arr[i].age, sizeof(arr[i].age));
        in.read(&arr[i].gender, sizeof(arr[i].gender));
    }

    in.close();
    cout << "Загружено " << size << " сотрудников из " << filename << endl;
    return arr;
}
//из бин файл

int find_element(Employee* employee, size_t size, bool(*condition)(Employee)) {
    for (size_t i = 0; i < size; ++i) {
        if (condition(employee[i])) return i;
    }
    return -1;
}
// поиск эл.
Employees find_all_elements(Employee* employee, size_t size, bool(*condition)(const Employee&)) {
    Employees result;
    result.size = 0;
    for (size_t i = 0; i < size; ++i) {
        if (condition(employee[i])) result.size++; // скок эл
    }
    result.employees = new Employee[result.size];// память
    int idx = 0;
    for (size_t i = 0; i < size; ++i) {
        if (condition(employee[i])) {
            result.employees[idx++] = employee[i];
        }
    }
    return result;
}// все элем.

size_t needful_element(Employee* employee, size_t size, bool(*comparator)(const Employee &, const Employee &)) {
    size_t idx = 0;
    for (size_t i = 1; i < size; ++i) {
        if (comparator(employee[i], employee[idx])) {
            idx = i;
        }
    }
    return idx;
}

bool is_Male(const Employee& e) {
    return e.gender == 'M' || e.gender == 'm';
}

bool is_Pensioner_Male(const Employee& e) {
    return is_Male(e) && e.age >= 65;
}

bool older_Than(const Employee& a, const Employee& b) {
    return a.age > b.age;
}

void print_Males(Employee* arr, size_t size) {
    cout << "\n ВСЕ МУЖЧИНЫ \n";
    Employees males = find_all_elements(arr, size, is_Male);

    if (males.size == 0) {
        cout << "Мужчины не найдены.\n";
    }
    else {
        cout << "Найдено мужчин: " << males.size << endl;
        print(males.employees, males.size);
        print_To_Text_File(males.employees, males.size, "males.txt");
        cout << "Результат сохранён в males.txt\n";
    }

    delete[] males.employees;
}

void print_Pensioner_Males(Employee* arr, size_t size) {
    cout << "\n МУЖЧИНЫ-ПЕНСИОНЕРЫ 65+\n";
    Employees pensioners = find_all_elements(arr, size, is_Pensioner_Male);

    if (pensioners.size == 0) {
        cout << "Мужчины-пенсионеры не найдены.\n";
    }
    else {
        cout << "Найдено мужчин-пенсионеров: " << pensioners.size << endl;
        print(pensioners.employees, pensioners.size);
        print_To_Text_File(pensioners.employees, pensioners.size, "pensioners_male.txt");
        cout << "Результат сохранён в pensioners_male.txt\n";
    }

    delete[] pensioners.employees;
}

void print_Oldest_Employee(Employee* arr, size_t size) {
    cout << " САМЫЙ ПОЖИЛОЙ СОТРУДНИК \n";

    if (size == 0) {
        cout << "Массив пуст.\n";
        return;
    }

    size_t idx = needful_element(arr, size, older_Than);
    cout << "Самый пожилой сотрудник: " << arr[idx] << endl;

    ofstream out("oldest.txt");
    out << "Самый пожилой сотрудник:\n";
    out << arr[idx] << endl;
    out.close();
    cout << "Результат сохранён в oldest.txt\n";
}

void print(const vector<Employee>& v) {
    if (v.empty()) {
        cout << "Вектор пуст.\n";
        return;
    }
    for (size_t i = 0; i < v.size(); i++) {
        cout << i + 1 << ". " << v[i] << endl;
    }
}

void init(vector<Employee>& v) {
    for (auto& emp : v) {
        cin >> emp;
    }
}

int find_element(const vector<Employee>& v, bool (*condition)( const Employee & )) {
    for (size_t i = 0; i < v.size(); i++) {
        if (condition(v[i])) return i;
    }
    return -1;
}

vector<Employee> find_all_elements(const vector<Employee>& v, bool(*condition)(const Employee&)) {
    vector<Employee> result;
    for (const auto& emp : v) { /// эмплоуее 
        if (condition(emp)) result.push_back(emp);
    }
    return result;
}

size_t needful_element(const vector<Employee>& v, bool(*comparator)(const Employee&, const Employee&)) {
    if (v.empty()) return 0;
    size_t idx = 0;
    for (size_t i = 1; i < v.size(); ++i) {
        if (comparator(v[i], v[idx])) idx = i;
    }
    return idx;
}

void init_vector_from_file(vector<Employee>& v, const string& filename) {
    ifstream in(filename);
    if (!in) {
        cout << "Ошибка: файл " << filename << " не найден!\n";
        return;
    }

    v.clear(); // очищаем вектор
    Employee emp;
    while (in >> emp) {
        v.push_back(emp);
    }
    in.close();
    cout << "Загружено " << v.size() << " сотрудников из " << filename << endl;
}

void save_vector_to_text_file(const vector<Employee>& v, const string& filename) {
    ofstream out(filename);
    if (!out) {
        cout << "Ошибка: не удалось создать файл " << filename << endl;
        return;
    }

    for (const auto& emp : v) {
        out << emp << endl;
    }
    out.close();
    cout << "Сохранено " << v.size() << " сотрудников в " << filename << endl;
}

void save_vector_to_binary(const vector<Employee>& v, const string& filename) {
    ofstream out(filename, ios::binary);
    if (!out) {
        cout << "Ошибка: не удалось создать файл " << filename << endl;
        return;
    }

    size_t size = v.size();
    out.write((char*)&size, sizeof(size));

    for (const auto& emp : v) {
        write_bin_str(out, emp.fullname.surname);
        write_bin_str(out, emp.fullname.name);
        write_bin_str(out, emp.fullname.patronymic);
        write_bin_str(out, emp.passport);
        write_bin_str(out, emp.phone);
        out.write((char*)&emp.age, sizeof(emp.age));
        out.write(&emp.gender, sizeof(emp.gender));
    }

    out.close();
    cout << "Сохранено " << size << " сотрудников в " << filename << endl;
}

void load_vector_from_binary(vector<Employee>& v, const string& filename) {
    ifstream in(filename, ios::binary);
    if (!in) {
        cout << "Ошибка: файл " << filename << " не найден!\n";
        return;
    }

    v.clear();
    size_t size;
    in.read((char*)&size, sizeof(size));

    for (size_t i = 0; i < size; i++) {
        Employee emp;
        read_bin_str(in, emp.fullname.surname);
        read_bin_str(in, emp.fullname.name);
        read_bin_str(in, emp.fullname.patronymic);
        read_bin_str(in, emp.passport);
        read_bin_str(in, emp.phone);
        in.read((char*)&emp.age, sizeof(emp.age));
        in.read(&emp.gender, sizeof(emp.gender));
        v.push_back(emp);
    }
    in.close();
    cout << "Загружено " << size << " сотрудников из " << filename << endl;}

void print_vector_menu() {
    cout << "\n Работа с вектором  \n";
    cout << "1. Ввод вектора с клавиатуры\n";
    cout << "2. Вывод вектора на экран\n";
    cout << "3. Запись вектора в текстовый файл\n";
    cout << "4. Чтение вектора из текстового файла (input.txt)\n";
    cout << "5. Запись вектора в бинарный файл\n";
    cout << "6. Чтение вектора из бинарного файла\n";
    cout << "7. Найти ВСЕХ мужчин в векторе\n";
    cout << "8. Найти ВСЕХ мужчин-пенсионеров в векторе\n";
    cout << "9. Найти САМОГО ПОЖИЛОГО в векторе\n";
    cout << "10. Добавить сотрудника в вектор\n";
    cout << "11. Удалить сотрудника из вектора (по индексу)\n";
    cout << "12. Очистить вектор\n";
    cout << "0. Вернуться в главное меню\n";
    cout << "Выберите действие: ";
}

void process_vector_operations() {
    vector<Employee> vec;
    int choice;

    do {
        print_vector_menu();

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка ввода! Введите число.\n";
            continue;
        }

        switch (choice) {
        case 1: {
            cout << "Введите количество сотрудников: ";
            int n;
            cin >> n;
            vec.resize(n);
            cout << "Введите данные сотрудников (Фамилия Имя Отчество возраст паспорт телефон пол M/F):\n";
            init(vec);
            break;
        }
        case 2: {
            if (!vec.empty()) {
                cout << "\n ВЕКТОР СОТРУДНИКОВ \n";
                print(vec);
            }
            else {
                cout << "Вектор пуст.\n";
            }
            break;
        }
        case 3: {
            if (!vec.empty()) {
                save_vector_to_text_file(vec, "vector_output.txt");
            }
            else {
                cout << "Вектор пуст.\n";
            }
            break;
        }
        case 4: {
            cout << "Введите количество сотрудников в файле input.txt: ";
            int size;
            if (!(cin >> size)) {
                cout << "Ошибка ввода размера!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }

            vec.clear();
            ifstream in("input.txt");
            if (!in) {
                cout << "Ошибка: файл input.txt не найден!\n";
                break;
            }

            Employee emp;
            int loaded = 0;
            for (int i = 0; i < size; i++) {
                if (in >> emp) {
                    vec.push_back(emp);
                    loaded++;
                }
                else {
                    break;
                }
            }
            in.close();

            cout << "Загружено " << loaded << " сотрудников из input.txt\n";
            if (loaded < size) {
                cout << "Предупреждение: в файле только " << loaded << " сотрудников\n";
            }
            break;
        }
        case 5: {
            if (!vec.empty()) {
                save_vector_to_binary(vec, "vector.bin");
            }
            else {
                cout << "Вектор пуст.\n";
            }
            break;
        }
        case 6: {
            load_vector_from_binary(vec, "vector.bin");
            break;
        }
        case 7: {
            if (!vec.empty()) {
                vector<Employee> males = find_all_elements(vec, is_Male);
                cout << "\n ВСЕ МУЖЧИНЫ \n";
                if (males.empty()) {
                    cout << "Мужчины не найдены.\n";
                }
                else {
                    cout << "Найдено мужчин: " << males.size() << endl;
                    print(males);
                    save_vector_to_text_file(males, "vector_males.txt");
                    cout << "Результат сохранён в vector_males.txt\n";
                }
            }
            else {
                cout << "Вектор пуст.\n";
            }
            break;
        }
        case 8: {
            if (!vec.empty()) {
                vector<Employee> pensioners = find_all_elements(vec, is_Pensioner_Male);
                cout << "\n МУЖЧИНЫ-ПЕНСИОНЕРЫ 65+ \n";
                if (pensioners.empty()) {
                    cout << "Мужчины-пенсионеры не найдены.\n";
                }
                else {
                    cout << "Найдено мужчин-пенсионеров: " << pensioners.size() << endl;
                    print(pensioners);
                    save_vector_to_text_file(pensioners, "vector_pensioners.txt");
                    cout << "Результат сохранён в vector_pensioners.txt\n";
                }
            }
            else {
                cout << "Вектор пуст.\n";
            }
            break;
        }
        case 9: {
            if (!vec.empty()) {
                size_t idx = needful_element(vec, older_Than);
                cout << "\n САМЫЙ ПОЖИЛОЙ СОТРУДНИК \n";
                cout << "Самый пожилой сотрудник: " << vec[idx] << endl;

                ofstream out("vector_oldest.txt");
                out << "Самый пожилой сотрудник:\n";
                out << vec[idx] << endl;
                out.close();
                cout << "Результат сохранён в vector_oldest.txt\n";
            }
            else {
                cout << "Вектор пуст.\n";
            }
            break;
        }
        case 10: {
            Employee emp;
            cout << "Введите данные сотрудника (Фамилия Имя Отчество возраст паспорт телефон пол M/F):\n";
            cin >> emp;
            vec.push_back(emp);
            cout << "Сотрудник добавлен. Текущий размер вектора: " << vec.size() << endl;
            break;
        }
        case 11: {
            if (!vec.empty()) {
                cout << "Введите индекс для удаления (1-" << vec.size() << "): ";
                size_t idx;
                cin >> idx;
                if (idx >= 1 && idx <= vec.size()) {
                    vec.erase(vec.begin() + idx - 1);
                    cout << "Сотрудник удален.\n";
                }
                else {
                    cout << "Неверный индекс!\n";
                }
            }
            else {
                cout << "Вектор пуст.\n";
            }
            break;
        }
        case 12: {
            vec.clear();
            cout << "Вектор очищен.\n";
            break;
  
        }
        case 0:
            cout << "Возврат в главное меню.\n";
            break;
        default:
            cout << "Неверный ввод. Попробуйте снова.\n";
        }
    } while (choice != 0);
}