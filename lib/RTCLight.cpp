#include "RTCLight.h"
namespace RTC
{
Light::Light()
{
    _intensity = RTC::Color();
    _position = RTC::Point(0, 0, 0);
}
Light::Light(Color intensity, Tuple position)
{
    _intensity = intensity;
    _position = position;
}
Color Light::intensity() const
{
    return _intensity;
}
Tuple Light::position() const
{
    return _position;
}
} // namespace RTC