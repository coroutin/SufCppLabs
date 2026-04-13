#include <gtest/gtest.h>
#include <sstream>
#include "Fraction.h"

// Конструктор без аргументов создаёт дробь 0/1
TEST(FractionTest, TestConstructorWithoutArgs) {
    Fraction f;
    EXPECT_EQ(0, f.getNumerator());
    EXPECT_EQ(1, f.getDenominator());
}

// Конструктор с одним аргументом создаёт дробь n/1
TEST(FractionTest, TestConstructorWithOneArg) {
    Fraction f(-5);
    EXPECT_EQ(-5, f.getNumerator());
    EXPECT_EQ(1, f.getDenominator());
}

// Знак переносится в числитель если знаменатель отрицательный
TEST(FractionTest, TestConstructorWithTwoArgs) {
    Fraction f(2, -5);
    EXPECT_EQ(-2, f.getNumerator());
    EXPECT_EQ(5, f.getDenominator());
}

// Дробь автоматически сокращается при создании
TEST(FractionTest, TestFractionReduction) {
    Fraction f(200, 400);
    EXPECT_EQ(1, f.getNumerator());
    EXPECT_EQ(2, f.getDenominator());
}

// Нулевой знаменатель вызывает исключение invalid_argument
TEST(FractionTest, TestConstructorException) {
    EXPECT_THROW(Fraction(20, 0), std::invalid_argument);
}

// Конструктор из строки "a/b" создаёт корректную дробь
TEST(FractionTest, TestStringConstructorSimple) {
    Fraction f("3/4");
    EXPECT_EQ(3, f.getNumerator());
    EXPECT_EQ(4, f.getDenominator());
}

// Конструктор из строки сокращает дробь
TEST(FractionTest, TestStringConstructorReduction) {
    Fraction f("6/4");
    EXPECT_EQ(3, f.getNumerator());
    EXPECT_EQ(2, f.getDenominator());
}

// Конструктор из строки корректно обрабатывает отрицательный числитель
TEST(FractionTest, TestStringConstructorNegative) {
    Fraction f("-3/4");
    EXPECT_EQ(-3, f.getNumerator());
    EXPECT_EQ(4, f.getDenominator());
}

// 1/2 += 1/3 = 5/6
TEST(FractionTest, TestPlusEquals) {
    Fraction f(1, 2);
    f += Fraction(1, 3);
    EXPECT_EQ(5, f.getNumerator());
    EXPECT_EQ(6, f.getDenominator());
}

// 3/4 -= 1/4 = 1/2
TEST(FractionTest, TestMinusEquals) {
    Fraction f(3, 4);
    f -= Fraction(1, 4);
    EXPECT_EQ(1, f.getNumerator());
    EXPECT_EQ(2, f.getDenominator());
}

// 2/3 *= 3/4 = 1/2
TEST(FractionTest, TestMultiplyEquals) {
    Fraction f(2, 3);
    f *= Fraction(3, 4);
    EXPECT_EQ(1, f.getNumerator());
    EXPECT_EQ(2, f.getDenominator());
}

// 1/2 /= 3/4 = 2/3
TEST(FractionTest, TestDivideEquals) {
    Fraction f(1, 2);
    f /= Fraction(3, 4);
    EXPECT_EQ(2, f.getNumerator());
    EXPECT_EQ(3, f.getDenominator());
}

// Деление на нулевую дробь вызывает исключение invalid_argument
TEST(FractionTest, TestDivideByZeroException) {
    Fraction f(1, 2);
    EXPECT_THROW(f /= Fraction(0), std::invalid_argument);
}

// Унарный минус меняет знак числителя
TEST(FractionTest, TestUnaryMinus) {
    Fraction f(3, 4);
    Fraction neg = -f;
    EXPECT_EQ(-3, neg.getNumerator());
    EXPECT_EQ(4, neg.getDenominator());
}

// Унарный минус от отрицательной даёт положительную
TEST(FractionTest, TestUnaryMinusNegative) {
    Fraction f(-3, 4);
    Fraction neg = -f;
    EXPECT_EQ(3, neg.getNumerator());
    EXPECT_EQ(4, neg.getDenominator());
}

