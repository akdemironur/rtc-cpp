#pragma once
#include "RTCTuple.h"
#include <iostream>

namespace RTC
{
class Color : public Tuple
{
  public:
    Color()
    {
        e[0] = 0;
        e[1] = 0;
        e[2] = 0;
        e[3] = 0;
    }
    Color(double x, double y, double z)
    {
        e[0] = x;
        e[1] = y;
        e[2] = z;
        e[3] = 0;
    }
    double red() const
    {
        return e[0];
    }
    double green() const
    {
        return e[1];
    }
    double blue() const
    {
        return e[2];
    }
};

extern std::ostream &operator<<(std::ostream &os, const Color &c);

} // namespace RTC
