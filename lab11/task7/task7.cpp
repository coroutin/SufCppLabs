#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

void reverse_word(std::string& s) {
    std::reverse(s.begin(), s.end());
}

int main() {
    std::cout << "Программа: разворот слов в обратном порядке\n\n";

    const std::string input_filename  = "i_7.txt";
    const std::string output_filename = "o_7.txt";

    std::ifstream fin(input_filename);
    std::ofstream fout(output_filename);


    std::string word;
    bool first = true;
    bool has_words = false;

    while (fin >> word) {
        has_words = true;

        reverse_word(word);

        if (!first) {
            fout << " ";
        }
        fout << word;
        first = false;
    }

    if (!has_words) {
        std::cout << "\nВходной файл пустой или не содержит слов.\n";
        std::cout << "Выходной файл o_7.txt будет пустым.\n\n";
    } else {
        std::cout << "\nВсе слова из файла i_7.txt успешно обработаны и записаны в файл \"" << output_filename << "\"\n\n";
    }

    fin.close();
    fout.close();

    return 0;
}