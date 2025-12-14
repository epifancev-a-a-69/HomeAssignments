/*
Epifancev Artem
st142163@student.spbu.ru
assignment 5
*/

#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

class Rational
{
public:
    Rational();
    explicit Rational(int num);
    Rational(int num, int den);

    Rational(const Rational&) = default;
    Rational& operator=(const Rational&) = default;
    ~Rational() = default;

    Rational operator+(const Rational& other) const;
    Rational& operator+=(const Rational& other);

    Rational operator*(const Rational& other) const;
    Rational& operator*=(const Rational& other);

    Rational operator*(int scalar) const;
    Rational& operator*=(int scalar);

    bool operator==(const Rational& other) const;
    bool operator!=(const Rational& other) const;

    int numerator() const;
    int denominator() const;

    friend std::ostream& operator<<(std::ostream& os, const Rational& r);
private:
    int numerator_;
    int denominator_;

    static int gcd(int a, int b);
    void reduce();
};

Rational operator*(int scalar, const Rational& r);

#endif
