#include "LinearEquation.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>
#include <random>
#include <cmath>

static constexpr double EPS = 1e-9;

// --- checkCompatible ---

void LinearEquation::checkCompatible(const LinearEquation& other) const {
    if (coefficients.size() != other.coefficients.size())
        throw std::invalid_argument("Уравнения имеют разное число переменных");
}

// --- Конструкторы ---

LinearEquation::LinearEquation(const std::vector<double>& all)
{
    if (all.size() < 2)
        throw std::invalid_argument("Нужно минимум 2 числа");
    coefficients = std::vector<double>(all.begin(), all.end() - 1);
    freeTerm = all.back();
}

LinearEquation::LinearEquation(const std::string& str)
{
    std::istringstream iss(str);
    double val;
    std::vector<double> all;
    while (iss >> val) all.push_back(val);

    if (all.size() < 2)
        throw std::invalid_argument("Строка должна содержать минимум 2 числа");

    coefficients = std::vector<double>(all.begin(), all.end() - 1);
    freeTerm = all.back();
}

LinearEquation::LinearEquation(const LinearEquation& other)
    : coefficients(other.coefficients), freeTerm(other.freeTerm) {}

// --- Оператор присваивания ---

LinearEquation& LinearEquation::operator=(const LinearEquation& other) {
    if (this != &other) {
        coefficients = other.coefficients;
        freeTerm = other.freeTerm;
    }
    return *this;
}

// --- Геттеры ---

int LinearEquation::getN() const { return static_cast<int>(coefficients.size()); }

double LinearEquation::getFreeTerm() const { return freeTerm; }

double LinearEquation::getCoefficient(int i) const {
    if (i < 0 || i >= getN())
        throw std::out_of_range("Индекс вне диапазона");
    return coefficients[i];
}

// --- fillRandom ---

void LinearEquation::fillRandom(double minVal, double maxVal) {
    std::mt19937 rng(std::random_device{}());
    std::uniform_real_distribution<double> dist(minVal, maxVal);
    for (auto& c : coefficients) c = dist(rng);
    freeTerm = dist(rng);
}

// --- Унарный минус ---

LinearEquation LinearEquation::operator-() const {
    std::vector<double> neg(coefficients.begin(), coefficients.end());
    for (auto& c : neg) c = -c;
    neg.push_back(-freeTerm);
    return LinearEquation(neg);
}

// --- += и -= ---

LinearEquation& LinearEquation::operator+=(const LinearEquation& other) {
    checkCompatible(other);
    for (size_t i = 0; i < coefficients.size(); ++i)
        coefficients[i] += other.coefficients[i];
    freeTerm += other.freeTerm;
    return *this;
}

LinearEquation& LinearEquation::operator-=(const LinearEquation& other) {
    checkCompatible(other);
    for (size_t i = 0; i < coefficients.size(); ++i)
        coefficients[i] -= other.coefficients[i];
    freeTerm -= other.freeTerm;
    return *this;
}

// --- Бинарные +, -, * ---

LinearEquation operator+(LinearEquation lhs, const LinearEquation& rhs) {
    lhs += rhs; return lhs;
}

LinearEquation operator-(LinearEquation lhs, const LinearEquation& rhs) {
    lhs -= rhs; return lhs;
}

LinearEquation operator*(LinearEquation lhs, double scalar) {
    for (auto& c : lhs.coefficients) c *= scalar;
    lhs.freeTerm *= scalar;
    return lhs;
}

LinearEquation operator*(double scalar, LinearEquation rhs) {
    return rhs * scalar;
}

// --- Сравнение (с допуском для double) ---

bool LinearEquation::operator==(const LinearEquation& other) const {
    if (coefficients.size() != other.coefficients.size()) return false;
    if (std::abs(freeTerm - other.freeTerm) > EPS) return false;
    for (size_t i = 0; i < coefficients.size(); ++i)
        if (std::abs(coefficients[i] - other.coefficients[i]) > EPS) return false;
    return true;
}

bool LinearEquation::operator!=(const LinearEquation& other) const {
    return !(*this == other);
}

// --- Оператор [] (индекс N обращается к freeTerm) ---

double& LinearEquation::operator[](int i) {
    if (i < 0 || i > getN()) throw std::out_of_range("Индекс вне диапазона");
    return i == getN() ? freeTerm : coefficients[i];
}

const double& LinearEquation::operator[](int i) const {
    if (i < 0 || i > getN()) throw std::out_of_range("Индекс вне диапазона");
    return i == getN() ? freeTerm : coefficients[i];
}

// --- Преобразование к vector<double> ---

LinearEquation::operator std::vector<double>() const {
    std::vector<double> result(coefficients);
    result.push_back(freeTerm);
    return result;
}

// --- << и >> ---

std::ostream& operator<<(std::ostream& os, const LinearEquation& eq) {
    for (int i = 0; i < eq.getN(); ++i) {
        if (i > 0 && eq.coefficients[i] >= 0) os << "+";
        os << eq.coefficients[i] << "*x" << (i + 1) << " ";
    }
    if (eq.freeTerm >= 0) os << "+";
    os << eq.freeTerm << " = 0";
    return os;
}

std::istream& operator>>(std::istream& is, LinearEquation& eq) {
    int n; is >> n;
    if (n <= 0) throw std::invalid_argument("n должно быть > 0");
    std::vector<double> coeffs(n);
    for (int i = 0; i < n; ++i) is >> coeffs[i];
    double free; is >> free;
    eq.coefficients = coeffs;
    eq.freeTerm = free;
    return is;
}