// 1/2 + 1/3 = 5/6
TEST(FractionTest, TestPlus) {
    Fraction c = Fraction(1, 2) + Fraction(1, 3);
    EXPECT_EQ(5, c.getNumerator());
    EXPECT_EQ(6, c.getDenominator());
}

// 3/4 - 1/4 = 1/2
TEST(FractionTest, TestMinus) {
    Fraction c = Fraction(3, 4) - Fraction(1, 4);
    EXPECT_EQ(1, c.getNumerator());
    EXPECT_EQ(2, c.getDenominator());
}

// 2/3 * 3/4 = 1/2
TEST(FractionTest, TestMultiply) {
    Fraction c = Fraction(2, 3) * Fraction(3, 4);
    EXPECT_EQ(1, c.getNumerator());
    EXPECT_EQ(2, c.getDenominator());
}

// 1/2 / 3/4 = 2/3
TEST(FractionTest, TestDivide) {
    Fraction c = Fraction(1, 2) / Fraction(3, 4);
    EXPECT_EQ(2, c.getNumerator());
    EXPECT_EQ(3, c.getDenominator());
}

// Деление на нулевую дробь вызывает исключение invalid_argument
TEST(FractionTest, TestDivideByZero) {
    EXPECT_THROW(Fraction(1, 2) / Fraction(0), std::invalid_argument);
}

// Равные дроби (в том числе несокращённые) считаются равными
TEST(FractionTest, TestEqual) {
    EXPECT_TRUE(Fraction(1, 2) == Fraction(2, 4));
    EXPECT_FALSE(Fraction(1, 2) == Fraction(1, 3));
}

// Неравные дроби определяются корректно
TEST(FractionTest, TestNotEqual) {
    EXPECT_TRUE(Fraction(1, 2) != Fraction(1, 3));
    EXPECT_FALSE(Fraction(1, 2) != Fraction(2, 4));
}

// 1/3 < 1/2
TEST(FractionTest, TestLess) {
    EXPECT_TRUE(Fraction(1, 3) < Fraction(1, 2));
    EXPECT_FALSE(Fraction(1, 2) < Fraction(1, 3));
}

// 1/2 > 1/3
TEST(FractionTest, TestGreater) {
    EXPECT_TRUE(Fraction(1, 2) > Fraction(1, 3));
    EXPECT_FALSE(Fraction(1, 3) > Fraction(1, 2));
}

// <= работает для равных и меньших дробей
TEST(FractionTest, TestLessOrEqual) {
    EXPECT_TRUE(Fraction(1, 2) <= Fraction(1, 2));
    EXPECT_TRUE(Fraction(1, 3) <= Fraction(1, 2));
    EXPECT_FALSE(Fraction(1, 2) <= Fraction(1, 3));
}

// >= работает для равных и больших дробей
TEST(FractionTest, TestGreaterOrEqual) {
    EXPECT_TRUE(Fraction(1, 2) >= Fraction(1, 2));
    EXPECT_TRUE(Fraction(1, 2) >= Fraction(1, 3));
    EXPECT_FALSE(Fraction(1, 3) >= Fraction(1, 2));
}

// Вывод дроби в поток даёт строку формата "a/b"
TEST(FractionTest, TestOutput) {
    std::ostringstream oss;
    oss << Fraction(3, 4);
    EXPECT_EQ("3/4", oss.str());
}

// Ввод дроби из потока корректно парсит строку "a/b"
TEST(FractionTest, TestInput) {
    Fraction f;
    std::istringstream iss("2/5");
    iss >> f;
    EXPECT_EQ(2, f.getNumerator());
    EXPECT_EQ(5, f.getDenominator());
}

TEST(FractionTest, TestValidInput) {
    Fraction f;
    std::istringstream iss("25");
    EXPECT_THROW(iss >> f, std::invalid_argument);
}

