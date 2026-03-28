#include "radio.h"
#include <ncurses.h>

int main() {
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(0);

    if (has_colors()) {
        start_color();
        init_pair(1, COLOR_YELLOW,  COLOR_BLACK); // станция
        init_pair(2, COLOR_WHITE,   COLOR_BLACK); // стрелки
        init_pair(3, COLOR_CYAN,    COLOR_BLACK); // громкость
    }

    int rows, cols;
    getmaxyx(stdscr, rows, cols);

    int winH = 16, winW = 54;
    int y0 = (rows - winH) / 2;
    int x0 = (cols - winW) / 2;

    WINDOW* win = newwin(winH, winW, y0, x0);

    Radio radio;
    redraw(win, radio);

    int ch;
    while ((ch = getch()) != 'q' && ch != 'Q') {
        switch (ch) {
            case KEY_RIGHT: ++radio; break;   // префиксный ++
            case KEY_LEFT:  --radio; break;   // префиксный --
            case KEY_UP:    radio.incVolume(); break;
            case KEY_DOWN:  radio.decVolume(); break;
        }
        redraw(win, radio);
    }

    delwin(win);
    endwin();
    return 0;
}