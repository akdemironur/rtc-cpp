#include "RTCShape.h"
namespace RTC
{
Sphere::Sphere()
{
    _center = RTC::Point(0, 0, 0);
    _radius = 1;
}
Sphere::Sphere(Tuple center, double radius)
{
    _center = center;
    _radius = radius;
}

std::pair<std::vector<double>, const Sphere &> Sphere::intersect(const Ray &r)
{
    auto sphereToRayVec = r.origin() - center();
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
    _intersections.push_back(t1);
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
} // namespace RTC