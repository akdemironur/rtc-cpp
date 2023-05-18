#pragma once
#include "RTCCommon.h"
#include "RTCTuple.h"
#include <iostream>
#include <vector>
#include <ranges>
namespace RTC
{
class Matrix
{
  public:
    Matrix(unsigned numRows, unsigned numColumns, std::vector<double> values)
    {
        _numRows = numRows;
        _numColumns = numColumns;
        values.resize(_numRows * _numColumns);
        _values = values;
    }
    double &operator()(unsigned row, unsigned col)
    {
        return _values[_numColumns * row + col];
    }
    double operator()(unsigned row, unsigned col) const
    {
        return _values[_numColumns * row + col];
    }
    Matrix &transpose()
    {
        std::vector<double> transposedValues;
        for (auto c = 0; c < _numColumns; c++)
            for (auto r = 0; r < _numRows; r++)
                transposedValues.push_back((*this)(r, c));
        std::swap(_numRows, _numColumns);
        _values = transposedValues;
        return *this;
    }
    unsigned numRows() const
    {
        return _numRows;
    }
    unsigned numColumns() const
    {
        return _numColumns;
    }
    const std::vector<double> &values() const
    {
        return _values;
    }
    void print() const
    {
        std::cout << "=====================\n";
        std::cout << "Rows: " << _numRows << "\tCols: " << _numColumns << std::endl;
        for (auto i : _values)
        {
            std::cout << i << std::endl;
        }
        std::cout << "=====================\n";
    }
    Matrix submatrix(unsigned sr, unsigned sc) const
    {
        std::vector<double> subValues;
        for (auto r = 0; r < _numRows; r++)
        {
            for (auto c = 0; c < _numColumns; c++)
            {
                if (!(c == sc || r == sr))
                    subValues.push_back((*this)(r, c));
            }
        }
        return Matrix(_numRows - 1, _numColumns - 1, subValues);
    }
    double determinant() const;
    double cofactor(unsigned r, unsigned c) const;
    double minor(unsigned r, unsigned c) const;

  protected:
    unsigned _numRows, _numColumns;
    std::vector<double> _values;
};
extern bool operator==(const Matrix &a, const Matrix &b);
extern bool operator!=(const Matrix &a, const Matrix &b);
extern Matrix operator*(const Matrix &a, const Matrix &b);
extern Matrix operator*(const Matrix &A, const Tuple &b);
extern Matrix identityMatrix(unsigned size);
Matrix rowVector(const Tuple &a);
Matrix columnVector(const Tuple &a);
} // namespace RTC
