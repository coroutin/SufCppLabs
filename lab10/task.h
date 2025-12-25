# pragma once
#include <string>
using namespace std;

void to_sentence_case(string& text);

char* as_sentence_case(const char* txt);

string to_lower_case(const string& text);

char* to_lower_case(const char* text);

string to_upper_case(const string& text);

char* to_upper_case(const char* text);

string to_title_case(const string& text);

char* to_title_case(const char* text);

string to_toggle_case(const string& text);

char* to_toggle_case(const char* text);

string trim(const string& text);

char* trim(const char* text);

string spaces_around_punctuation(const string& text);

char* spaces_around_punctuation(const char* text);

inline bool is_punctuation(char c) {
    return c == '.' || c == ',' || c == '!' || c == '?' || c == ':' || c == ';';
}