/*
Epifancev Artem
st142163@student.spbu.ru
assignment 5
*/

#include "rational.h"

#include <stdexcept>
#include <cstdlib>


int Rational::gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void Rational::reduce()
{
    if (denominator_ == 0)
    {
        throw std::runtime_error("Denominator cannot be zero");
    }

    if (denominator_ < 0)
    {
        numerator_ = -numerator_;
        denominator_ = -denominator_;
    }

    int g = gcd(std::abs(numerator_), std::abs(denominator_));
    numerator_ /= g;
    denominator_ /= g;
}

Rational::Rational() : numerator_(0), denominator_(1) {}

Rational::Rational(int num) : numerator_(num), denominator_(1) {}

Rational::Rational(int num, int den) : numerator_(num), denominator_(den)
{
    if (den == 0)
    {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    reduce();
}

Rational Rational::operator+(const Rational& other) const
{
    int num = numerator_ * other.denominator_ + other.numerator_ * denominator_;
    int den = denominator_ * other.denominator_;
    return Rational(num, den);
}

Rational& Rational::operator+=(const Rational& other)
{
    *this = *this + other;
    return *this;
}

Rational Rational::operator*(const Rational& other) const
{
    return Rational(numerator_ * other.numerator_,
                    denominator_ * other.denominator_);
}

Rational& Rational::operator*=(const Rational& other)
{
    *this = *this * other;
    return *this;
}

Rational Rational::operator*(int scalar) const
{
    return Rational(numerator_ * scalar, denominator_);
}

Rational& Rational::operator*=(int scalar)
{
    numerator_ *= scalar;
    reduce();
    return *this;
}

bool Rational::operator==(const Rational& other) const
{
    return numerator_ == other.numerator_ && denominator_ == other.denominator_;
}

bool Rational::operator!=(const Rational& other) const
{
    return !(*this == other);
}

int Rational::numerator() const
{
    return numerator_;
}
int Rational::denominator() const
{
    return denominator_;
}

Rational operator*(int scalar, const Rational& r)
{
    return r * scalar;
}

std::ostream& operator<<(std::ostream& os, const Rational& r)
{
    if (r.denominator() == 1)
    {
        os << r.numerator();
    }
    else
    {
        os << r.numerator() << "/" << r.denominator();
    }
    return os;
}
