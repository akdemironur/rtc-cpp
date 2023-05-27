#include "RTCLight.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include <cstdint>

TEST_CASE("Light creation", "[light]")
{
    auto intensity = RTC::Color(1, 1, 1);
    auto position = RTC::Point(0, 0, 0);
    auto light = RTC::Light(intensity, position);
    REQUIRE(light.intensity() == intensity);
    REQUIRE(light.position() == position);
}
