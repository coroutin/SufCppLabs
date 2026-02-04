#include <cstring>
#include <string>

char* replace_substr(const char* text, char c, const char* str)
{
    if (!text || !str)
    {
        char* empty = new char[1]{ '\0' };
        return empty;
    }

    size_t text_len = std::strlen(text);
    size_t sub_len  = std::strlen(str);

    size_t count = 0;
    for (size_t i = 0; i < text_len; ++i)
        if (text[i] == c)
            ++count;

    size_t new_len = text_len + count * (sub_len - 1);
    char* result = new char[new_len + 1];

    size_t pos = 0;
    for (size_t i = 0; i < text_len; ++i)
    {
        if (text[i] == c)
        {
            std::strcpy(result + pos, str);
            pos += sub_len;
        }
        else
        {
            result[pos++] = text[i];
        }
    }

    result[pos] = '\0';
    return result;
}

std::string replace_substr(std::string text, char c, std::string str)
{
    std::string result;
    result.reserve(text.size());

    for (char ch : text)
    {
        if (ch == c)
            result += str;
        else
            result += ch;
    }

    return result;
}
