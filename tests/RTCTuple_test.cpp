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
  auto v = RTC::Vector(5, 6, 7);
  REQUIRE((p1 - p2) == RTC::Vector(-2, -4, -6));
  REQUIRE((p1 - v) == RTC::Point(-2, -4, -6));
}
