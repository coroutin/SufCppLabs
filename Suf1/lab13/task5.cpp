#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>

bool compare(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
    if (a.second != b.second) {
        return a.second > b.second;
    }
    return a.first < b.first;
}

int main() {
    std::ifstream infile("input.txt");
    std::ofstream outfile("output.txt");

    if (!infile.is_open()) return 0;

    std::map<std::string, int> freq_map;
    std::string line;

    std::string current_word = "";
    char ch;
    while (infile.get(ch)) {
        if (isalpha(static_cast<unsigned char>(ch))) {
            current_word += tolower(static_cast<unsigned char>(ch));
        } else {
            if (!current_word.empty()) {
                freq_map[current_word]++;
                current_word = "";
            }
        }
    }
    if (!current_word.empty()) {
        freq_map[current_word]++;
    }

    std::vector<std::pair<std::string, int>> sorted_list(freq_map.begin(), freq_map.end());

    sort(sorted_list.begin(), sorted_list.end(), compare);

    for (const auto& p : sorted_list) {
        outfile << p.first << ": " << p.second << std::endl;
    }

    infile.close();
    outfile.close();

    return 0;
}