// (2/3)^3 = 8/27
TEST(FractionTest, TestPow) {
    Fraction result = Fraction(2, 3).pow(3);
    EXPECT_EQ(8, result.getNumerator());
    EXPECT_EQ(27, result.getDenominator());
}

// Любая дробь в степени 0 равна 1/1
TEST(FractionTest, TestPowZero) {
    Fraction result = Fraction(2, 3).pow(0);
    EXPECT_EQ(1, result.getNumerator());
    EXPECT_EQ(1, result.getDenominator());
}

// Обратная к 3/4 равна 4/3
TEST(FractionTest, TestInverse) {
    Fraction result = Fraction(3, 4).inverse();
    EXPECT_EQ(4, result.getNumerator());
    EXPECT_EQ(3, result.getDenominator());
}

// Обратная к отрицательной -2/5 равна -5/2
TEST(FractionTest, TestInverseNegative) {
    Fraction result = Fraction(-2, 5).inverse();
    EXPECT_EQ(-5, result.getNumerator());
    EXPECT_EQ(2, result.getDenominator());
}

// Обратная к нулевой дроби вызывает исключение
TEST(FractionTest, TestInverseZero) {
    EXPECT_THROW(Fraction(0).inverse(), std::invalid_argument);
}

// 1/2 * 3 = 3/2
TEST(FractionTest, TestMultiplyByIntRight) {
    Fraction result = Fraction(1, 2) * 3;
    EXPECT_EQ(3, result.getNumerator());
    EXPECT_EQ(2, result.getDenominator());
}

// 3 * 1/2 = 3/2
TEST(FractionTest, TestMultiplyByIntLeft) {
    Fraction result = 3 * Fraction(1, 2);
    EXPECT_EQ(3, result.getNumerator());
    EXPECT_EQ(2, result.getDenominator());
}

// 2/3 * 3 = 2/1
TEST(FractionTest, TestMultiplyByIntReduction) {
    Fraction result = Fraction(2, 3) * 3;
    EXPECT_EQ(2, result.getNumerator());
    EXPECT_EQ(1, result.getDenominator());
}

// (2/3)^(-2) = 9/4
TEST(FractionTest, TestPowNegative) {
    Fraction result = Fraction(2, 3).pow(-2);
    EXPECT_EQ(9, result.getNumerator());
    EXPECT_EQ(4, result.getDenominator());
}

// Возведение нуля в отрицательную степень вызывает исключение
TEST(FractionTest, TestPowNegativeZero) {
    EXPECT_THROW(Fraction(0).pow(-1), std::invalid_argument);
}

// Неявное приведение к double: 1/2 = 0.5
TEST(FractionTest, TestToDouble) {
    double result = Fraction(1, 2);
    EXPECT_DOUBLE_EQ(0.5, result);
}

// Отрицательная дробь: -1/4 = -0.25
TEST(FractionTest, TestToDoubleNegative) {
    double result = Fraction(-1, 4);
    EXPECT_DOUBLE_EQ(-0.25, result);
}

// Явное приведение к строке даёт "a/b"
TEST(FractionTest, TestToString) {
    std::string result = (std::string)Fraction(3, 4);
    EXPECT_EQ("3/4", result);
}

// Явное приведение отрицательной дроби к строке
TEST(FractionTest, TestToStringNegative) {
    std::string result = (std::string)Fraction(-3, 4);
    EXPECT_EQ("-3/4", result);
}

// Сложение дробей с большими знаменателями не вызывает переполнения
TEST(FractionTest, TestOverflowAdd) {
    Fraction a(1, 46341);
    Fraction b(1, 46341);
    Fraction result = a + b;
    EXPECT_EQ(2, result.getNumerator());
    EXPECT_EQ(46341, result.getDenominator());
}

// Умножение дробей с большими числами не вызывает переполнения
TEST(FractionTest, TestOverflowMultiply) {
    Fraction a(2, 46341);
    Fraction b(46341, 4);
    Fraction result = a * b;
    EXPECT_EQ(1, result.getNumerator());
    EXPECT_EQ(2, result.getDenominator());
}