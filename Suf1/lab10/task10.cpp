#include <cstring>
#include <string>

char* replace_substr(const char* text, const char* c, const char* str)
{
    if (!text || !c || !str)
    {
        char* empty = new char[1]{ '\0' };
        return empty;
    }

    size_t text_len = std::strlen(text);
    size_t c_len    = std::strlen(c);
    size_t str_len  = std::strlen(str);

    if (c_len == 0)
    {
        char* copy = new char[text_len + 1];
        std::strcpy(copy, text);
        return copy;
    }

    size_t count = 0;
    for (const char* p = text; (p = std::strstr(p, c)); p += c_len)
        ++count;

    size_t new_len = text_len + count * (str_len - c_len);
    char* result = new char[new_len + 1];

    const char* src = text;
    char* dst = result;

    while (const char* pos = std::strstr(src, c))
    {
        size_t chunk = pos - src;
        std::memcpy(dst, src, chunk);
        dst += chunk;

        std::memcpy(dst, str, str_len);
        dst += str_len;

        src = pos + c_len;
    }

    std::strcpy(dst, src);
    return result;
}

std::string replace_substr(std::string text, std::string c, std::string str)
{
    if (c.empty())
        return text;

    std::string result;
    size_t pos = 0;

    while (true)
    {
        size_t found = text.find(c, pos);
        if (found == std::string::npos)
        {
            result += text.substr(pos);
            break;
        }

        result += text.substr(pos, found - pos);
        result += str;
        pos = found + c.length();
    }

    return result;
}