#include <ncurses.h>
#include "fifteen.h"

#define COLOR_TILE   1
#define COLOR_EMPTY  2
#define COLOR_WIN    3

void drawField(WINDOW *win, const Field &f) {
    size_t size = f.getSize();
    std::vector<int> grid = f.getField();

    werase(win);

    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            int val = grid[i * size + j];
            int x = (int)j * 5;
            int y = (int)i * 3;

            if (val == 0) {
                wattron(win, COLOR_PAIR(COLOR_EMPTY));
                mvwprintw(win, y,     x, "     ");
                mvwprintw(win, y + 1, x, "     ");
                mvwprintw(win, y + 2, x, "     ");
                wattroff(win, COLOR_PAIR(COLOR_EMPTY));
            } else {
                wattron(win, COLOR_PAIR(COLOR_TILE) | A_BOLD);
                mvwprintw(win, y,     x, "%3d", val);
                wattroff(win, COLOR_PAIR(COLOR_TILE) | A_BOLD);
            }
        }
    }

    wrefresh(win);
}

bool isWin(const Field &f) {
    std::vector<int> grid = f.getField();
    size_t n = f.getSize();
    for (size_t i = 0; i < n * n - 1; i++) {
        if (grid[i] != (int)(i + 1)) return false;
    }
    return grid[n * n - 1] == 0;
}

void showWin(WINDOW *win, const Field &f) {
    size_t size = f.getSize();
    int cy = (int)(size);
    int cx = (int)(size);

    wattron(win, COLOR_PAIR(COLOR_WIN) | A_BOLD);
    mvwprintw(win, cy, cx, "You win!");

    wattroff(win, COLOR_PAIR(COLOR_WIN) | A_BOLD);

    wrefresh(win);
}

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

        if (isWin(game)) {
            won = true;
            showWin(win, game);
        }
    }

    delwin(win);
    endwin();
    return 0;
}