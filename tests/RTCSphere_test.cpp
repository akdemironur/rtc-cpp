#include "RTCMatrix.h"
#include "RTCTransformations.h"
#include "RTCTuple.h"
#include "RTCShape.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include <cstdint>
#include <iostream>
#include <numbers>

TEST_CASE("Sphere normal at", "[Matrix]")
{
    auto s = RTC::Sphere();
    auto n = s.normalAt(RTC::Point(1, 0, 0));
    REQUIRE(n == RTC::Vector(1, 0, 0));
    n = s.normalAt(RTC::Point(0, 1, 0));
    REQUIRE(n == RTC::Vector(0, 1, 0));
    n = s.normalAt(RTC::Point(0, 0, 1));
    REQUIRE(n == RTC::Vector(0, 0, 1));
    n = s.normalAt(RTC::Point(std::sqrt(3) / 3, std::sqrt(3) / 3, std::sqrt(3) / 3));
    REQUIRE(n == RTC::Vector(std::sqrt(3) / 3, std::sqrt(3) / 3, std::sqrt(3) / 3));
    REQUIRE(n == n.getNorm());
    // s.setTransform(RTC::translation(0, 1, 0));
    // n = s.normalAt(RTC::Point(0, 1.70711, -0.70711));
    // REQUIRE(n == RTC::Vector(0, 0.70711, -0.70711));
    s.setTransform(RTC::rotation_z(std::numbers::pi / 5) >>= RTC::scaling(1, 0.5, 1));
    n = s.normalAt(RTC::Point(0, std::sqrt(2) / 2, -std::sqrt(2) / 2));
    REQUIRE(n == RTC::Vector(0, 0.97014, -0.24254));
}
