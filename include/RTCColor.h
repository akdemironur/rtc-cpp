#pragma once
#include "RTCTuple.h"
#include <iostream>

namespace RTC
{
class Color : public Tuple
{
  public:
    Color();
    Color(double x, double y, double z);
    double red() const;
    double green() const;
    double blue() const;
};

extern std::ostream &operator<<(std::ostream &os, const Color &c);

} // namespace RTC
