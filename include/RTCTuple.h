#pragma once
#include "RTCCommon.h"
#include <vector>
namespace RTC
{
class Tuple
{
  public:
    Tuple()
    {
        e.push_back(0);
        e.push_back(0);
        e.push_back(0);
        e.push_back(0);
    }
    Tuple(double x, double y, double z, double w)
    {
        e.push_back(x);
        e.push_back(y);
        e.push_back(z);
        e.push_back(w);
    }
    double x() const
    {
        return e[0];
    }
    double y() const
    {
        return e[1];
    }
    double z() const
    {
        return e[2];
    }
    double w() const
    {
        return e[3];
    }
    const std::vector<double> &vec() const
    {
        return e;
    }
    double magsqr() const
    {
        return (std::pow(e[0], 2) + std::pow(e[1], 2) + std::pow(e[2], 2) + std::pow(e[3], 2));
    }
    double magnitude() const
    {
        return std::sqrt(magsqr());
    }
    bool isPoint() const
    {
        return approxEqual(e[3], 1.0);
    }
    bool isVector() const
    {
        return approxEqual(e[3], 0.0);
    }
    Tuple getNorm() const
    {
        auto mag = magnitude();
        return Tuple(x() / mag, y() / mag, z() / mag, w() / mag);
    }
    Tuple operator-() const
    {
        return Tuple(-e[0], -e[1], -e[2], -e[3]);
    }

  protected:
    std::vector<double> e;
};

extern bool operator==(const Tuple &a, const Tuple &b);
extern bool operator!=(const Tuple &a, const Tuple &b);
extern Tuple operator+(const Tuple &a, const Tuple &b);
extern Tuple operator-(const Tuple &a, const Tuple &b);
extern Tuple operator*(const Tuple &t, double a);
extern Tuple operator/(const Tuple &t, double a);
extern Tuple operator*(double a, const Tuple &t);
extern Tuple operator*(const Tuple &a, const Tuple &b);
extern Tuple Vector(double x, double y, double z);
extern Tuple Point(double x, double y, double z);
extern double dot(const Tuple &a, const Tuple &b);
extern Tuple cross(const Tuple &a, const Tuple &b);
} // namespace RTC
