#pragma once
#include <optional>
#include "RTCLight.h"
#include "RTCShape.h"
namespace RTC
{
class World
{
  public:
    int numOfObjects() const;
    std::optional<RTC::Light> lightSource;

  protected:
    std::vector<Shape> _objects;
};

} // namespace RTC
