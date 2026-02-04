#include <cstring>
#include <string>

bool is_punctuation(char c){
    return c == '.' || c == ',' || c == '!' || c == '?' || c == ':' || c == ';';
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

std::string spaces_around_punctuation(std::string text){
    std::string result;
    result.reserve(text.size() * 2);

    for (size_t i = 0; i < text.size(); ++i)
    {
        char c = text[i];

        if (is_punctuation(c)){
            if (!result.empty() && result.back() == ' ')
                result.pop_back();

            result.push_back(c);

            if (i + 1 < text.size() && text[i + 1] != ' ')
                result.push_back(' ');
        }
        else{
            result.push_back(c);
        }
    }

    return result;
}