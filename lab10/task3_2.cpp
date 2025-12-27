#include <cstring>
#include <string>

char* all_lower(const char* text)
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

std::string all_lower(std::string text)
{
    for (char& c : text)
    {
        unsigned char ch = static_cast<unsigned char>(c);

        if (std::isalpha(ch))
            c = static_cast<char>(std::tolower(ch));
    }

    return text;
}
