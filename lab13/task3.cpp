#include <iostream>
#include <fstream>
#include <string>
#include <set>

int main() {
    std::ifstream infile("input.txt");

    std::set<std::string> unique_words;
    std::string word;

    while (infile >> word) {
        unique_words.insert(word);
    }

    std::cout << unique_words.size() << std::endl;

    bool first = true;
    for (const std::string& w : unique_words) {
        if (!first) {
            std::cout << " ";
        }
        std::cout << w;
        first = false;
    }
    std::cout << std::endl;

    infile.close();
    return 0;
}