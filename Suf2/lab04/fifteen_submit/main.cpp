#include <ncurses.h>
#include "fifteen.h"

int main() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);

    start_color();
    init_pair(COLOR_TILE,  COLOR_WHITE, COLOR_BLUE);
    init_pair(COLOR_EMPTY, COLOR_BLACK, COLOR_BLACK);
    init_pair(COLOR_WIN,   COLOR_BLACK, COLOR_GREEN);

    const size_t SIZE = getSize();
    int winH = (int)(SIZE * 3);
    int winW = (int)(SIZE * 5);
    int startY = (LINES - winH) / 2;
    int startX = (COLS  - winW) / 2;

    WINDOW *win = newwin(winH, winW, startY, startX);

    Field game(SIZE);
    Field win_field(SIZE);
    game.start_field();
    bool won = false;

    drawField(win, game);

    int ch;
    while ((ch = getch()) != 'q' && ch != 'Q') {
        if (won) continue;

        switch (ch) {
            case KEY_UP:    case 'w': case 'W': game.shiftUp();    break;
            case KEY_DOWN:  case 's': case 'S': game.shiftDown();  break;
            case KEY_LEFT:  case 'a': case 'A': game.shiftLeft();  break;
            case KEY_RIGHT: case 'd': case 'D': game.shiftRight(); break;
            default: continue;
        }

        drawField(win, game);

        if (game == win_field) {
            won = true;
            showWin(win, game);
        }
    }

    delwin(win);
    endwin();
    return 0;
}