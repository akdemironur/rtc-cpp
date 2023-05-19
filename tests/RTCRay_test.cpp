#include "RTCTuple.h"
#include "RTCShape.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include <cstdint>

TEST_CASE("Ray, creation tests", "[Matrix]")
{
    auto origin = RTC::Point(1, 2, 3);
    auto direction = RTC::Vector(4, 5, 6);
    RTC::Ray r(origin, direction);
    REQUIRE(r.origin() == origin);
    REQUIRE(r.direction() == direction);
}
TEST_CASE("Ray, distance tests", "[Matrix]")
{
    auto origin = RTC::Point(2, 3, 4);
    auto direction = RTC::Vector(1, 0, 0);
    RTC::Ray r(origin, direction);
    REQUIRE(r.position(0) == RTC::Point(2, 3, 4));
    REQUIRE(r.position(1) == RTC::Point(3, 3, 4));
    REQUIRE(r.position(-1) == RTC::Point(1, 3, 4));
    REQUIRE(r.position(2.5) == RTC::Point(4.5, 3, 4));
}

TEST_CASE("Ray, intersection with sphere 2 points", "[Matrix]")
{
    auto r = RTC::Ray(RTC::Point(0, 0, -5), RTC::Vector(0, 0, 1));
    auto s = RTC::Sphere();
    auto xs = s.intersect(r);
    REQUIRE(xs.first.size() == 2);
    REQUIRE_THAT(xs.first[0], Catch::Matchers::WithinAbs(4, 1e-8));
    REQUIRE_THAT(xs.first[1], Catch::Matchers::WithinAbs(6, 1e-8));
}

TEST_CASE("Ray, intersection with sphere tangent", "[Matrix]")
{
    auto r = RTC::Ray(RTC::Point(0, 1, -5), RTC::Vector(0, 0, 1));
    auto s = RTC::Sphere();
    auto xs = s.intersect(r);
    REQUIRE(xs.first.size() == 2);
    REQUIRE_THAT(xs.first[0], Catch::Matchers::WithinAbs(5, 1e-8));
    REQUIRE_THAT(xs.first[1], Catch::Matchers::WithinAbs(5, 1e-8));
}
TEST_CASE("Ray, ray misses sphere", "[Matrix]")
{
    auto r = RTC::Ray(RTC::Point(0, 2, -5), RTC::Vector(0, 0, 1));
    auto s = RTC::Sphere();
    auto xs = s.intersect(r);
    REQUIRE(xs.first.size() == 0);
}
TEST_CASE("Ray, ray originates inside sphere", "[Matrix]")
{
    auto r = RTC::Ray(RTC::Point(0, 0, 0), RTC::Vector(0, 0, 1));
    auto s = RTC::Sphere();
    auto xs = s.intersect(r);
    REQUIRE(xs.first.size() == 2);
    REQUIRE_THAT(xs.first[0], Catch::Matchers::WithinAbs(-1, 1e-8));
    REQUIRE_THAT(xs.first[1], Catch::Matchers::WithinAbs(1, 1e-8));
}
TEST_CASE("Ray, ray behind sphere", "[Matrix]")
{
    auto r = RTC::Ray(RTC::Point(0, 0, 5), RTC::Vector(0, 0, 1));
    auto s = RTC::Sphere();
    auto xs = s.intersect(r);
    REQUIRE(xs.first.size() == 2);
    REQUIRE_THAT(xs.first[0], Catch::Matchers::WithinAbs(-6, 1e-8));
    REQUIRE_THAT(xs.first[1], Catch::Matchers::WithinAbs(-4, 1e-8));
}
