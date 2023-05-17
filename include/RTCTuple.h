#pragma once
#include "RTCCommon.h"

namespace RTC
{
class Tuple
{
  public:
    Tuple()
    {
        e[0] = 0;
        e[1] = 0;
        e[2] = 0;
        e[3] = 0;
    }
    Tuple(double x, double y, double z, double w) : e{x, y, z, w}
    {
        e[0] = x;
        e[1] = y;
        e[2] = z;
        e[3] = w;
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
    double magsqr() const
    {
        return (std::pow(e[0], 2) + std::pow(e[1], 2) + std::pow(e[2], 2) + std::pow(e[3], 2));
    }
    double magnitude() const
    {
        return std::sqrt(magsqr());
    }
    bool isPoint()
    {
        return approxEqual(e[3], 1.0);
    }
    bool isVector()
    {
        return approxEqual(e[3], 0.0);
    }
    Tuple operator-() const
    {
        return Tuple(-e[0], -e[1], -e[2], -e[3]);
    }

  protected:
    double e[4];
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
extern Tuple normalize(Tuple a);
extern double dot(const Tuple &a, const Tuple &b);
extern Tuple cross(const Tuple &a, const Tuple &b);
} // namespace RTC
