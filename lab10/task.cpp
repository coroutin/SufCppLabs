#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include "task.h"

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

char* as_sentence_case(const char* txt) {
    static char res[5000];
    int n = strlen(txt);
    for (int i = 0; i < n; i++)
        res[i] = txt[i];
    if (n > 0 && isalpha(res[0]))
        res[0] = toupper(res[0]);
    for (int i = 0; i < n - 2; i++) {
        if ((res[i] == '.' || res[i] == '!' || res[i] == '?') && res[i+1] == ' ' && isalpha(res[i+2]))
            res[i+2] = toupper(res[i+2]);
    }
    res[n] = '\0';
    return res;
}

string to_lower_case(const string& text) {
    string result = text;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

char* to_lower_case(const char* text)
{
    if (text == nullptr)
    {
        char* empty = new char[1]{'\0'};
        return empty;
    }

    size_t len = std::strlen(text);
    char* result = new char[len + 1];

    for (size_t i = 0; i < len; ++i)
    {
        unsigned char ch = static_cast<unsigned char>(text[i]);

        if (std::isalpha(ch))
            result[i] = static_cast<char>(std::tolower(ch));
        else
            result[i] = text[i];
    }

    result[len] = '\0';
    return result;
}

string to_upper_case(const string& text) {
    string result = text;
    transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

char* to_upper_case(const char* text)
{
    if (text == nullptr)
    {
        char* empty = new char[1]{'\0'};
        return empty;
    }

    size_t len = std::strlen(text);
    char* result = new char[len + 1];

    for (size_t i = 0; i < len; ++i)
    {
        unsigned char ch = static_cast<unsigned char>(text[i]);

        if (std::isalpha(ch))
            result[i] = static_cast<char>(std::toupper(ch));
        else
            result[i] = text[i];
    }

    result[len] = '\0';
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

char* to_title_case(const char* text)
{
    if (text == nullptr)
    {
        char* empty = new char[1]{'\0'};
        return empty;
    }

    size_t len = std::strlen(text);
    char* result = new char[len + 1];

    bool new_word = true;

    for (size_t i = 0; i < len; ++i)
    {
        unsigned char ch = static_cast<unsigned char>(text[i]);

        if (std::isalpha(ch))
        {
            if (new_word)
            {
                result[i] = static_cast<char>(std::toupper(ch));
                new_word = false;
            }
            else
            {
                result[i] = static_cast<char>(std::tolower(ch));
            }
        }
        else
        {
            result[i] = text[i];
            new_word = (text[i] == ' ');
        }
    }

    result[len] = '\0';
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

char* to_toggle_case(const char* text)
{
    if (text == nullptr)
    {
        char* empty = new char[1]{'\0'};
        return empty;
    }

    size_t len = std::strlen(text);
    char* result = new char[len + 1];

    for (size_t i = 0; i < len; ++i)
    {
        unsigned char ch = static_cast<unsigned char>(text[i]);

        if (std::isupper(ch))
            result[i] = static_cast<char>(std::tolower(ch));
        else if (std::islower(ch))
            result[i] = static_cast<char>(std::toupper(ch));
        else
            result[i] = text[i];
    }

    result[len] = '\0';
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

char* trim(const char* text)
{
    if (!text)
    {
        char* empty = new char[1]{ '\0' };
        return empty;
    }

    const char* start = text;
    while (*start && std::isspace(static_cast<unsigned char>(*start)))
        ++start;

    const char* end = text + std::strlen(text) - 1;
    while (end >= start && std::isspace(static_cast<unsigned char>(*end)))
        --end;

    size_t len = (end >= start) ? (end - start + 1) : 0;
    char* result = new char[len + 1];

    if (len > 0)
        std::strncpy(result, start, len);

    result[len] = '\0';
    return result;
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

char* spaces_around_punctuation(const char* text){
    if (!text){
        char* empty = new char[1]{ '\0' };
        return empty;
    }

    size_t len = std::strlen(text);
    char* result = new char[len * 2 + 1];
    size_t pos = 0;

    for (size_t i = 0; i < len; ++i){
        char c = text[i];

        if (is_punctuation(c)){
            if (pos > 0 && result[pos - 1] == ' ')
                pos--;

            result[pos++] = c;

            if (i + 1 < len && text[i + 1] != ' ')
                result[pos++] = ' ';
        }
        else{
            result[pos++] = c;
        }
    }

    result[pos] = '\0';
    return result;
}