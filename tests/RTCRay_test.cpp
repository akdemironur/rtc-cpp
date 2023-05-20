#include "RTCMatrix.h"
#include "RTCTransformations.h"
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
TEST_CASE("Ray, hit sphere", "[Matrix]")
{
    auto s = RTC::Sphere();
    auto r = RTC::Ray(RTC::Point(0, 0, 5), RTC::Vector(0, 0, 1));
    s.intersect(r);
    r = RTC::Ray(RTC::Point(0, 0, 0), RTC::Vector(0, 0, 1));
    s.intersect(r);
    r = RTC::Ray(RTC::Point(0, 2, -5), RTC::Vector(0, 0, 1));
    s.intersect(r);
    REQUIRE_THAT(s.hit().value().first, Catch::Matchers::WithinAbs(1, 1e-8));
    s = RTC::Sphere();
    r = RTC::Ray(RTC::Point(0, 0, 5), RTC::Vector(0, 0, 1));
    s.intersect(r);
    REQUIRE(s.hit() == std::nullopt);
}
TEST_CASE("Ray, transform", "[Matrix]")
{
    auto r = RTC::Ray(RTC::Point(1, 2, 3), RTC::Vector(0, 1, 0));
    auto M = RTC::translation(3, 4, 5);
    auto r2 = r.transform(M);
    REQUIRE(r2.origin() == RTC::Point(4, 6, 8));
    REQUIRE(r2.direction() == RTC::Vector(0, 1, 0));
    M = RTC::scaling(2, 3, 4);
    r2 = r.transform(M);
    REQUIRE(r2.origin() == RTC::Point(2, 6, 12));
    REQUIRE(r2.direction() == RTC::Vector(0, 3, 0));
}
TEST_CASE("Sphere, transform", "[Matrix]")
{
    auto s = RTC::Sphere();
    REQUIRE(s.transformation() == RTC::identityMatrix(4));
    auto t = RTC::translation(2, 3, 4);
    s.setTransform(t);
    REQUIRE(s.transformation() == t);
    auto r = RTC::Ray(RTC::Point(0, 0, -5), RTC::Vector(0, 0, 1));
    s = RTC::Sphere();
    s.setTransform(RTC::scaling(2, 2, 2));
    auto xs = s.intersect(r);
    REQUIRE(xs.first.size() == 2);
    REQUIRE_THAT(xs.first[0], Catch::Matchers::WithinAbs(3, 1e-8));
    REQUIRE_THAT(xs.first[1], Catch::Matchers::WithinAbs(7, 1e-8));
}
TEST_CASE("Sphere, transform ray", "[Matrix]")
{
    auto s = RTC::Sphere();
    auto r = RTC::Ray(RTC::Point(0, 0, -5), RTC::Vector(0, 0, 1));
    s.setTransform(RTC::translation(5, 0, 0));
    auto xs = s.intersect(r);
    REQUIRE(xs.first.size() == 0);
}
