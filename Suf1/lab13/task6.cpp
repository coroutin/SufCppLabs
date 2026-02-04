#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cctype>

int main() {
    std::ifstream infile("input.txt");

    if (!infile.is_open()) return 0;

    std::map<char, int> letter_weights;

    char letter;
    int weight;

    for (int i = 0; i < 26; ++i) {
        if (infile >> letter >> weight) {
            letter_weights[tolower(static_cast<unsigned char>(letter))] = weight;
        }
    }

    std::string word;
    if (!(infile >> word)) {
        infile.close();
        return 0;
    }

    long long total_score = 0;

    for (char c : word) {
        char lower_c = tolower(static_cast<unsigned char>(c));

        total_score += letter_weights[lower_c];
    }

    std::cout << total_score << std::endl;

    infile.close();
    return 0;
}