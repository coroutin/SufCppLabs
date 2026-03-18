#include "radio.h"
#include <iostream>
#include <termios.h>
#include <unistd.h>

char getch() {
    struct termios oldt, newt;
    char ch;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

int main() {
    Radio radio;

    std::cout << "Управление: W/S - Увеличение/уменьшение громкости, A/D - Переключение станций, Q - Выход" << std::endl;
    radio.print();

    char key;
    while ((key = getch()) != 'q' && key != 'Q') {
        bool changed = true;
        switch (key) {
            case 'w': case 'W': radio.incVolume();        break;
            case 's': case 'S': radio.decVolume();        break;
            case 'd': case 'D': radio.nextStation();      break;
            case 'a': case 'A': radio.previousStation();  break;
            default: changed = false; break;
        }
        if (changed) {
            radio.print();
        }
    }
    return 0;
}