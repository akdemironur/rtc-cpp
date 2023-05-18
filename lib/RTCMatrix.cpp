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

Matrix operator*(const Matrix &A, const Tuple &b)
{
    auto bMat = columnVector(b);
    return A * bMat;
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
Matrix Matrix::transpose() const
{
    std::vector<double> transposedValues;
    for (auto c = 0; c < this->numColumns(); c++)
        for (auto r = 0; r < this->numRows(); r++)
            transposedValues.push_back((*this)(r, c));
    return Matrix(this->numColumns(), this->numRows(), transposedValues);
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
void Matrix::print() const
{
    std::cout << "=====================\n";
    std::cout << "Rows: " << _numRows << "\tCols: " << _numColumns << std::endl;
    for (auto i : this->values())
    {
        std::cout << i << std::endl;
    }
    std::cout << "=====================\n";
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
} // namespace RTC