#pragma once
#include "RTCTuple.h"
#include "RTCRay.h"
#include "RTCMatrix.h"
#include "RTCMaterial.h"
#include <utility>
#include <optional>
#include <algorithm>
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
    virtual Tuple normalAt(Tuple p) = 0;
    Material material{};

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
    Tuple normalAt(Tuple p);

  protected:
    Tuple _center;
    double _radius;
};

} // namespace RTC
