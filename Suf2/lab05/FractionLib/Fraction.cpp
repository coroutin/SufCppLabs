#include "Fraction.h"

int Fraction::gcd(int a, int b) {
    a = (a < 0) ? -a : a;
    b = (b < 0) ? -b : b;
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

Fraction::Fraction(int num, int den) {
    if (den == 0)
        throw std::invalid_argument("Denominator cannot be zero");

    if (den < 0) {
        num = -num;
        den = -den;
    }

    int g = gcd(num, den);
    numerator = num / g;
    denominator = den / g;
}

int Fraction::getNumerator() const {
    return numerator;
}

unsigned int Fraction::getDenominator() const {
    return denominator;
}

Fraction::Fraction(const std::string& str) {
    size_t slash = str.find('/');

    int num = std::stoi(str.substr(0, slash));
    int den = std::stoi(str.substr(slash + 1));

    *this = Fraction(num, den);
}

Fraction& Fraction::operator+=(const Fraction& other) {
    int g = gcd((int)denominator, (int)other.denominator);
    *this = Fraction(
        numerator * ((int)other.denominator / g) + other.numerator * ((int)denominator / g),
        (int)denominator / g * (int)other.denominator
    );
    return *this;
}

Fraction& Fraction::operator-=(const Fraction& other) {
    int g = gcd((int)denominator, (int)other.denominator);
    *this = Fraction(
        numerator * ((int)other.denominator / g) - other.numerator * ((int)denominator / g),
        (int)denominator / g * (int)other.denominator
    );
    return *this;
}

Fraction& Fraction::operator*=(const Fraction& other) {
    int g1 = gcd(numerator, (int)other.denominator);
    int g2 = gcd((int)denominator, other.numerator);
    std::cout << "g1=" << g1 << " g2=" << g2 << std::endl;
    std::cout << "num=" << (numerator/g1) << "*" << (other.numerator/g2)
              << " den=" << ((int)denominator/g2) << "*" << ((int)other.denominator/g1) << std::endl;
    *this = Fraction(
        (numerator / g1) * (other.numerator / g2),
        ((int)denominator / g2) * ((int)other.denominator / g1)
    );
    return *this;
}

Fraction& Fraction::operator/=(const Fraction& other) {
    if (other.numerator == 0)
        throw std::invalid_argument("Division by zero");
    *this = Fraction(
        numerator * (int)other.denominator,
        (int)denominator * other.numerator
    );
    return *this;
}

Fraction Fraction::operator-() const {
    return Fraction(-numerator, denominator);
}

Fraction Fraction::operator+(const Fraction& other) const {
    Fraction result = *this;
    return result += other;
}

Fraction Fraction::operator-(const Fraction& other) const {
    Fraction result = *this;
    return result -= other;
}

Fraction Fraction::operator*(const Fraction& other) const {
    Fraction result = *this;
    return result *= other;
}

Fraction Fraction::operator/(const Fraction& other) const {
    Fraction result = *this;
    return result /= other;
}

bool Fraction::operator==(const Fraction& other) const {
    return numerator == other.numerator && denominator == other.denominator;
}

bool Fraction::operator!=(const Fraction& other) const {
    return !(*this == other);
}

bool Fraction::operator<(const Fraction& other) const {
    return numerator * (int)other.denominator < other.numerator * (int)denominator;
}

bool Fraction::operator>(const Fraction& other) const {
    return other < *this;
}

bool Fraction::operator<=(const Fraction& other) const {
    return !(*this > other);
}

bool Fraction::operator>=(const Fraction& other) const {
    return !(*this < other);
}

std::ostream& operator<<(std::ostream& os, const Fraction& f) {
    os << f.numerator << "/" << f.denominator;
    return os;
}

std::istream& operator>>(std::istream& is, Fraction& f) {
    std::string str;
    is >> str;
    size_t slash = str.find('/');
    if (slash == std::string::npos)
        throw std::invalid_argument("Invalid format");
    f = Fraction(str);
    return is;
}

Fraction Fraction::pow(int n) const {
    std::cout << "pow called with " << n << std::endl;
    if (n < 0)
        return inverse().pow(-n);
    Fraction result(1);
    for (int i = 0; i < n; i++)
        result *= *this;
    return result;
}

Fraction Fraction::inverse() const {
    if (numerator == 0)
        throw std::invalid_argument("Zero fraction has no inverse");
    return Fraction((int)denominator, numerator);
}

Fraction Fraction::operator*(int n) const {
    return Fraction(numerator * n, (int)denominator);
}

Fraction operator*(int n, const Fraction& f) {
    return f * n;
}

Fraction::operator double() const {
    return (double)numerator / denominator;
}

Fraction::operator std::string() const {
    return std::to_string(numerator) + "/" + std::to_string(denominator);
}