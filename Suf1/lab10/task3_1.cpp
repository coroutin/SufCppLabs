#include <cstring>
#include <string>

char* as_sentence(const char* txt) {
    static char res[5000];
    int n = strlen(txt);
    for (int i = 0; i < n; i++)
        res[i] = txt[i];
    if (n > 0 && isalpha(res[0]))
        res[0] = toupper(res[0]);
    for (int i = 0; i < n - 2; i++) {
        if ((res[i] == '.' || res[i] == '!' || res[i] == '?') && res[i+1] == ' ' && isalpha(res[i+2]))
            res[i+2] = toupper(res[i+2]);
    }
    res[n] = '\0';
    return res;
}

std::string as_sentence(std::string txt) {
    int n = txt.size();
    if (n > 0 && isalpha(txt[0]))
        txt[0] = toupper(txt[0]);
    for (int i = 0; i < n - 2; i++) {
        if ((txt[i] == '.' || txt[i] == '!' || txt[i] == '?') && txt[i+1] == ' ' && isalpha(txt[i+2]))
            txt[i+2] = toupper(txt[i+2]);
    }
    return txt;
}