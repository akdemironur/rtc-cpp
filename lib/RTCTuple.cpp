#include "RTCTuple.h"
namespace RTC {
Tuple Vector(double x, double y, double z) { return Tuple(x, y, z, 0.0); }

Tuple Point(double x, double y, double z) { return Tuple(x, y, z, 1.0); }

bool operator==(const Tuple &a, const Tuple &b) {
  return (approxEqual(a.x(), b.x()) && approxEqual(a.y(), b.y()) &&
          approxEqual(a.z(), b.z()) && approxEqual(a.w(), b.w()));
}

Tuple operator+(const Tuple &a, const Tuple &b) {
  return Tuple(a.x() + b.x(), a.y() + b.y(), a.z() + b.z(), a.w() + b.w());
}

Tuple operator-(const Tuple &a, const Tuple &b) {
  return Tuple(a.x() - b.x(), a.y() - b.y(), a.z() - b.z(), a.w() - b.w());
}

} // namespace RTC