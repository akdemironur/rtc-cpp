#include "RTCCommon.h"
namespace RTC
{
bool approxEqual(double a, double b)
{
    const double EPSILON = 1e-5;
    return std::abs(a - b) < EPSILON;
}
} // namespace RTC
