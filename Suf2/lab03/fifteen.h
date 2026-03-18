#pragma once

#include <vector>
#include <random>

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
};

size_t getSize();