#include <cstring>
#include <string>

char* trim(const char* text)
{
    if (!text)
    {
        char* empty = new char[1]{ '\0' };
        return empty;
    }

    const char* start = text;
    while (*start && std::isspace(static_cast<unsigned char>(*start)))
        ++start;

    const char* end = text + std::strlen(text) - 1;
    while (end >= start && std::isspace(static_cast<unsigned char>(*end)))
        --end;

    size_t len = (end >= start) ? (end - start + 1) : 0;
    char* result = new char[len + 1];

    if (len > 0)
        std::strncpy(result, start, len);

    result[len] = '\0';
    return result;
}

std::string trim(std::string text)
{
    size_t start = 0;
    while (start < text.length() && std::isspace(static_cast<unsigned char>(text[start])))
        ++start;

    if (start == text.length())
        return "";

    size_t end = text.length() - 1;
    while (end > start && std::isspace(static_cast<unsigned char>(text[end])))
        --end;

    return text.substr(start, end - start + 1);
}