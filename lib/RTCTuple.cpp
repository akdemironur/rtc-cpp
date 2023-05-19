#include "RTCTuple.h"
namespace RTC
{
Tuple::Tuple()
{
    e.push_back(0);
    e.push_back(0);
    e.push_back(0);
    e.push_back(0);
}
Tuple::Tuple(double x, double y, double z, double w)
{
    e.push_back(x);
    e.push_back(y);
    e.push_back(z);
    e.push_back(w);
}
Tuple::Tuple(std::vector<double> vals)
{
    e = vals;
}
double Tuple::x() const
{
    return e[0];
}
double Tuple::y() const
{
    return e[1];
}
double Tuple::z() const
{
    return e[2];
}
double Tuple::w() const
{
    return e[3];
}
const std::vector<double> &Tuple::vec() const
{
    return e;
}
double Tuple::magsqr() const
{
    return (std::pow(e[0], 2) + std::pow(e[1], 2) + std::pow(e[2], 2) + std::pow(e[3], 2));
}
double Tuple::magnitude() const
{
    return std::sqrt(magsqr());
}
bool Tuple::isPoint() const
{
    return approxEqual(e[3], 1.0);
}
bool Tuple::isVector() const
{
    return approxEqual(e[3], 0.0);
}
Tuple Tuple::getNorm() const
{
    auto mag = magnitude();
    return Tuple(x() / mag, y() / mag, z() / mag, w() / mag);
}
Tuple Tuple::operator-() const
{
    return Tuple(-e[0], -e[1], -e[2], -e[3]);
}
Tuple Vector(double x, double y, double z)
{
    return Tuple(x, y, z, 0.0);
}

Tuple Point(double x, double y, double z)
{
    return Tuple(x, y, z, 1.0);
}

bool operator==(const Tuple &a, const Tuple &b)
{
    return (approxEqual(a.x(), b.x()) && approxEqual(a.y(), b.y()) && approxEqual(a.z(), b.z()) &&
            approxEqual(a.w(), b.w()));
}

bool operator!=(const Tuple &a, const Tuple &b)
{
    return !(a == b);
}

Tuple operator+(const Tuple &a, const Tuple &b)
{
    return Tuple(a.x() + b.x(), a.y() + b.y(), a.z() + b.z(), a.w() + b.w());
}

Tuple operator-(const Tuple &a, const Tuple &b)
{
    return Tuple(a.x() - b.x(), a.y() - b.y(), a.z() - b.z(), a.w() - b.w());
}

Tuple operator*(const Tuple &t, double a)
{
    return a * t;
}

Tuple operator*(const Tuple &a, const Tuple &b)
{
    return Tuple(a.x() * b.x(), a.y() * b.y(), a.z() * b.z(), a.w() * b.w());
}

Tuple operator/(const Tuple &t, double a)
{
    return (1 / a) * t;
}

Tuple operator*(double a, const Tuple &t)
{
    return Tuple(a * t.x(), a * t.y(), a * t.z(), a * t.w());
}

double dot(const Tuple &a, const Tuple &b)
{
    return a.x() * b.x() + a.y() * b.y() + a.z() * b.z() + a.w() * b.w();
}

Tuple cross(const Tuple &a, const Tuple &b)
{
    return Vector(a.y() * b.z() - a.z() * b.y(), a.z() * b.x() - a.x() * b.z(), a.x() * b.y() - a.y() * b.x());
}
} // namespace RTC