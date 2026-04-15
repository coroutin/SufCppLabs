//
// Created by Artyom Yukhnyov on 15.04.2026.
//

#include "Indexer.h"

Indexer::Indexer(double* data, int offset, int len) : data(data), offset(offset), len(len)
{
    if (data == nullptr)
        throw std::invalid_argument("data can`t be nullptr");
    if (offset < 0)
        throw std::invalid_argument("offset can`t be negative");
    if (len <= 0)
        throw std::invalid_argument("len can`t be negative");
}

double& Indexer::operator[](int i) {
    if (i < 0 || i >= len)
        throw std::out_of_range("index out of range");
    return data[offset + i];
}

double Indexer::operator[](int i) const {
    if (i < 0 || i >= len)
        throw std::out_of_range("index out of range");
    return data[offset + i];
}