#include <iostream>
#include <string>
#include <cstring>
#include "task.h"

int main() {
    std::string input;
    std::cout << "Введите текст: ";
    std::getline(std::cin, input);

    char* text_c = new char[input.size() + 1];
    std::strcpy(text_c, input.c_str());

    char* prepared_c = spaces_around_punctuation(text_c);
    std::string prepared_s = spaces_around_punctuation(input);

    int choice;
    do {
        std::cout <<
        "\n1 - Как в предложениях\n"
        "2 - все строчные\n"
        "3 - ВСЕ ПРОПИСНЫЕ\n"
        "4 - Начинать С Прописных\n"
        "5 - иЗМЕНИТЬ РЕГИСТР\n"
        "0 - Выход\nВаш выбор: ";

        std::cin >> choice;
        std::cin.ignore(10000, '\n');

        if (choice == 0) break;

        char* result_c = nullptr;
        std::string result_s = prepared_s;

        switch (choice) {
            case 1: result_c = to_sentence_case(prepared_c);
                result_s = to_sentence_case(result_s); break;
            case 2: result_c = to_lower_case(prepared_c);
                result_s = to_lower_case(result_s); break;
            case 3: result_c = to_upper_case(prepared_c);
                result_s = to_upper_case(result_s); break;
            case 4: result_c = to_title_case(prepared_c);
                result_s = to_title_case(result_s); break;
            case 5: result_c = to_toggle_case(prepared_c);
                result_s = to_toggle_case(result_s); break;
            default:
                std::cout << "Неверный выбор\n";
                continue;
        }

        std::cout << "\nchar*: " << result_c << "\nstring: " << result_s << "\n";
        delete[] result_c;

    } while (true);

    delete[] text_c;
    delete[] prepared_c;
    return 0;
}