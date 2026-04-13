#pragma once
#include <string>
#include <iostream>
#include <stdexcept>

//----- Класс несократимой рациональной дроби -----//

class Fraction {
private:
    int numerator;
    unsigned int denominator;

    // Алгоритм Евклида
    static int gcd(int a, int b);

public:
    /**
     * @brief Основной конструктор
     * @param numerator Числитель (по умолчанию 0)
     * @param denominator Знаменатель (по умолчанию 1)
     * @throws std::invalid_argument если знаменатель равен нулю
     */
    Fraction(int numerator = 0, int denominator = 1);

    /**
     * @brief Конструктор из строки вида "a/b".
     * @param str Строка формата "a/b", где a и b — целые числа
     * @throws std::invalid_argument если формат строки некорректен
     */
    Fraction(const std::string& str);

    // Геттеры числитель/знаменатель
    int getNumerator() const;
    unsigned int getDenominator() const;

    // Операторы присваивания с арифметикой
    Fraction& operator+=(const Fraction& other);
    Fraction& operator-=(const Fraction& other);
    Fraction& operator*=(const Fraction& other);
    Fraction& operator/=(const Fraction& other);

    // Унарный минус
    Fraction operator-() const;

    // Бинарные арифметические операторы
    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    Fraction operator/(const Fraction& other) const;

    // Операторы сравнения
    bool operator==(const Fraction& other) const;
    bool operator!=(const Fraction& other) const;
    bool operator<(const Fraction& other) const;
    bool operator>(const Fraction& other) const;
    bool operator<=(const Fraction& other) const;
    bool operator>=(const Fraction& other) const;

    // Ввод/вывод дроби в поток
    friend std::ostream& operator<<(std::ostream& os, const Fraction& f);
    friend std::istream& operator>>(std::istream& is, Fraction& f);

    // Возведение в целую степень
    Fraction pow(int n) const;

    // Обратная дробь
    Fraction inverse() const;

    // Умножение на целое число справа/слева
    Fraction operator*(int n) const;
    friend Fraction operator*(int n, const Fraction& f);

    // Операторы неявного приведения к double и явного к строке
    operator double() const;
    explicit operator std::string() const;
};