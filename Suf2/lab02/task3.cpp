class Field {
private:
    unsigned int size;
    unsigned int zeroIndex;
    int *field;

public:
    Field(size_t const & size = 4) {
        this->size = size;
        zeroIndex = size * size - 1;

        field = new int[size * size];

        for (int i = 0; i < size * size - 1; i++) {
            field[i] = i + 1;
        }

        field[size * size - 1] = 0;
    }

    ~Field() {delete[] field;}

    size_t getSize() const {
        return size;
    }

    size_t getZeroIndex() const {
        return zeroIndex;
    }

    std::vector<int> getField() const {
        std::vector<int> result(field, field + size * size);
        return result;
    }
};