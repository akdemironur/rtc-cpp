#include "RTCTuple.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include <cstdint>

TEST_CASE("Tuple, point tests", "[Tuple]") {
  RTC::Tuple a(4.3, -4.2, 3.1, 1.0);
  RTC::Tuple b = RTC::Point(4.3, -4.2, 3.1);
  REQUIRE_THAT(a.x(), Catch::Matchers::WithinAbs(4.3, 1e-8));
  REQUIRE_THAT(a.y(), Catch::Matchers::WithinAbs(-4.2, 1e-8));
  REQUIRE_THAT(a.z(), Catch::Matchers::WithinAbs(3.1, 1e-8));
  REQUIRE_THAT(a.w(), Catch::Matchers::WithinAbs(1.0, 1e-8));
  REQUIRE(a.isPoint());
  REQUIRE(!a.isVector());
  REQUIRE(a == b);
}
TEST_CASE("Tuple, vector tests", "[Tuple]") {
  RTC::Tuple a(4.3, -4.2, 3.1, 0.0);
  RTC::Tuple b = RTC::Vector(4.3, -4.2, 3.1);
  REQUIRE_THAT(a.x(), Catch::Matchers::WithinAbs(4.3, 1e-8));
  REQUIRE_THAT(a.y(), Catch::Matchers::WithinAbs(-4.2, 1e-8));
  REQUIRE_THAT(a.z(), Catch::Matchers::WithinAbs(3.1, 1e-8));
  REQUIRE_THAT(a.w(), Catch::Matchers::WithinAbs(0.0, 1e-8));
  REQUIRE(!a.isPoint());
  REQUIRE(a.isVector());
  REQUIRE(a == b);
}
TEST_CASE("Tuple, addition", "[Tuple]") {
  RTC::Tuple a1(3, -2, 5, 1);
  RTC::Tuple a2(-2, 3, 1, 0);
  REQUIRE((a1 + a2) == RTC::Tuple(1, 1, 6, 1));
}
TEST_CASE("Tuple, subtraction", "[Tuple]") {
  auto p1 = RTC::Point(3, 2, 1);
  auto p2 = RTC::Point(5, 6, 7);
  auto v1 = RTC::Vector(3, 2, 1);
  auto v2 = RTC::Vector(5, 6, 7);
  REQUIRE((p1 - p2) == RTC::Vector(-2, -4, -6));
  REQUIRE((p1 - v2) == RTC::Point(-2, -4, -6));
  REQUIRE((v1 - v2) == RTC::Vector(-2, -4, -6));
}
TEST_CASE("Tuple, negating", "[Tuple]") {
  auto zero = RTC::Vector(0, 0, 0);
  auto v = RTC::Vector(1, -2, 3);
  RTC::Tuple a(1, -2, 3, -4);
  REQUIRE((zero - v) == RTC::Vector(-1, 2, -3));
  REQUIRE(-a == RTC::Tuple(-1, 2, -3, 4));
}
TEST_CASE("Tuple, multiplication with scalar", "[Tuple]") {
  RTC::Tuple a(1, -2, 3, -4);
  REQUIRE(a * 3.5 == RTC::Tuple(3.5, -7, 10.5, -14));
  REQUIRE(3.5 * a == RTC::Tuple(3.5, -7, 10.5, -14));
  REQUIRE(a * 0.5 == RTC::Tuple(0.5, -1, 1.5, -2));
  REQUIRE(0.5 * a == RTC::Tuple(0.5, -1, 1.5, -2));
}
TEST_CASE("Tuple, magnitude", "[Tuple]") {
  auto v = RTC::Vector(1, 0, 0);
  REQUIRE_THAT(v.magnitude(), Catch::Matchers::WithinAbs(1, 1e-8));
  v = RTC::Vector(0, 1, 0);
  REQUIRE_THAT(v.magnitude(), Catch::Matchers::WithinAbs(1, 1e-8));
  v = RTC::Vector(0, 0, 1);
  REQUIRE_THAT(v.magnitude(), Catch::Matchers::WithinAbs(1, 1e-8));
  v = RTC::Vector(1, 2, 3);
  REQUIRE_THAT(v.magnitude(), Catch::Matchers::WithinAbs(std::sqrt(14), 1e-8));
  v = RTC::Vector(-1, -2, -3);
  REQUIRE_THAT(v.magnitude(), Catch::Matchers::WithinAbs(std::sqrt(14), 1e-8));
}

TEST_CASE("Tuple, normalization", "[Tuple]") {
  auto v = RTC::Vector(4, 0, 0);
  REQUIRE(RTC::normalize(v) == RTC::Vector(1, 0, 0));
  v = RTC::Vector(1, 2, 3);
  auto sqrt14 = std::sqrt(14);
  REQUIRE(RTC::normalize(v) == RTC::Vector(1 / sqrt14, 2 / sqrt14, 3 / sqrt14));
  auto norm = RTC::normalize(v);
  REQUIRE_THAT(norm.magnitude(), Catch::Matchers::WithinAbs(1, 1e-8));
}

TEST_CASE("Tuple, dot product", "[Tuple]") {
  auto a = RTC::Vector(1, 2, 3);
  auto b = RTC::Vector(2, 3, 4);
  REQUIRE_THAT(RTC::dot(a, b), Catch::Matchers::WithinAbs(20, 1e-8));
}