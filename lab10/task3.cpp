#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

void to_sentence_case(string& text) {
    if (text.empty()) return;

    bool new_sentence = true;

    for (size_t i = 0; i < text.length(); ++i) {
        char c = text[i];

        if (new_sentence && isalpha(c)) {
            text[i] = toupper(c);
            new_sentence = false;
        } else {
            text[i] = tolower(c);
        }

        if (c == '.' || c == '!' || c == '?') {
            new_sentence = true;
        }
    }
}

string to_lower_case(const string& text) {
    string result = text;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

string to_upper_case(const string& text) {
    string result = text;
    transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

string to_title_case(const string& text) {
    string result = text;
    bool new_word = true;
    for (size_t i = 0; i < result.length(); ++i) {
        if (new_word && isalpha(result[i])) {
            result[i] = toupper(result[i]);
            new_word = false;
        } else {
            result[i] = tolower(result[i]);
        }
        if (isspace(result[i]) || ispunct(result[i])) {
            new_word = true;
        }
    }
    return result;
}

string to_toggle_case(const string& text) {
    string result = text;
    for (size_t i = 0; i < result.length(); ++i) {
        if (isupper(result[i])) {
            result[i] = tolower(result[i]);
        } else if (islower(result[i])) {
            result[i] = toupper(result[i]);
        }
    }
    return result;
}

int main() {

    string text;
    cout << "Введите текст: ";
    getline(cin, text);

    cout << "\nВыберите способ изменения регистра:\n";
    cout << "1 - Как в предложениях\n";
    cout << "2 - все строчные\n";
    cout << "3 - ВСЕ ПРОПИСНЫЕ\n";
    cout << "4 - Начинать С Прописных\n";
    cout << "5 - иЗМЕНИТЬ РЕГИСТР\n";
    cout << "Ваш выбор: ";

    int choice;
    cin >> choice;

    string result = text;

    switch (choice) {
        case 1:
            result = text;
            to_sentence_case(result);
            break;
        case 2:
            result = to_lower_case(text);
            break;
        case 3:
            result = to_upper_case(text);
            break;
        case 4:
            result = to_title_case(text);
            break;
        case 5:
            result = to_toggle_case(text);
            break;
        default:
            cout << "Неверный выбор!\n";
            return 1;
    }

    cout << "\nРезультат:\n" << result << endl;

    return 0;
}