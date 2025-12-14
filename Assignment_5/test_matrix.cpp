/*
Epifancev Artem
st142163@student.spbu.ru
assignment 5
*/

#include "matrix.h"
#include "rational.h"
#include <gtest/gtest.h>
#include <cmath>

TEST(IntMatrixTest, BasicOperations)
{
    Matrix<int> m1({{1, 2}, {3, 4}});
    Matrix<int> m2({{5, 6}, {7, 8}});

    Matrix<int> sum = m1 + m2;
    EXPECT_EQ(sum(0, 0), 6);
    EXPECT_EQ(sum(0, 1), 8);
    EXPECT_EQ(sum(1, 0), 10);
    EXPECT_EQ(sum(1, 1), 12);

    Matrix<int> scaled = m1 * 3;
    EXPECT_EQ(scaled(0, 0), 3);
    EXPECT_EQ(scaled(0, 1), 6);
    EXPECT_EQ(scaled(1, 0), 9);
    EXPECT_EQ(scaled(1, 1), 12);

    Matrix<int> m3({{1, 2, 3}, {4, 5, 6}});
    Matrix<int> m4({{7, 8}, {9, 10}, {11, 12}});
    Matrix<int> product = m3 * m4;
    EXPECT_EQ(product.getRows(), 2);
    EXPECT_EQ(product.getCols(), 2);
    EXPECT_EQ(product(0, 0), 58);
    EXPECT_EQ(product(0, 1), 64);
    EXPECT_EQ(product(1, 0), 139);
    EXPECT_EQ(product(1, 1), 154);
}

TEST(IntMatrixTest, Transpose)
{
    Matrix<int> m({{1, 2, 3}, {4, 5, 6}});
    Matrix<int> transposed = m.transpose();

    EXPECT_EQ(transposed.getRows(), 3);
    EXPECT_EQ(transposed.getCols(), 2);
    EXPECT_EQ(transposed(0, 0), 1);
    EXPECT_EQ(transposed(0, 1), 4);
    EXPECT_EQ(transposed(1, 0), 2);
    EXPECT_EQ(transposed(1, 1), 5);
    EXPECT_EQ(transposed(2, 0), 3);
    EXPECT_EQ(transposed(2, 1), 6);
}

TEST(IntMatrixTest, Equality)
{
    Matrix<int> m1({{1, 2}, {3, 4}});
    Matrix<int> m2({{1, 2}, {3, 4}});
    Matrix<int> m3({{1, 2}, {3, 5}});

    EXPECT_TRUE(m1 == m2);
    EXPECT_FALSE(m1 == m3);
    EXPECT_TRUE(m1 != m3);
}

TEST(FloatMatrixTest, BasicOperations)
{
    Matrix<float> m1({{1.5f, 2.5f}, {3.5f, 4.5f}});
    Matrix<float> m2({{0.5f, 1.5f}, {2.5f, 3.5f}});

    Matrix<float> sum = m1 + m2;
    EXPECT_FLOAT_EQ(sum(0, 0), 2.0f);
    EXPECT_FLOAT_EQ(sum(0, 1), 4.0f);
    EXPECT_FLOAT_EQ(sum(1, 0), 6.0f);
    EXPECT_FLOAT_EQ(sum(1, 1), 8.0f);

    Matrix<float> scaled = m1 * 2.0f;
    EXPECT_FLOAT_EQ(scaled(0, 0), 3.0f);
    EXPECT_FLOAT_EQ(scaled(0, 1), 5.0f);
    EXPECT_FLOAT_EQ(scaled(1, 0), 7.0f);
    EXPECT_FLOAT_EQ(scaled(1, 1), 9.0f);
}

TEST(FloatMatrixTest, Multiplication)
{
    Matrix<float> m1({{1.0f, 2.0f}, {3.0f, 4.0f}});
    Matrix<float> m2({{5.0f, 6.0f}, {7.0f, 8.0f}});

    Matrix<float> product = m1 * m2;
    EXPECT_FLOAT_EQ(product(0, 0), 19.0f);
    EXPECT_FLOAT_EQ(product(0, 1), 22.0f);
    EXPECT_FLOAT_EQ(product(1, 0), 43.0f);
    EXPECT_FLOAT_EQ(product(1, 1), 50.0f);
}

TEST(DoubleMatrixTest, Precision)
{
    Matrix<double> m1({{0.1, 0.2}, {0.3, 0.4}});
    Matrix<double> m2({{0.5, 0.6}, {0.7, 0.8}});

    Matrix<double> product = m1 * m2;
    EXPECT_NEAR(product(0, 0), 0.19, 1e-10);
    EXPECT_NEAR(product(0, 1), 0.22, 1e-10);
    EXPECT_NEAR(product(1, 0), 0.43, 1e-10);
    EXPECT_NEAR(product(1, 1), 0.50, 1e-10);
}

