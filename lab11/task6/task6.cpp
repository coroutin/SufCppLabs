#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::cout << "Программа: проверка количества круглых скобок\n\n";

    const std::string filename = "i_6.txt";
    std::ifstream fin(filename);

    std::string s;
    if (!std::getline(fin, s)) {
        std::cout << "Файл пустой.\n";
        return 0;
    }

    std::string extra;
    if (std::getline(fin, extra)) {
        std::cout << "Файл содержит более одной строки. "
                     "Будет обработана только первая строка.\n\n";
    }

    std::cout << "Прочитано: \"" << s << "\"\n\n";

    int open = 0, close = 0;

    for (char c : s) {
        if (c == '(') {
            ++open;
        } else if (c == ')') {
            ++close;
        }
    }

    if (open == 0 || close == 0) {
        std::cout <<"Скобок нет.";
        return 0;
    }
    std::cout << "Количество открывающихся скобок: " << open << "\n";
    std::cout << "Количество закрывающихся скобок: " << close << "\n\n";

    std::cout << "Результат: ";
    if (open == close) {
        std::cout << "=";
    } else if (open > close) {
        std::cout << "( " << (open - close);
    } else {
        std::cout << ") " << (close - open);
    }

    std::cout << "\n\n";
    return 0;
}
