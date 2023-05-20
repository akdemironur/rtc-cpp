#pragma once
#include "RTCTuple.h"
#include "RTCRay.h"
#include "RTCMatrix.h"
#include <utility>
#include <optional>
namespace RTC
{
class Shape
{
  public:
    virtual std::pair<std::vector<double>, const Shape &> intersect(const Ray &r) = 0;
    std::optional<std::pair<double, Shape &>> hit();
    const Matrix &transformation() const;
    void setTransform(Matrix M);
    void addTransform(Matrix M);
    virtual void restoreTransform() = 0;

  protected:
    std::vector<double> _intersections;
    Matrix _transformation{identityMatrix(4)};
};

class Sphere : public Shape
{
  public:
    Sphere();
    Sphere(Tuple center, double radius);
    Tuple center() const;
    double radius() const;
    std::pair<std::vector<double>, const Shape &> intersect(const Ray &r);
    void restoreTransform();

  protected:
    Tuple _center;
    double _radius;
};

} // namespace RTC
