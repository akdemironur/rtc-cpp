#include "RTCColor.h"
#include <algorithm>
#include <cmath>
namespace RTC
{

Color::Color()
{
    e[0] = 0;
    e[1] = 0;
    e[2] = 0;
    e[3] = 0;
}
Color::Color(double x, double y, double z)
{
    e[0] = x;
    e[1] = y;
    e[2] = z;
    e[3] = 0;
}
double Color::red() const
{
    return e[0];
}
double Color::green() const
{
    return e[1];
}
double Color::blue() const
{
    return e[2];
}
int normColorComponent(double x)
{
    return std::max(std::min(int(std::lrint(255 * x)), 255), 0);
}

std::ostream &operator<<(std::ostream &os, const Color &c)
{
    os << normColorComponent(c.red()) << " " << normColorComponent(c.green()) << " " << normColorComponent(c.blue());
    return os;
}
void Color::operator=(const Tuple &a)
{
    e[0] = a.x();
    e[1] = a.y();
    e[2] = a.z();
    e[3] = 0;
}

} // namespace RTC