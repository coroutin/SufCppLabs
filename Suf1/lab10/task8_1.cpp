#include <cstring>
#include <string>

bool is_punct_or_space(char c)
{
    return c == ' ' || c == '.' || c == ',' || c == '!' || c == '?';
}

char* text_transformation(const char* text) {
    if (!text)
    {
        char* empty = new char[1]{ '\0' };
        return empty;
    }

    size_t len = std::strlen(text);
    char* result = new char[len + 1];
    size_t pos = 0;

    for (size_t i = 0; i < len; ++i)
    {
        char c = text[i];
        if (!is_punct_or_space(c))
        {
            result[pos++] = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
        }
    }

    result[pos] = '\0';
    return result;
}

std::string text_transformation(std::string text)
{
    std::string result;
    result.reserve(text.size());

    for (char c : text)
    {
        if (!is_punct_or_space(c))
        {
            result.push_back(static_cast<char>(std::tolower(static_cast<unsigned char>(c))));
        }
    }

    return result;
}