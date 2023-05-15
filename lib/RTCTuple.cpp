#include "RTCTuple.h"
namespace RTC {
Tuple Vector(double x, double y, double z) { return Tuple(x, y, z, 0.0); }

Tuple Point(double x, double y, double z) { return Tuple(x, y, z, 1.0); }
} // namespace RTC