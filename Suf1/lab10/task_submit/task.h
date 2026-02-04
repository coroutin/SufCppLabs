#pragma once
#include <string>

std::string to_sentence_case(const std::string& text);
char* to_sentence_case(const char* text);

std::string to_lower_case(const std::string& text);
char* to_lower_case(const char* text);

std::string to_upper_case(const std::string& text);
char* to_upper_case(const char* text);

std::string to_title_case(const std::string& text);
char* to_title_case(const char* text);

std::string to_toggle_case(const std::string& text);
char* to_toggle_case(const char* text);

std::string trim(const std::string& text);
char* trim(const char* text);

std::string spaces_around_punctuation(const std::string& text);
char* spaces_around_punctuation(const char* text);

inline bool is_punctuation(char c) {
    return c == '.' || c == ',' || c == '!' || c == '?' || c == ':' || c == ';';
}
