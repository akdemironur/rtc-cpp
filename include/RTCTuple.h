#pragma once
#include "RTCCommon.h"
#include <vector>
namespace RTC
{
class Tuple
{
  public:
    Tuple();
    Tuple(double x, double y, double z, double w);
    double x() const;
    double y() const;
    double z() const;
    double w() const;
    const std::vector<double> &vec() const;
    double magsqr() const;
    double magnitude() const;
    bool isPoint() const;
    bool isVector() const;
    Tuple getNorm() const;
    Tuple operator-() const;

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
