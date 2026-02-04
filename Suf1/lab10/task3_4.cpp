#include <cstring>
#include <string>

char* start_with_upper(const char* text)
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

std::string start_with_upper(std::string text)
{
    bool new_word = true;

    for (char& c : text)
    {
        unsigned char ch = static_cast<unsigned char>(c);

        if (std::isalpha(ch))
        {
            if (new_word)
            {
                c = static_cast<char>(std::toupper(ch));
                new_word = false;
            }
            else
            {
                c = static_cast<char>(std::tolower(ch));
            }
        }
        else
        {
            new_word = (c == ' ');
        }
    }

    return text;
}