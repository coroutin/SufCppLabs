#include <gtest/gtest.h>
#include <sstream>
#include "LinearEquation.h"

// Вспомогательный макрос: конструируем из вектора {coeffs..., free}
#define EQ(...) LinearEquation(std::vector<double>{__VA_ARGS__})

// --- Конструкторы ---

// Конструктор из вектора создаёт уравнение с нужными коэффициентами
TEST(LinearEquationTest, ConstructorFromVector) {
    LinearEquation eq(std::vector<double>{2.0, -3.0, 1.0, 5.0});
    EXPECT_EQ(3, eq.getN());
    EXPECT_DOUBLE_EQ(2.0,  eq.getCoefficient(0));
    EXPECT_DOUBLE_EQ(-3.0, eq.getCoefficient(1));
    EXPECT_DOUBLE_EQ(1.0,  eq.getCoefficient(2));
    EXPECT_DOUBLE_EQ(5.0,  eq.getFreeTerm());
}

// Конструктор из строки: числа разделены пробелами, последнее — свободный член
TEST(LinearEquationTest, ConstructorFromString) {
    LinearEquation eq(std::string("2.0 -3.0 1.0 5.0"));
    EXPECT_EQ(3, eq.getN());
    EXPECT_DOUBLE_EQ(2.0,  eq.getCoefficient(0));
    EXPECT_DOUBLE_EQ(-3.0, eq.getCoefficient(1));
    EXPECT_DOUBLE_EQ(1.0,  eq.getCoefficient(2));
    EXPECT_DOUBLE_EQ(5.0,  eq.getFreeTerm());
}

// Оба конструктора с одинаковыми данными дают равные уравнения
TEST(LinearEquationTest, BothConstructorsEqual) {
    LinearEquation v(std::vector<double>{2.0, -3.0, 1.0, 5.0});
    LinearEquation s(std::string("2.0 -3.0 1.0 5.0"));
    EXPECT_EQ(v, s);
}

// Конструктор из вектора менее чем из 2 элементов бросает invalid_argument
TEST(LinearEquationTest, ConstructorVectorTooShortThrows) {
    EXPECT_THROW(LinearEquation(std::vector<double>{1.0}), std::invalid_argument);
}

// Конструктор из пустого вектора бросает invalid_argument
TEST(LinearEquationTest, ConstructorVectorEmptyThrows) {
    EXPECT_THROW(LinearEquation(std::vector<double>{}), std::invalid_argument);
}

// Конструктор из строки менее чем с 2 числами бросает invalid_argument
TEST(LinearEquationTest, ConstructorStringTooShortThrows) {
    EXPECT_THROW(LinearEquation(std::string("42")), std::invalid_argument);
}

// --- Копирование и присваивание ---

// Копирующий конструктор создаёт независимую копию
TEST(LinearEquationTest, CopyConstructor) {
    LinearEquation eq1(std::vector<double>{2.0, -3.0, 5.0});
    LinearEquation eq2 = eq1;
    EXPECT_EQ(eq1, eq2);
    eq2[0] = 99.0;
    EXPECT_NE(eq1, eq2);
}

// Оператор присваивания копирует значения
TEST(LinearEquationTest, AssignmentOperator) {
    LinearEquation eq1(std::vector<double>{2.0, -3.0, 5.0});
    LinearEquation eq2(std::vector<double>{0.0, 0.0, 0.0});
    eq2 = eq1;
    EXPECT_EQ(eq1, eq2);
}

// --- Унарный минус ---

// Унарный минус меняет знак всех коэффициентов и свободного члена
TEST(LinearEquationTest, UnaryMinus) {
    LinearEquation eq(std::vector<double>{2.0, -3.0, 1.0, 5.0});
    LinearEquation neg = -eq;
    EXPECT_DOUBLE_EQ(-2.0, neg.getCoefficient(0));
    EXPECT_DOUBLE_EQ(3.0,  neg.getCoefficient(1));
    EXPECT_DOUBLE_EQ(-1.0, neg.getCoefficient(2));
    EXPECT_DOUBLE_EQ(-5.0, neg.getFreeTerm());
}

// --- += и -= ---

