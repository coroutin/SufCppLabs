#include <ncurses.h>

int main() {
    // 1. Инициализация
    initscr();            // инициализировать ncurses
    cbreak();             // символы передаются сразу (без Enter)
    noecho();             // не отображать вводимые символы
    keypad(stdscr, TRUE); // включить специальные клавиши (стрелки и т.д.)
    curs_set(0);          // скрыть курсор (0=скрыт, 1=обычный, 2=яркий)

    // 2. Ваша логика...
    mvprintw(10, 20, "Hello, ncurses!");
    refresh();
    getch();

    // 3. Завершение — ОБЯЗАТЕЛЬНО
    endwin();
    return 0;
}