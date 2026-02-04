#include <cstring>
#include <string>

bool is_palindrome(const char* text)
{
    if (!text)
        return false;

    size_t left = 0;
    size_t right = std::strlen(text);

    if (right == 0)
        return true;

    right--;

    while (left < right)
    {
        if (text[left] != text[right])
            return false;

        ++left;
        --right;
    }

    return true;
}

bool is_palindrome(std::string text)
{
    size_t left = 0;
    size_t right = text.length();

    if (right == 0)
        return true;

    right--;

    while (left < right)
    {
        if (text[left] != text[right])
            return false;

        ++left;
        --right;
    }

    return true;
}