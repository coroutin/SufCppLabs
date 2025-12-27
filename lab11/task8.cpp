#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

std::string to_lower(std::string s) {
    for (char& c : s) {
        c = std::tolower(static_cast<unsigned char>(c));
    }
    return s;
}

int main() {
    std::ifstream fin("input.txt");

    std::string word, text;
    std::getline(fin, word);
    std::getline(fin, text);

    word = to_lower(word);
    text = to_lower(text);

    std::stringstream ss(text);
    std::string cur;

    while (ss >> cur) {
        if (cur == word) {
            std::cout << "YES";
            return 0;
        }
    }

    std::cout << "NO";
    return 0;
}