// += складывает коэффициенты и свободные члены
TEST(LinearEquationTest, PlusEquals) {
    LinearEquation a(std::vector<double>{1.0, 2.0, 3.0});
    LinearEquation b(std::vector<double>{4.0, 5.0, 6.0});
    a += b;
    EXPECT_DOUBLE_EQ(5.0, a[0]);
    EXPECT_DOUBLE_EQ(7.0, a[1]);
    EXPECT_DOUBLE_EQ(9.0, a.getFreeTerm());
}

// -= вычитает коэффициенты и свободные члены
TEST(LinearEquationTest, MinusEquals) {
    LinearEquation a(std::vector<double>{5.0, 7.0, 9.0});
    LinearEquation b(std::vector<double>{4.0, 5.0, 6.0});
    a -= b;
    EXPECT_DOUBLE_EQ(1.0, a[0]);
    EXPECT_DOUBLE_EQ(2.0, a[1]);
    EXPECT_DOUBLE_EQ(3.0, a.getFreeTerm());
}

// += с несовместимым уравнением бросает invalid_argument
TEST(LinearEquationTest, PlusEqualsIncompatibleThrows) {
    LinearEquation a(std::vector<double>{1.0, 2.0, 3.0});
    LinearEquation b(std::vector<double>{1.0, 2.0, 3.0, 4.0});
    EXPECT_THROW(a += b, std::invalid_argument);
}

// --- Бинарные +, -, * ---

// Сложение двух уравнений
TEST(LinearEquationTest, BinaryPlus) {
    LinearEquation a(std::vector<double>{1.0, 2.0, 3.0});
    LinearEquation b(std::vector<double>{4.0, 5.0, 6.0});
    LinearEquation c = a + b;
    EXPECT_DOUBLE_EQ(5.0, c[0]);
    EXPECT_DOUBLE_EQ(7.0, c[1]);
    EXPECT_DOUBLE_EQ(9.0, c.getFreeTerm());
}

// Вычитание двух уравнений
TEST(LinearEquationTest, BinaryMinus) {
    LinearEquation a(std::vector<double>{1.0, 2.0, 3.0});
    LinearEquation b(std::vector<double>{4.0, 5.0, 6.0});
    LinearEquation c = b - a;
    EXPECT_DOUBLE_EQ(3.0, c[0]);
    EXPECT_DOUBLE_EQ(3.0, c[1]);
    EXPECT_DOUBLE_EQ(3.0, c.getFreeTerm());
}

// Умножение уравнения на скаляр справа
TEST(LinearEquationTest, MultiplyByScalarRight) {
    LinearEquation eq(std::vector<double>{1.0, 2.0, 3.0});
    LinearEquation r = eq * 2.0;
    EXPECT_DOUBLE_EQ(2.0, r[0]);
    EXPECT_DOUBLE_EQ(4.0, r[1]);
    EXPECT_DOUBLE_EQ(6.0, r.getFreeTerm());
}

// Умножение скаляра на уравнение слева
TEST(LinearEquationTest, MultiplyByScalarLeft) {
    LinearEquation eq(std::vector<double>{1.0, 2.0, 3.0});
    LinearEquation r = 3.0 * eq;
    EXPECT_DOUBLE_EQ(3.0, r[0]);
    EXPECT_DOUBLE_EQ(6.0, r[1]);
    EXPECT_DOUBLE_EQ(9.0, r.getFreeTerm());
}

// --- Сравнение ---

// Одинаковые уравнения равны
TEST(LinearEquationTest, EqualityTrue) {
    LinearEquation a(std::vector<double>{1.0, 2.0, 3.0});
    LinearEquation b(std::vector<double>{1.0, 2.0, 3.0});
    EXPECT_TRUE(a == b);
    EXPECT_FALSE(a != b);
}

// Уравнения с разными коэффициентами не равны
TEST(LinearEquationTest, EqualityFalseCoeffs) {
    LinearEquation a(std::vector<double>{1.0, 2.0, 3.0});
    LinearEquation b(std::vector<double>{1.0, 9.0, 3.0});
    EXPECT_FALSE(a == b);
    EXPECT_TRUE(a != b);
}

