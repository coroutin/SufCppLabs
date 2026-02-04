#include <cstring>
#include <string>

char* delete_spaces(const char* text)
{
    if (!text)
    {
        char* empty = new char[1]{ '\0' };
        return empty;
    }

    size_t len = std::strlen(text);
    char* result = new char[len + 1];
    size_t pos = 0;

    bool last_was_space = false;

    for (size_t i = 0; i < len; ++i)
    {
        char c = text[i];

        if (c != ' ')
        {
            result[pos++] = c;
            last_was_space = false;
        }
        else
        {
            if (!last_was_space)
            {
                result[pos++] = ' ';
                last_was_space = true;
            }
        }
    }

    result[pos] = '\0';
    return result;
}

std::string delete_spaces(std::string text)
{
    std::string result;
    result.reserve(text.size());

    bool last_was_space = false;

    for (char c : text)
    {
        if (c != ' ')
        {
            result.push_back(c);
            last_was_space = false;
        }
        else
        {
            if (!last_was_space)
            {
                result.push_back(' ');
                last_was_space = true;
            }
        }
    }

    return result;
}