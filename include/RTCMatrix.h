#pragma once
#include "RTCCommon.h"
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
    unsigned numRows() const
    {
        return _numRows;
    }
    unsigned numColumns() const
    {
        return _numRows;
    }
    const std::vector<double> &values() const
    {
        return _values;
    }

  protected:
    unsigned _numRows, _numColumns;
    std::vector<double> _values;
};
extern bool operator==(const Matrix &a, const Matrix &b);
extern bool operator!=(const Matrix &a, const Matrix &b);
extern Matrix operator*(const Matrix &a, const Matrix &b);
} // namespace RTC
