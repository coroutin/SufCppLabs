#include "../task.h"
#include <cctype>
#include <cstring>
#include <algorithm>

std::string to_sentence_case(const std::string& text) {
    std::string result = text;
    bool new_sentence = true;

    for (size_t i = 0; i < result.size(); ++i) {
        unsigned char c = result[i];

        if (new_sentence && std::isalpha(c)) {
            result[i] = std::toupper(c);
            new_sentence = false;
        } else {
            result[i] = std::tolower(c);
        }

        if (c == '.' || c == '!' || c == '?')
            new_sentence = true;
    }
    return result;
}

char* to_sentence_case(const char* text) {
    if (!text) return new char[1]{'\0'};
    std::string tmp = to_sentence_case(std::string(text));
    char* res = new char[tmp.size() + 1];
    std::strcpy(res, tmp.c_str());
    return res;
}

std::string to_lower_case(const std::string& text) {
    std::string r = text;
    std::transform(r.begin(), r.end(), r.begin(), ::tolower);
    return r;
}

char* to_lower_case(const char* text) {
    if (!text) return new char[1]{'\0'};
    std::string tmp = to_lower_case(std::string(text));
    char* res = new char[tmp.size() + 1];
    std::strcpy(res, tmp.c_str());
    return res;
}

std::string to_upper_case(const std::string& text) {
    std::string r = text;
    std::transform(r.begin(), r.end(), r.begin(), ::toupper);
    return r;
}

char* to_upper_case(const char* text) {
    if (!text) return new char[1]{'\0'};
    std::string tmp = to_upper_case(std::string(text));
    char* res = new char[tmp.size() + 1];
    std::strcpy(res, tmp.c_str());
    return res;
}

std::string to_title_case(const std::string& text) {
    std::string r = text;
    bool new_word = true;

    for (char& c : r) {
        if (std::isalpha((unsigned char)c)) {
            c = new_word ? std::toupper(c) : std::tolower(c);
            new_word = false;
        } else {
            new_word = std::isspace((unsigned char)c) || is_punctuation(c);
        }
    }
    return r;
}

char* to_title_case(const char* text) {
    if (!text) return new char[1]{'\0'};
    std::string tmp = to_title_case(std::string(text));
    char* res = new char[tmp.size() + 1];
    std::strcpy(res, tmp.c_str());
    return res;
}

std::string to_toggle_case(const std::string& text) {
    std::string r = text;
    for (char& c : r) {
        if (std::islower((unsigned char)c)) c = std::toupper(c);
        else if (std::isupper((unsigned char)c)) c = std::tolower(c);
    }
    return r;
}

char* to_toggle_case(const char* text) {
    if (!text) return new char[1]{'\0'};
    std::string tmp = to_toggle_case(std::string(text));
    char* res = new char[tmp.size() + 1];
    std::strcpy(res, tmp.c_str());
    return res;
}

std::string trim(const std::string& text) {
    size_t l = 0, r = text.size();
    while (l < r && std::isspace((unsigned char)text[l])) ++l;
    while (r > l && std::isspace((unsigned char)text[r - 1])) --r;
    return text.substr(l, r - l);
}

char* trim(const char* text) {
    if (!text) return new char[1]{'\0'};
    std::string tmp = trim(std::string(text));
    char* res = new char[tmp.size() + 1];
    std::strcpy(res, tmp.c_str());
    return res;
}

std::string spaces_around_punctuation(const std::string& text) {
    std::string result;
    bool space = false;

    for (char c : text) {
        if (std::isspace((unsigned char)c)) {
            if (!space && !result.empty()) {
                result += ' ';
                space = true;
            }
        }
        else if (is_punctuation(c)) {
            if (!result.empty() && result.back() == ' ')
                result.pop_back();

            result += c;
            result += ' ';
            space = true;
        }
        else {
            result += c;
            space = false;
        }
    }

    if (!result.empty() && result.back() == ' ')
        result.pop_back();

    return result;
}


char* spaces_around_punctuation(const char* text) {
    if (!text) return new char[1]{'\0'};

    std::string tmp = spaces_around_punctuation(std::string(text));

    char* res = new char[tmp.size() + 1];
    std::strcpy(res, tmp.c_str());
    return res;
}