#include "RTCTuple.h"
namespace RTC
{
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

Tuple normalize(Tuple a)
{
    return a / a.magnitude();
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