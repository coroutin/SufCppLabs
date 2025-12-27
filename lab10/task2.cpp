#include <iostream>
#include <string>
#include <cctype>

int get_telegram_cost(const char* text, int value) {
    if (text == nullptr || value < 0) {
        return 0;
    }

    int word_count = 0;
    bool in_word = false;

    while (*text != '\0') {
        if (std::isspace(static_cast<unsigned char>(*text))) {
            in_word = false;
        }
        else {
            if (!in_word) {
                ++word_count;
                in_word = true;
            }
        }
        ++text;
    }

    return word_count * value;
}

int get_telegram_cost(std::string text, int value) {
    if (value < 0) {
        return 0;
    }

    int word_count = 0;
    bool in_word = false;

    for (char ch : text) {
        if (std::isspace(static_cast<unsigned char>(ch))) {
            in_word = false;
        } else {
            if (!in_word) {
                ++word_count;
                in_word = true;
            }
        }
    }

    return word_count * value;
}