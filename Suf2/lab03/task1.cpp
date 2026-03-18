#include <iomanip>
#include <vector>
#include <algorithm>

class Field {
private:
    unsigned int size;
    unsigned int zeroIndex;
    int *field;

    Field(Field const &);
    Field & operator=(Field const &);

public:
    Field(size_t const & size = 4) {
        this->size = size;
        field = new int[size * size];
        generateStartField(size);
    }

    ~Field() { delete[] field; }

    void generateStartField(size_t const & size = 4) {
        zeroIndex = size * size - 1;
        for (int i = 0; i < size * size - 1; i++) {
            field[i] = i + 1;
        }
        field[size * size - 1] = 0;
    }

    size_t getSize() const { return size; }
    size_t getZeroIndex() const { return zeroIndex; }

    std::vector<int> getField() const {
        std::vector<int> result(field, field + size * size);
        return result;
    }

    void shiftUp() {
        if (zeroIndex >= size) {
            std::swap(field[zeroIndex], field[zeroIndex - size]);
            zeroIndex -= size;
        }
    }

    void shiftDown() {
        if (zeroIndex < size * (size - 1)) {
            std::swap(field[zeroIndex], field[zeroIndex + size]);
            zeroIndex += size;
        }
    }

    void shiftLeft() {
        if (zeroIndex % size != 0) {
            std::swap(field[zeroIndex], field[zeroIndex - 1]);
            zeroIndex -= 1;
        }
    }

    void shiftRight() {
        if (zeroIndex % size != size - 1) {
            std::swap(field[zeroIndex], field[zeroIndex + 1]);
            zeroIndex += 1;
        }
    }
};