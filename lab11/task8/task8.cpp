#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>

void to_lower(std::string& s) {
    std::transform(s.begin(), s.end(), s.begin(),
        [](unsigned char c) { return std::tolower(c); });
}

int main() {
    std::cout << "Программа: поиск слова в тексте\n\n";

    std::ifstream fin("i_8.txt");

    std::string word;
    std::string text;

    if (!std::getline(fin, word)) {
        std::cout << "Файл пустой.\n";
        return 0;
    }

    if (!std::getline(fin, text)) {
        std::cout << "В файле есть только одна строка.\n";
        return 0;
    }

    std::string extra;
    if (std::getline(fin, extra)) {
        std::cout << "Файл содержит более двух строк. Лишние строки проигнорированы.\n\n";
    }

    std::cout << "Прочитано из файла:\n";
    std::cout << "Искомое слово: \"" << word << "\"\n";
    std::cout << "Текст:         \"" << text << "\"\n\n";

    if (word.empty()) {
        std::cout << "Искомое слово пустое.\n";
    }
    else {
        std::string word_lower = word;
        std::string text_lower = text;
        to_lower(word_lower);
        to_lower(text_lower);

        bool found = (text_lower.find(word_lower) != std::string::npos);

        std::cout << "Результат: ";
        if (found) {
            std::cout << "YES\n";
        }
        else {
            std::cout << "NO\n";
        }
    }

    return 0;
}