TEST(RationalTest, BasicOperations)
{
    Rational r1(1, 2);
    Rational r2(1, 3);

    Rational sum = r1 + r2;
    EXPECT_EQ(sum.numerator(), 5);
    EXPECT_EQ(sum.denominator(), 6);

    Rational product = r1 * r2;
    EXPECT_EQ(product.numerator(), 1);
    EXPECT_EQ(product.denominator(), 6);

    Rational scaled = r1 * 3;
    EXPECT_EQ(scaled.numerator(), 3);
    EXPECT_EQ(scaled.denominator(), 2);
}

TEST(RationalTest, Reduction)
{
    Rational r1(2, 4);
    EXPECT_EQ(r1.numerator(), 1);
    EXPECT_EQ(r1.denominator(), 2);

    Rational r2(-3, 9);
    EXPECT_EQ(r2.numerator(), -1);
    EXPECT_EQ(r2.denominator(), 3);

    Rational r3(4, -8);
    EXPECT_EQ(r3.numerator(), -1);
    EXPECT_EQ(r3.denominator(), 2);
}

TEST(RationalTest, Equality)
{
    Rational r1(1, 2);
    Rational r2(2, 4);
    Rational r3(1, 3);

    EXPECT_TRUE(r1 == r2);
    EXPECT_FALSE(r1 == r3);
    EXPECT_TRUE(r1 != r3);
}

TEST(RationalMatrixTest, BasicOperations)
{
    Matrix<Rational> m1({{Rational(1, 2), Rational(1, 3)}, {Rational(1, 4), Rational(1, 5)}});
    Matrix<Rational> m2({{Rational(1, 6), Rational(1, 7)}, {Rational(1, 8), Rational(1, 9)}});

    Matrix<Rational> sum = m1 + m2;
    EXPECT_EQ(sum(0, 0), Rational(2, 3));
    EXPECT_EQ(sum(0, 1), Rational(10, 21));
    EXPECT_EQ(sum(1, 0), Rational(3, 8));
    EXPECT_EQ(sum(1, 1), Rational(14, 45));

    Matrix<Rational> scaled = m1 * Rational(2);
    EXPECT_EQ(scaled(0, 0), Rational(1, 1));
    EXPECT_EQ(scaled(0, 1), Rational(2, 3));
    EXPECT_EQ(scaled(1, 0), Rational(1, 2));
    EXPECT_EQ(scaled(1, 1), Rational(2, 5));
}

TEST(RationalMatrixTest, Multiplication)
{
    Matrix<Rational> m1({{Rational(1, 2), Rational(1, 3)}, {Rational(1, 4), Rational(1, 5)}});
    Matrix<Rational> m2({{Rational(1, 6), Rational(1, 7)}, {Rational(1, 8), Rational(1, 9)}});

    Matrix<Rational> product = m1 * m2;

    EXPECT_EQ(product(0, 0), Rational(1, 8));

    EXPECT_EQ(product(0, 1), Rational(41, 378));

    EXPECT_EQ(product(1, 0), Rational(1, 15));

    EXPECT_EQ(product(1, 1), Rational(73, 1260));
}

TEST(RationalMatrixTest, Transpose)
{
    Matrix<Rational> m({{Rational(1, 2), Rational(1, 3), Rational(1, 4)},
        {Rational(1, 5), Rational(1, 6), Rational(1, 7)}});

    Matrix<Rational> transposed = m.transpose();

    EXPECT_EQ(transposed.getRows(), 3);
    EXPECT_EQ(transposed.getCols(), 2);
    EXPECT_EQ(transposed(0, 0), Rational(1, 2));
    EXPECT_EQ(transposed(0, 1), Rational(1, 5));
    EXPECT_EQ(transposed(1, 0), Rational(1, 3));
    EXPECT_EQ(transposed(1, 1), Rational(1, 6));
    EXPECT_EQ(transposed(2, 0), Rational(1, 4));
    EXPECT_EQ(transposed(2, 1), Rational(1, 7));
}

TEST(ErrorHandlingTest, InvalidDimensions)
{
    Matrix<int> m1(2, 3);
    Matrix<int> m2(4, 5);

    EXPECT_THROW(m1 + m2, std::invalid_argument);

    Matrix<int> m3(2, 3);
    Matrix<int> m4(4, 5);
    EXPECT_THROW(m3 * m4, std::invalid_argument);
}

TEST(ErrorHandlingTest, InvalidRational)
{
    EXPECT_THROW(Rational(1, 0), std::invalid_argument);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
