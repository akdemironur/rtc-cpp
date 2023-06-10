#include "RTCMatrix.h"
namespace RTC
{
double &Matrix::operator()(unsigned row, unsigned col)
{
    return _values[_numColumns * row + col];
}
double Matrix::operator()(unsigned row, unsigned col) const
{
    return _values[_numColumns * row + col];
}
bool operator==(const Matrix &a, const Matrix &b)
{
    if (!(a.numColumns() == b.numColumns() && a.numRows() == b.numRows()))
        return false;
    for (auto it1 = a.values().begin(), it2 = b.values().begin(); it1 != a.values().end() && it2 != b.values().end();
         ++it1, ++it2)
    {

        if (!approxEqual(*it1, *it2))
            return false;
    }
    return true;
}
bool operator!=(const Matrix &a, const Matrix &b)
{
    return !(a == b);
}
Matrix operator*(const Matrix &a, const Matrix &b)
{
    unsigned resultRows = a.numRows();
    unsigned resultColumns = b.numColumns();
    std::vector<double> resultValues(resultRows * resultColumns);
    Matrix result(resultRows, resultColumns, resultValues);
    for (auto row = 0; row < resultRows; row++)
    {
        for (auto col = 0; col < resultColumns; col++)
        {
            result(row, col) = 0;
            for (auto i = 0; i < a.numColumns(); i++)
            {
                result(row, col) += a(row, i) * b(i, col);
            }
        }
    }
    return result;
}
Matrix rowVector(const Tuple &a)
{
    return Matrix(1, 4, a.vec());
}
Matrix columnVector(const Tuple &a)
{
    return Matrix(4, 1, a.vec());
}
Matrix identityMatrix(unsigned size)
{
    std::vector<double> values(size * size);
    Matrix id(size, size, values);
    for (auto i = 0; i < size; i++)
        id(i, i) = 1;
    return id;
}

Tuple operator*(const Matrix &A, const Tuple &b)
{
    auto bMat = columnVector(b);
    auto C = A * bMat;
    return C.toTuple();
}
std::vector<double> Matrix::vec() const
{
    return _values;
}
Tuple Matrix::toTuple() const
{
    return Tuple(this->vec());
}

double Matrix::determinant() const
{
    if (this->numRows() == 1 && this->numColumns() == 1)
        return (*this)(0, 0);
    double det = 0;
    for (auto c = 0; c < this->numColumns(); c++)
    {
        det += this->cofactor(0, c) * (*this)(0, c);
    }
    return det;
}
double Matrix::cofactor(unsigned r, unsigned c) const
{
    auto minor = this->minor(r, c);
    if ((r + c) % 2 == 0)
        return minor;
    else
        return -minor;
}
double Matrix::minor(unsigned r, unsigned c) const
{
    auto sub = this->submatrix(r, c);
    return sub.determinant();
}

Matrix::Matrix(unsigned numRows, unsigned numColumns, std::vector<double> values)
{
    _numRows = numRows;
    _numColumns = numColumns;
    values.resize(_numRows * _numColumns);
    _values = values;
}
Matrix &Matrix::transpose()
{
    std::vector<double> transposedValues;
    for (auto c = 0; c < this->numColumns(); c++)
        for (auto r = 0; r < this->numRows(); r++)
            transposedValues.push_back((*this)(r, c));
    std::swap(_numRows, _numColumns);
    _values = transposedValues;
    return *this;
}
unsigned Matrix::numRows() const
{
    return _numRows;
}
unsigned Matrix::numColumns() const
{
    return _numColumns;
}
const std::vector<double> &Matrix::values() const
{
    return _values;
}

std::ostream &operator<<(std::ostream &os, const Matrix &m)
{
    os << "=====================\n";
    os << "Rows: " << m.numRows() << "\tCols: " << m.numColumns() << std::endl;
    for (auto i : m.values())
    {
        os << i << std::endl;
    }
    os << "=====================\n";
}
Matrix Matrix::submatrix(unsigned sr, unsigned sc) const
{
    std::vector<double> subValues;
    for (auto r = 0; r < this->numRows(); r++)
    {
        for (auto c = 0; c < this->numColumns(); c++)
        {
            if (!(c == sc || r == sr))
                subValues.push_back((*this)(r, c));
        }
    }
    return Matrix(this->numRows() - 1, this->numColumns() - 1, subValues);
}

bool Matrix::isInvertible() const
{
    return !approxEqual(this->determinant(), 0);
}
Matrix Matrix::getInverse() const
{
    double det = this->determinant();
    std::vector<double> values;
    auto inv = Matrix(this->numRows(), this->numColumns(), values);
    for (auto r = 0; r < this->numRows(); r++)
    {
        for (auto c = 0; c < this->numColumns(); c++)
        {
            inv(c, r) = this->cofactor(r, c) / det;
        }
    }
    return inv;
}
} // namespace RTC