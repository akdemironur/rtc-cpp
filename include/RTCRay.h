#pragma once
#include "RTCTuple.h"
namespace RTC
{
class Ray
{
  public:
    Ray();
    Ray(Tuple origin, Tuple direction);
    Tuple origin() const;
    Tuple direction() const;
    Tuple position(double t) const;

  protected:
    Tuple _origin;
    Tuple _direction;
};

} // namespace RTC
