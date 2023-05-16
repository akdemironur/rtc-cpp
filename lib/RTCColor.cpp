#include "RTCColor.h"
#include <algorithm>
#include <cmath>
namespace RTC
{

int normColorComponent(double x)
{
    return std::max(std::min(int(std::lrint(255 * x)), 255), 0);
}

std::ostream &operator<<(std::ostream &os, const Color &c)
{
    os << normColorComponent(c.red()) << " " << normColorComponent(c.green()) << " " << normColorComponent(c.blue());
    return os;
}

} // namespace RTC