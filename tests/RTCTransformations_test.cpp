#include "RTCMatrix.h"
#include <numbers>
#include "RTCTransformations.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include <cstdint>

auto pi = std::numbers::pi;
TEST_CASE("Transformations, translation tests", "[Transformations]")
{
    auto p = RTC::Point(-3, 4, 5);
    auto transform = RTC::translation(5, -3, 2);
    REQUIRE(transform * p == RTC::Point(2, 1, 7));
    transform = transform.getInverse();
    REQUIRE(transform * p == RTC::Point(-8, 7, 3));
    auto v = RTC::Vector(-3, 4, 5);
    REQUIRE(transform * v == v);
}
TEST_CASE("Transformations, scaling tests", "[Transformations]")
{
    auto p = RTC::Point(2, 3, 4);
    auto transform = RTC::scaling(-1, 1, 1);
    REQUIRE(transform * p == RTC::Point(-2, 3, 4));
}
TEST_CASE("Transformations, rotation around x tests", "[Transformations]")
{
    auto p = RTC::Point(0, 1, 0);
    auto half_quarter = RTC::rotation_x(pi / 4);
    auto full_quarter = RTC::rotation_x(pi / 2);
    REQUIRE(half_quarter * p == RTC::Point(0, std::sqrt(2) / 2, std::sqrt(2) / 2));
    REQUIRE(full_quarter * p == RTC::Point(0, 0, 1));
    auto inv = half_quarter.getInverse();
    REQUIRE(inv * p == RTC::Point(0, std::sqrt(2) / 2, -std::sqrt(2) / 2));
}
TEST_CASE("Transformations, rotation around y tests", "[Transformations]")
{
    auto p = RTC::Point(0, 0, 1);
    auto half_quarter = RTC::rotation_y(pi / 4);
    auto full_quarter = RTC::rotation_y(pi / 2);
    REQUIRE(half_quarter * p == RTC::Point(std::sqrt(2) / 2, 0, std::sqrt(2) / 2));
    REQUIRE(full_quarter * p == RTC::Point(1, 0, 0));
}
TEST_CASE("Transformations, rotation around z tests", "[Transformations]")
{
    auto p = RTC::Point(0, 1, 0);
    auto half_quarter = RTC::rotation_z(pi / 4);
    auto full_quarter = RTC::rotation_z(pi / 2);
    REQUIRE(half_quarter * p == RTC::Point(-std::sqrt(2) / 2, std::sqrt(2) / 2, 0));
    REQUIRE(full_quarter * p == RTC::Point(-1, 0, 0));
}
TEST_CASE("Transformations, shearing tests", "[Transformations]")
{
    auto transform = RTC::shearing(1, 0, 0, 0, 0, 0);
    auto p = RTC::Point(2, 3, 4);
    REQUIRE(transform * p == RTC::Point(5, 3, 4));
    transform = RTC::shearing(0, 1, 0, 0, 0, 0);
    REQUIRE(transform * p == RTC::Point(6, 3, 4));
    transform = RTC::shearing(0, 0, 1, 0, 0, 0);
    REQUIRE(transform * p == RTC::Point(2, 5, 4));
    transform = RTC::shearing(0, 0, 0, 1, 0, 0);
    REQUIRE(transform * p == RTC::Point(2, 7, 4));
    transform = RTC::shearing(0, 0, 0, 0, 1, 0);
    REQUIRE(transform * p == RTC::Point(2, 3, 6));
    transform = RTC::shearing(0, 0, 0, 0, 0, 1);
    REQUIRE(transform * p == RTC::Point(2, 3, 7));
}

TEST_CASE("Transformations, chaining tests", "[Transformations]")
{
    auto A = RTC::rotation_x(pi / 2);
    auto B = RTC::scaling(5, 5, 5);
    auto C = RTC::translation(10, 5, 7);
    REQUIRE((A > B > C) == (C * (B * A)));
    auto p = RTC::Point(5, 6, 3);
    REQUIRE((p > A > B > C) == (C * (B * (A * p))));
}
