#pragma once
#include "RTCColor.h"
#include "RTCTuple.h"
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

} // namespace RTC
