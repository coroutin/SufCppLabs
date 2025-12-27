#include <cstring>
#include <string>

char* get_unique_symbol(const char* text)
{
    if (text == nullptr)
    {
        char* empty = new char[1]{ '\0' };
        return empty;
    }

    bool used[256] = { false };

    size_t len = std::strlen(text);
    char* result = new char[len + 1];

    size_t pos = 0;

    for (size_t i = 0; i < len; ++i)
    {
        unsigned char ch = static_cast<unsigned char>(text[i]);

        if (!used[ch])
        {
            used[ch] = true;
            result[pos++] = text[i];
        }
    }

    result[pos] = '\0';
    return result;
}

std::string get_unique_symbol(std::string text)
{
    bool used[256] = { false };
    std::string result;

    for (char c : text)
    {
        unsigned char ch = static_cast<unsigned char>(c);

        if (!used[ch])
        {
            used[ch] = true;
            result.push_back(c);
        }
    }

    return result;
}