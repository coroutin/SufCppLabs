#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string trim(string text)
{
    size_t start = 0;
    while (start < text.length() && isspace(static_cast<unsigned char>(text[start]))) {
        ++start;
    }

    if (start == text.length()) {
        return "";
    }

    size_t end = text.length() - 1;
    while (end > start && isspace(static_cast<unsigned char>(text[end]))) {
        --end;
    }

    return text.substr(start, end - start + 1);
}

int main() {

    string userText;

    cout << "Введите строку (пробелы в начале и конце будут удалены):\n";
    getline(cin, userText);

    string trimmedText = trim(userText);

    cout << "\nПосле удаления пробелов:\n";
    cout << trimmedText << endl;

    return 0;
}