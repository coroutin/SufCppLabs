#pragma once
#include <stdexcept>
#include <string>

class Indexer {
private:
    double* data;
    int offset;
    int len;

public:
    Indexer(double* data, int offset, int len);

    // Геттеры
    int getOffset() const { return offset; }
    int getLen()    const { return len; }

    double& operator[](int i);

    double operator[](int i) const;
};