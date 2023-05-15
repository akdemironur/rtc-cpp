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

  bool isPoint() { return approxEqual(e[3], 1.0); }
  bool isVector() { return approxEqual(e[3], 0.0); }

private:
  double e[4];
};

extern bool operator==(const Tuple &a, const Tuple &b);
extern Tuple operator+(const Tuple &a, const Tuple &b);
extern Tuple Vector(double x, double y, double z);
extern Tuple Point(double x, double y, double z);
} // namespace RTC
