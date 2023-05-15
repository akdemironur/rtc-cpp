#include "RTCCommon.h"
namespace RTC {
bool approxEqual(double a, double b) {
  const double EPSILON = 1e-8;
  return std::abs(a - b) < EPSILON;
}
} // namespace RTC
