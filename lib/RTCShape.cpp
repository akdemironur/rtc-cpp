#include "RTCShape.h"
#include "RTCMatrix.h"
#include "RTCTransformations.h"
namespace RTC
{
Tuple Sphere::normalAt(Tuple wp)
{
    auto p = wp >>= transformation().getInverse();
    auto objectNormal = p - _center;
    auto worldNormal = objectNormal >>= transformation().getInverse().transpose();
    return worldNormal.vectorize().getNorm();
}

Sphere::Sphere()
{
    _center = RTC::Point(0, 0, 0);
    _radius = 1;
}
Sphere::Sphere(Tuple center, double radius)
{
    _center = center;
    _radius = radius;
    restoreTransform();
}
std::optional<std::pair<double, Shape &>> Shape::hit()
{
    if (_intersections.size() == 0)
    {
        return {};
    }
    auto i = std::ranges::min_element(_intersections.begin(), _intersections.end());
    std::pair<double, Shape &> j = {*i, *this};
    _intersections.clear();
    return j;
}
std::pair<std::vector<double>, const Shape &> Sphere::intersect(const Ray &r_orig)
{
    auto r = r_orig.transform(this->transformation().getInverse());
    auto sphereToRayVec = r.origin() - Point(0, 0, 0);
    auto a = r.direction().magsqr();
    auto b = 2 * dot(r.direction(), sphereToRayVec);
    auto c = sphereToRayVec.magsqr() - 1;
    auto discriminant = b * b - 4 * a * c;
    std::vector<double> xs;
    if (discriminant < 0)
        return {xs, *this};
    double t1, t2;
    t1 = (-b - std::sqrt(discriminant)) / (2 * a);
    t2 = (-b + std::sqrt(discriminant)) / (2 * a);
    xs.push_back(t1);
    xs.push_back(t2);
    if (t1 >= 0)
        _intersections.push_back(t1);
    if (t2 >= 0)
        _intersections.push_back(t2);
    return {xs, *this};
}
Tuple Sphere::center() const
{
    return _center;
}
double Sphere::radius() const
{
    return _radius;
}
const Matrix &Shape::transformation() const
{
    return _transformation;
}
void Shape::setTransform(Matrix M)
{
    _transformation = M;
}
void Shape::addTransform(Matrix M)
{
    _transformation = _transformation >>= M;
}
void Sphere::restoreTransform()
{
    _transformation = RTC::scaling(_radius, _radius, _radius) >>=
        RTC::translation(_center.x(), _center.y(), _center.z());
}
} // namespace RTC