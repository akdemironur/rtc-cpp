#pragma once
#include "RTCTuple.h"
#include "RTCMatrix.h"
#include <cmath>
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
    Ray transform(Matrix M) const;

  protected:
    Tuple _origin;
    Tuple _direction;
};

} // namespace RTC
