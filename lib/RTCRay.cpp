#include "RTCRay.h"
namespace RTC
{

Ray::Ray()
{
    _origin = Point(0, 0, 0);
    _direction = Vector(0, 0, 0);
}
Ray::Ray(Tuple origin, Tuple direction)
{
    _origin = origin;
    _direction = direction;
}
Tuple Ray::origin() const
{
    return _origin;
}
Tuple Ray::direction() const
{
    return _direction;
}
Tuple Ray::position(double t) const
{
    return origin() + direction() * t;
}
Ray Ray::transform(Matrix M) const
{
    return Ray(M * origin(), M * direction());
}
} // namespace RTC