#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream fin("input.txt");

    std::string s;
    if (!std::getline(fin, s)) {
        std::cout << "=\n";
        return 0;
    }

    int open_count = 0;
    int close_count = 0;

    for (char c : s) {
        if (c == '(') {
            ++open_count;
        } else if (c == ')') {
            ++close_count;
        }
    }

    int diff = open_count - close_count;

    if (diff == 0) {
        std::cout << "=\n";
    } else if (diff > 0) {
        std::cout << "(" << diff << "\n";
    } else {
        std::cout << ")" << (-diff) << "\n";
    }

    return 0;
}