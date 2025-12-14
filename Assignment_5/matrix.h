/*
Epifancev Artem
st142163@student.spbu.ru
assignment 5
*/

#ifndef MATRIX_H
#define MATRIX_H

#include "rational.h"

#include <stdexcept>
#include <vector>
#include <iostream>
#include <iomanip>
#include <type_traits>


template<typename T>
class Matrix
{
public:
    Matrix(size_t rows, size_t cols);
    Matrix(size_t rows, size_t cols, const T& init_value);
    Matrix(const std::vector<std::vector<T>>& data);

    Matrix(const Matrix& other) = default;
    Matrix& operator=(const Matrix& other) = default;
    ~Matrix() = default;

    std::vector<T>& operator[](size_t row);
    const std::vector<T>& operator[](size_t row) const;

    T& operator()(size_t row, size_t col);
    const T& operator()(size_t row, size_t col) const;

    size_t getRows() const;
    size_t getCols() const;

    Matrix operator*(const T& scalar) const;
    Matrix& operator*=(const T& scalar);

    Matrix operator+(const Matrix& other) const;
    Matrix& operator+=(const Matrix& other);

    Matrix operator*(const Matrix& other) const;

    Matrix transpose() const;

    bool operator==(const Matrix& other) const;
    bool operator!=(const Matrix& other) const;

    void print(std::ostream& os = std::cout) const;
    const std::vector<std::vector<T>>& data() const
    {
        return _data;
    }

private:
    size_t _rows;
    size_t _cols;
    std::vector<std::vector<T>> _data;
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix);

#endif
