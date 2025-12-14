/*
Epifancev Artem
st142163@student.spbu.ru
assignment 5
*/

#include "matrix.h"

template<typename T>
Matrix<T>::Matrix(size_t rows, size_t cols) :
    _rows(rows), _cols(cols), _data(rows, std::vector<T>(cols)) {}

template<typename T>
Matrix<T>::Matrix(size_t rows, size_t cols, const T& init_value) :
    _rows(rows), _cols(cols), _data(rows, std::vector<T>(cols, init_value)) {}

template<typename T>
Matrix<T>::Matrix(const std::vector<std::vector<T>>& data) :
    _rows(data.size()), _cols(data.empty() ? 0 : data[0].size()), _data(data) {}

template<typename T>
std::vector<T>& Matrix<T>::operator[](size_t row)
{
    return _data[row];
}

template<typename T>
const std::vector<T>& Matrix<T>::operator[](size_t row) const
{
    return _data[row];
}

template<typename T>
T& Matrix<T>::operator()(size_t row, size_t col)
{
    return _data[row][col];
}

template<typename T>
const T& Matrix<T>::operator()(size_t row, size_t col) const
{
    return _data[row][col];
}

template<typename T>
size_t Matrix<T>::getRows() const
{
    return _rows;
}

template<typename T>
size_t Matrix<T>::getCols() const
{
    return _cols;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const T& scalar) const
{
    Matrix result(_rows, _cols);
    for (size_t i = 0; i < _rows; ++i)
    {
        for (size_t j = 0; j < _cols; ++j)
        {
            result[i][j] = _data[i][j] * scalar;
        }
    }
    return result;
}

template<typename T>
Matrix<T>& Matrix<T>::operator*=(const T& scalar)
{
    for (size_t i = 0; i < _rows; ++i)
    {
        for (size_t j = 0; j < _cols; ++j)
        {
            _data[i][j] *= scalar;
        }
    }
    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix& other) const
{
    if (_rows != other._rows || _cols != other._cols)
    {
        throw std::invalid_argument("Matrix dimensions must match for addition");
    }

    Matrix result(_rows, _cols);
    for (size_t i = 0; i < _rows; ++i)
    {
        for (size_t j = 0; j < _cols; ++j)
        {
            result[i][j] = _data[i][j] + other._data[i][j];
        }
    }
    return result;
}

template<typename T>
Matrix<T>& Matrix<T>::operator+=(const Matrix& other)
{
    if (_rows != other._rows || _cols != other._cols)
    {
        throw std::invalid_argument("Matrix dimensions must match for addition");
    }

    for (size_t i = 0; i < _rows; ++i)
    {
        for (size_t j = 0; j < _cols; ++j)
        {
            _data[i][j] += other._data[i][j];
        }
    }
    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix& other) const
{
    if (_cols != other._rows)
    {
        throw std::invalid_argument(
            "Number of columns of first matrix must equal number of rows of second matrix"
        );
    }

    Matrix result(_rows, other._cols);
    for (size_t i = 0; i < _rows; ++i)
    {
        for (size_t j = 0; j < other._cols; ++j)
        {
            T sum = T();
            for (size_t k = 0; k < _cols; ++k)
            {
                sum += _data[i][k] * other._data[k][j];
            }
            result[i][j] = sum;
        }
    }
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::transpose() const
{
    Matrix result(_cols, _rows);
    for (size_t i = 0; i < _rows; ++i)
    {
        for (size_t j = 0; j < _cols; ++j)
        {
            result[j][i] = _data[i][j];
        }
    }
    return result;
}

template<typename T>
bool Matrix<T>::operator==(const Matrix& other) const
{
    if (_rows != other._rows || _cols != other._cols)
    {
        return false;
    }

    for (size_t i = 0; i < _rows; ++i)
    {
        for (size_t j = 0; j < _cols; ++j)
        {
            if (_data[i][j] != other._data[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

template<typename T>
bool Matrix<T>::operator!=(const Matrix& other) const
{
    return !(*this == other);
}

template<typename T>
void Matrix<T>::print(std::ostream& os) const
{
    for (size_t i = 0; i < _rows; ++i)
    {
        for (size_t j = 0; j < _cols; ++j)
        {
            os << std::setw(10) << _data[i][j] << " ";
        }
        os << std::endl;
    }
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix)
{
    matrix.print(os);
    return os;
}

template class Matrix<int>;
template class Matrix<float>;
template class Matrix<double>;
template class Matrix<Rational>;

template std::ostream& operator<<(std::ostream& os, const Matrix<int>& matrix);
template std::ostream& operator<<(std::ostream& os, const Matrix<float>& matrix);
template std::ostream& operator<<(std::ostream& os, const Matrix<double>& matrix);
template std::ostream& operator<<(std::ostream& os, const Matrix<Rational>& matrix);
