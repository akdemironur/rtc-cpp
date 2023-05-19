#pragma once
#include "RTCTuple.h"
#include "RTCRay.h"
#include <utility>
namespace RTC
{
class Shape
{
  public:
  protected:
};

class Sphere : public Shape
{
  public:
    Sphere();
    Sphere(Tuple center, double radius);
    Tuple center() const;
    double radius() const;
    std::pair<std::vector<double>, const Sphere &> intersect(const Ray &r);

  protected:
    Tuple _center;
    double _radius;
    std::vector<double> _intersections;
};

} // namespace RTC
