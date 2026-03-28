#pragma once

#include <ncurses.h>
#include <vector>
#include <random>

#define COLOR_TILE   1
#define COLOR_EMPTY  2
#define COLOR_WIN    3

class Field {
private:
    unsigned int size;
    unsigned int zeroIndex;
    int *field;
    static std::mt19937 mt_engine;

    Field(Field const &size);
    Field & operator=(Field const &);

public:

    Field(size_t const &size);

    ~Field();

    void generateStartField(size_t const & size = 4);

    void start_field();

    size_t getSize() const;
    size_t getZeroIndex() const;

    std::vector<int> getField() const;

    void shiftUp();
    void shiftDown();
    void shiftLeft();
    void shiftRight();
    
    static int rand();
    friend bool operator==(Field const& a, Field const& b);
    friend bool operator!=(Field const& a, Field const& b);
};

size_t getSize();

void drawField(WINDOW *win, const Field &f);
void showWin(WINDOW *win, const Field &f);