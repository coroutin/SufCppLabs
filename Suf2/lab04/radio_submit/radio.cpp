#include "radio.h"
#include <ncurses.h>
#include <string>

void drawVolumeBar(WINDOW* win, int y, int x, unsigned int vol, unsigned int maxVol) {
    mvwprintw(win, y, x, "");
    for (unsigned int i = 1; i <= maxVol; ++i) {
        if (i <= vol)
            waddch(win, ACS_BLOCK);
        else
            waddch(win, ACS_BULLET);
    }
    wprintw(win, "  %2u / %u", vol, maxVol);
}

void redraw(WINDOW* win, const Radio& radio) {
    werase(win);
    int W = getmaxx(win);

    // Рамка
    box(win, 0, 0);

    // Заголовок
    std::string title = " DOOMSDAY RADIO ";
    mvwprintw(win, 0, (W - (int)title.size()) / 2, "%s", title.c_str());

    // --- Станция ---
    mvwprintw(win, 2, 2, "STATION");

    wattron(win, COLOR_PAIR(1) | A_BOLD);
    mvwprintw(win, 4, 8, "> %s <", radio.getStationName());
    wattroff(win, COLOR_PAIR(1) | A_BOLD);

    // Кнопки << и >>

    wattron(win, COLOR_PAIR(1) | A_BOLD);
    wprintw(win, " %2u ", radio.getStation());
    wattroff(win, COLOR_PAIR(1) | A_BOLD);

    mvwhline(win, 6, 1, ACS_HLINE, W - 2);

    mvwprintw(win, 8, 2, "VOLUME");

    wattron(win, COLOR_PAIR(3));
    drawVolumeBar(win, 9, 8, radio.getVolume(), Radio::MAX_VOLUME);
    mvwprintw(win, 9, 8 + Radio::MAX_VOLUME, "");
    wattroff(win, COLOR_PAIR(3));

    // Разделитель
    mvwhline(win, 11, 1, ACS_HLINE, W - 2);

    mvwprintw(win, 12, 2, "CONTROLS");
    wattron(win, A_DIM);
    mvwprintw(win, 13, 4, "<- ->  station      ^ v  volume      Q  quit");
    wattroff(win, A_DIM);

    wrefresh(win);
}