#include <iostream>
#include <string>

using namespace std;

bool is_punctuation(char c) {
    return c == '.' || c == ',' || c == '!' || c == '?' || c == ':' || c == ';';
}

string spaces_around_punctuation(string text) {
    string result;
    result.reserve(text.size());

    bool last_was_space = false;
    bool last_was_punctuation = false;

    for (size_t i = 0; i < text.size(); ++i) {
        char c = text[i];

        if (is_punctuation(c)) {
            // Убираем пробел перед знаком препинания
            if (!result.empty() && result.back() == ' ') {
                result.pop_back();
                last_was_space = false;
            }

            result.push_back(c);
            last_was_punctuation = true;
            last_was_space = false;

            // Добавляем пробел после знака препинания, если дальше есть символы и пробела нет
            if (i + 1 < text.size()) {
                char next = text[i + 1];
                if (next != ' ' && !is_punctuation(next)) {  // если следующий символ не пробел и не другой знак
                    result.push_back(' ');
                    last_was_space = true;
                }
            }
        }
        else if (c == ' ') {
            if (!last_was_space && !result.empty() &&
                (isalnum(result.back()) || is_punctuation(result.back()))) {
                result.push_back(' ');
                last_was_space = true;
            }
            last_was_punctuation = false;
        }
        else {
            result.push_back(c);
            last_was_space = false;
            last_was_punctuation = false;
        }
    }

    return result;
}

int main() {
    string userText;

    cout << "Введите текст:\n";
    getline(cin, userText);

    string processed = spaces_around_punctuation(userText);

    cout << "\nТекст после удаления лишних символов:\n";
    cout << processed << endl;

    return 0;
}