#pragma once
#include "RTCCommon.h"

namespace RTC {
class Tuple {
public:
  Tuple() : e{} {}
  Tuple(double x, double y, double z, double w) : e{x, y, z, w} {}
  double x() const { return e[0]; }
  double y() const { return e[1]; }
  double z() const { return e[2]; }
  double w() const { return e[3]; }
  bool operator==(const Tuple &c) {
    return (approxEqual(e[0], c.x()) && approxEqual(e[1], c.y()) &&
            approxEqual(e[2], c.z()) && approxEqual(e[3], c.w()));
  }
  bool isPoint() { return approxEqual(e[3], 1.0); }
  bool isVector() { return approxEqual(e[3], 0.0); }

private:
  double e[4];
};

extern Tuple Vector(double x, double y, double z);
extern Tuple Point(double x, double y, double z);
} // namespace RTC
