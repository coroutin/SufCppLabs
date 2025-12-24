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
        if (isupper(result[i])) result[i] = tolower(result[i]);
        else if (islower(result[i])) result[i] = toupper(result[i]);
    }
    return result;
}

string trim(const string& text) {
    size_t start = 0;
    while (start < text.length() && isspace((unsigned char)text[start])) {
        ++start;
    }

    if (start == text.length()) return "";

    size_t end = text.length() - 1;
    while (end > start && isspace((unsigned char)text[end])) {
        --end;
    }

    return text.substr(start, end - start + 1);
}

bool is_punctuation(char c) {
    return c == '.' || c == ',' || c == '!' || c == '?' || c == ':' || c == ';';
}

string spaces_around_punctuation(const string& text) {
    string result;
    result.reserve(text.size());

    bool last_was_space = false;

    for (size_t i = 0; i < text.size(); ++i) {
        char c = text[i];

        if (is_punctuation(c)) {
            if (!result.empty() && result.back() == ' ')
                result.pop_back();

            result.push_back(c);

            if (i + 1 < text.size() && text[i + 1] != ' ' && !is_punctuation(text[i + 1]))
                result.push_back(' ');

            last_was_space = false;
        }
        else if (c == ' ') {
            if (!last_was_space && !result.empty()) {
                result.push_back(' ');
                last_was_space = true;
            }
        }
        else {
            result.push_back(c);
            last_was_space = false;
        }
    }

    return result;
}

int main() {
    string original_text;
    string prepared_text;

    cout << "Введите текст: ";
    getline(cin, original_text);

    prepared_text = spaces_around_punctuation(trim(original_text));

    while (true) {
        cout << "\nВыберите способ изменения регистра:\n";
        cout << "1 - Как в предложениях\n";
        cout << "2 - все строчные\n";
        cout << "3 - ВСЕ ПРОПИСНЫЕ\n";
        cout << "4 - Начинать С Прописных\n";
        cout << "5 - иЗМЕНИТЬ РЕГИСТР\n";
        cout << "0 - Выход\n";
        cout << "Ваш выбор: ";

        int choice;
        cin >> choice;
        cin.ignore(10000, '\n');

        if (choice == 0) {
            cout << "Выход из программы.\n";
            break;
        }

        string result = prepared_text;

        switch (choice) {
            case 1: to_sentence_case(result); break;
            case 2: result = to_lower_case(result); break;
            case 3: result = to_upper_case(result); break;
            case 4: result = to_title_case(result); break;
            case 5: result = to_toggle_case(result); break;
            default:
                cout << "Неверный выбор!\n";
                continue;
        }

        cout << "\nРезультат:\n" << result << endl;
    }

    return 0;
}