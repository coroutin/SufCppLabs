#pragma once
#include <iosfwd>
#include <string>
#include <vector>

class LinearEquation {
private:
    std::vector<double> coefficients;
    double freeTerm;

    void checkCompatible(const LinearEquation& other) const;

public:
    // --- Конструкторы ---

    explicit LinearEquation(const std::vector<double>& all);

    explicit LinearEquation(const std::string& str);

    LinearEquation(const LinearEquation& other);

    // --- Оператор присваивания ---

    LinearEquation& operator=(const LinearEquation& other);

    // --- Геттеры ---

    int getN() const;

    double getFreeTerm() const;

    double getCoefficient(int i) const;

    // --- fillRandom ---

    void fillRandom(double minVal = -10.0, double maxVal = 10.0);

    // --- Унарный минус ---

    LinearEquation operator-() const;

    // --- += и -= ---

    LinearEquation& operator+=(const LinearEquation& other);

    LinearEquation& operator-=(const LinearEquation& other);

    // --- Бинарные +, -, * ---

    friend LinearEquation operator+(LinearEquation lhs, const LinearEquation& rhs);

    friend LinearEquation operator-(LinearEquation lhs, const LinearEquation& rhs);

    friend LinearEquation operator*(LinearEquation lhs, double scalar);

    friend LinearEquation operator*(double scalar, LinearEquation rhs);

    // --- Сравнение ---

    bool operator==(const LinearEquation& other) const;

    bool operator!=(const LinearEquation& other) const;

    // --- Оператор [] ---

    double& operator[](int i);

    const double& operator[](int i) const;

    // --- Преобразование к vector<double> ---

    operator std::vector<double>() const;

    // --- << и >> ---

    friend std::ostream& operator<<(std::ostream& os, const LinearEquation& eq);

    friend std::istream& operator>>(std::istream& is, LinearEquation& eq);
};
