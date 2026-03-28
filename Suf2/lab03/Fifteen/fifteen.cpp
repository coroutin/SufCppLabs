#include "../fifteen.h"
#include <chrono>
#include <ncurses.h>
#include <random>

std::mt19937 Field::mt_engine(std::chrono::steady_clock::now().time_since_epoch().count());

Field::Field(size_t const & size) {
    this->size = size;
    field = new int[size * size];
    generateStartField(size);
}

Field::~Field() {
    delete[] field;
}

void Field::generateStartField(size_t const & size) {
    zeroIndex = size * size - 1;
    for (int i = 0; i < (int)(size * size) - 1; i++) {
        field[i] = i + 1;
    }
    field[size * size - 1] = 0;
}

size_t Field::getSize() const {
    return size;
}

size_t Field::getZeroIndex() const {
    return zeroIndex;
}

std::vector<int> Field::getField() const {
    return std::vector<int>(field, field + size * size);
}

void Field::shiftUp() {
    if (zeroIndex >= size) {
        std::swap(field[zeroIndex], field[zeroIndex - size]);
        zeroIndex -= size;
    }
}

void Field::shiftDown() {
    if (zeroIndex < size * (size - 1)) {
        std::swap(field[zeroIndex], field[zeroIndex + size]);
        zeroIndex += size;
    }
}

void Field::shiftLeft() {
    if (zeroIndex % size != 0) {
        std::swap(field[zeroIndex], field[zeroIndex - 1]);
        zeroIndex -= 1;
    }
}

void Field::shiftRight() {
    if (zeroIndex % size != size - 1) {
        std::swap(field[zeroIndex], field[zeroIndex + 1]);
        zeroIndex += 1;
    }
}

void Field::start_field() {
    int s = 500;
    for (int i = 0; i < s; i++) {
        switch (rand() % 4) {
            case 0: shiftUp();    break;
            case 1: shiftDown();  break;
            case 2: shiftLeft();  break;
            case 3: shiftRight(); break;
        }
    }
}

int Field::rand() {
    static std::uniform_int_distribution<int> dist(0, RAND_MAX);
    return dist(mt_engine);
}

size_t getSize() {
    clear();
    mvprintw(LINES/2 - 6, COLS/2 - 15, "Fifteen game. Controls: WASD or arrows Q - quit");
    mvprintw(LINES/2 - 2, COLS/2 - 15, "Enter field size: ");
    echo();
    char input[10];
    getstr(input);
    noecho();

    size_t size = 4;

    int parsed = atoi(input);
    if (parsed >= 2 && parsed <= 8) {
        size = parsed;
        clear();
        refresh();
    } else {
        clear();
        refresh();
        napms(1000);
    }

    return size;
}