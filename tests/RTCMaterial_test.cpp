#include "RTCLight.h"
#include "RTCMaterial.h"
#include "RTCTuple.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include <cstdint>

TEST_CASE("Material, creation", "[Material]")
{
    auto m = RTC::Material();
    REQUIRE(m.color() == RTC::Color(1, 1, 1));
    REQUIRE_THAT(m.ambient(), Catch::Matchers::WithinAbs(0.1, 1e-8));
    REQUIRE_THAT(m.diffuse(), Catch::Matchers::WithinAbs(0.9, 1e-8));
    REQUIRE_THAT(m.specular(), Catch::Matchers::WithinAbs(0.9, 1e-8));
    REQUIRE_THAT(m.shininess(), Catch::Matchers::WithinAbs(200.0, 1e-8));
}
TEST_CASE("Material lighting", "[Material]")
{
    auto m = RTC::Material();
    auto position = RTC::Point(0, 0, 0);
    auto eyev = RTC::Vector(0, 0, -1);
    auto normalv = RTC::Vector(0, 0, -1);
    auto light = RTC::Light(RTC::Color(1, 1, 1), RTC::Point(0, 0, -10));
    auto result = RTC::lighting(m, light, position, eyev, normalv);
    REQUIRE(result == RTC::Color(1.9, 1.9, 1.9));

    eyev = RTC::Vector(0, std::sqrt(2) / 2, -std::sqrt(2) / 2);
    normalv = RTC::Vector(0, 0, -1);
    light = RTC::Light(RTC::Color(1, 1, 1), RTC::Point(0, 0, -10));
    result = RTC::lighting(m, light, position, eyev, normalv);
    REQUIRE(result == RTC::Color(1.0, 1.0, 1.0));

    eyev = RTC::Vector(0, 0, -1);
    normalv = RTC::Vector(0, 0, -1);
    light = RTC::Light(RTC::Color(1, 1, 1), RTC::Point(0, 10, -10));
    result = RTC::lighting(m, light, position, eyev, normalv);
    REQUIRE(result == RTC::Color(0.7364, 0.7364, 0.7364));

    eyev = RTC::Vector(0, -std::sqrt(2) / 2, -std::sqrt(2) / 2);
    normalv = RTC::Vector(0, 0, -1);
    light = RTC::Light(RTC::Color(1, 1, 1), RTC::Point(0, 10, -10));
    result = RTC::lighting(m, light, position, eyev, normalv);
    REQUIRE(result == RTC::Color(1.6364, 1.6364, 1.6364));

    eyev = RTC::Vector(0, 0, -1);
    normalv = RTC::Vector(0, 0, -1);
    light = RTC::Light(RTC::Color(1, 1, 1), RTC::Point(0, 0, 10));
    result = RTC::lighting(m, light, position, eyev, normalv);
    REQUIRE(result == RTC::Color(0.1, 0.1, 0.1));
}
