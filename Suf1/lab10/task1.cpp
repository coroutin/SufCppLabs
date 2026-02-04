#include <iostream>
#include <string>

void change(char* str, char firstsymbol, char secondsymbol) {
    if (str == nullptr) {
        return;
    }

    while (*str != '\0') {
        if (*str == firstsymbol) {
            *str = secondsymbol;
        }
        ++str;
    }
}

void change(std::string &str, char firstsymbol, char secondsymbol) {
    for (char &ch : str) {
        if (ch == firstsymbol) {
            ch = secondsymbol;
        }
    }
}