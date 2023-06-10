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
    Matrix(unsigned numRows, unsigned numColumns, std::vector<double> values);
    double &operator()(unsigned row, unsigned col);
    double operator()(unsigned row, unsigned col) const;
    Matrix &transpose();
    unsigned numRows() const;
    unsigned numColumns() const;
    const std::vector<double> &values() const;
    Matrix submatrix(unsigned sr, unsigned sc) const;
    double determinant() const;
    double cofactor(unsigned r, unsigned c) const;
    double minor(unsigned r, unsigned c) const;
    bool isInvertible() const;
    Matrix getInverse() const;
    Tuple toTuple() const;
    std::vector<double> vec() const;

  protected:
    unsigned _numRows, _numColumns;
    std::vector<double> _values;
};
extern bool operator==(const Matrix &a, const Matrix &b);
extern bool operator!=(const Matrix &a, const Matrix &b);
extern Matrix operator*(const Matrix &a, const Matrix &b);
extern Tuple operator*(const Matrix &A, const Tuple &b);
extern Matrix identityMatrix(unsigned size);
extern std::ostream &operator<<(std::ostream &os, const Matrix &m);
Matrix rowVector(const Tuple &a);
Matrix columnVector(const Tuple &a);
} // namespace RTC
