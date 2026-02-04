#include <cstring>
#include <string>

void get_from_absolute_path(const char* text, char*& filename, char*& extension)
{
    filename = nullptr;
    extension = nullptr;

    if (!text)
        return;

    const char* last_slash1 = strrchr(text, '\\');
    const char* last_slash2 = strrchr(text, '/');

    const char* file_start = text;
    if (last_slash1 && last_slash2)
        file_start = (last_slash1 > last_slash2 ? last_slash1 : last_slash2) + 1;
    else if (last_slash1)
        file_start = last_slash1 + 1;
    else if (last_slash2)
        file_start = last_slash2 + 1;

    const char* dot = strrchr(file_start, '.');

    size_t fname_len = dot ? (dot - file_start) : strlen(file_start);
    filename = new char[fname_len + 1];
    strncpy(filename, file_start, fname_len);
    filename[fname_len] = '\0';

    if (dot)
    {
        size_t ext_len = strlen(dot + 1);
        extension = new char[ext_len + 1];
        strcpy(extension, dot + 1);
    }
    else
    {
        extension = new char[1]{ '\0' };
    }
}

void get_from_absolute_path(std::string text, std::string& filename, std::string& extension) {
    filename.clear();
    extension.clear();

    size_t pos1 = text.find_last_of('\\');
    size_t pos2 = text.find_last_of('/');

    size_t file_pos;
    if (pos1 == std::string::npos && pos2 == std::string::npos) {file_pos = 0;}
    else if (pos1 == std::string::npos) {file_pos = pos2 + 1;}
    else if (pos2 == std::string::npos) {file_pos = pos1 + 1;}
    else {file_pos = std::max(pos1, pos2) + 1;}

    std::string file = text.substr(file_pos);

    size_t dot = file.find_last_of('.');

    if (dot != std::string::npos){
        filename = file.substr(0, dot);
        extension = file.substr(dot + 1);
    }
    else{
        filename = file;
        extension = "";
    }
}