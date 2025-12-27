#include <fstream>
#include <string>
#include <algorithm>

int main() {
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    std::string word;
    bool first = true;

    while (fin >> word) {
        std::reverse(word.begin(), word.end());

        if (!first) {
            fout << " ";
        }
        fout << word;
        first = false;
    }

    return 0;
}