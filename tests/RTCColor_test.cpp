#include "RTCColor.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include <cstdint>

TEST_CASE("Color, creation", "[Color]")
{
    RTC::Color c(-0.5, 0.4, 1.7);
    REQUIRE_THAT(c.red(), Catch::Matchers::WithinAbs(-0.5, 1e-8));
    REQUIRE_THAT(c.green(), Catch::Matchers::WithinAbs(0.4, 1e-8));
    REQUIRE_THAT(c.blue(), Catch::Matchers::WithinAbs(1.7, 1e-8));
}
TEST_CASE("Color, addition", "[Color]")
{
    RTC::Color c1(0.9, 0.6, 0.75);
    RTC::Color c2(0.7, 0.1, 0.25);
    REQUIRE((c1 + c2) == RTC::Color(1.6, 0.7, 1.0));
}
TEST_CASE("Color, subtraction", "[Color]")
{
    RTC::Color c1(0.9, 0.6, 0.75);
    RTC::Color c2(0.7, 0.1, 0.25);
    REQUIRE((c1 - c2) == RTC::Color(0.2, 0.5, 0.5));
}
TEST_CASE("Color, multiplication by scalar", "[Color]")
{
    RTC::Color c(0.2, 0.3, 0.4);
    REQUIRE((c * 2) == RTC::Color(0.4, 0.6, 0.8));
    REQUIRE((2 * c) == RTC::Color(0.4, 0.6, 0.8));
}
TEST_CASE("Color, multiplication ", "[Color]")
{
    RTC::Color c1(1, 0.2, 0.4);
    RTC::Color c2(0.9, 1, 0.1);
    REQUIRE((c1 * c2) == RTC::Color(0.9, 0.2, 0.04));
}
