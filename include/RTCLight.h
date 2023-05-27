#pragma once
#include "RTCColor.h"
#include "RTCTuple.h"
#include "RTCMaterial.h"
namespace RTC
{
class Light
{
  public:
    Light();
    Light(Color intensity, Tuple position);
    Color intensity() const;
    Tuple position() const;

  protected:
    Color _intensity;
    Tuple _position;
};

extern Color lighting(Material material, Light light, Tuple point, Tuple eyev, Tuple normalv);
} // namespace RTC