// Уравнения с разными свободными членами не равны
TEST(LinearEquationTest, EqualityFalseFreeTerm) {
    LinearEquation a(std::vector<double>{1.0, 2.0, 3.0});
    LinearEquation b(std::vector<double>{1.0, 2.0, 9.0});
    EXPECT_FALSE(a == b);
}

// Уравнения разных размеров не равны
TEST(LinearEquationTest, EqualityFalseDifferentSize) {
    LinearEquation a(std::vector<double>{1.0, 2.0, 3.0});
    LinearEquation b(std::vector<double>{1.0, 2.0, 3.0, 4.0});
    EXPECT_FALSE(a == b);
}

// --- Оператор [] ---

// operator[] возвращает нужный коэффициент
TEST(LinearEquationTest, IndexOperatorCoeffs) {
    LinearEquation eq(std::vector<double>{1.0, 2.0, 3.0, 4.0});
    EXPECT_DOUBLE_EQ(1.0, eq[0]);
    EXPECT_DOUBLE_EQ(2.0, eq[1]);
    EXPECT_DOUBLE_EQ(3.0, eq[2]);
}

// operator[N] возвращает свободный член
TEST(LinearEquationTest, IndexOperatorFreeTerm) {
    LinearEquation eq(std::vector<double>{1.0, 2.0, 3.0, 4.0});
    EXPECT_DOUBLE_EQ(4.0, eq[3]);
}

// operator[] позволяет изменять коэффициент
TEST(LinearEquationTest, IndexOperatorWrite) {
    LinearEquation eq(std::vector<double>{1.0, 2.0, 3.0});
    eq[1] = 99.0;
    EXPECT_DOUBLE_EQ(99.0, eq[1]);
}

// Выход за границы бросает out_of_range
TEST(LinearEquationTest, IndexOutOfRangeThrows) {
    LinearEquation eq(std::vector<double>{1.0, 2.0, 3.0});
    EXPECT_THROW(eq[-1], std::out_of_range);
    EXPECT_THROW(eq[3],  std::out_of_range);
}

// --- Преобразование к vector<double> ---

// Приведение к vector даёт все коэффициенты + свободный член
TEST(LinearEquationTest, ConversionToVector) {
    std::vector<double> v = LinearEquation(std::vector<double>{1.0, 2.0, 3.0});
    ASSERT_EQ(3u, v.size());
    EXPECT_DOUBLE_EQ(1.0, v[0]);
    EXPECT_DOUBLE_EQ(2.0, v[1]);
    EXPECT_DOUBLE_EQ(3.0, v[2]);
}

// --- getCoefficient ---

// getCoefficient бросает out_of_range при неверном индексе
TEST(LinearEquationTest, GetCoefficientOutOfRange) {
    LinearEquation eq(std::vector<double>{1.0, 2.0, 3.0});
    EXPECT_THROW(eq.getCoefficient(-1), std::out_of_range);
    EXPECT_THROW(eq.getCoefficient(2),  std::out_of_range);
}

// --- operator<< ---

// Вывод уравнения в поток
TEST(LinearEquationTest, OutputOperator) {
    LinearEquation eq(std::vector<double>{2.0, -3.0, 5.0});
    std::ostringstream oss;
    oss << eq;
    EXPECT_EQ("2*x1 -3*x2 +5 = 0", oss.str());
}

// --- operator>> ---

// Ввод из потока: первое число — n, затем n коэффициентов, затем свободный член
TEST(LinearEquationTest, InputOperator) {
    std::istringstream iss("3  1.0 2.0 3.0  4.0");
    LinearEquation eq(std::vector<double>{0.0, 0.0});
    iss >> eq;
    EXPECT_EQ(3, eq.getN());
    EXPECT_DOUBLE_EQ(1.0, eq[0]);
    EXPECT_DOUBLE_EQ(4.0, eq.getFreeTerm());
}

// Ввод с n <= 0 бросает invalid_argument
TEST(LinearEquationTest, InputOperatorInvalidN) {
    std::istringstream iss("0 1.0 2.0");
    LinearEquation eq(std::vector<double>{0.0, 0.0});
    EXPECT_THROW(iss >> eq, std::invalid_argument);
}
