#include "RTCTuple.h"
#include <catch2/catch_test_macros.hpp>
#include <cstdint>

TEST_CASE("Tuple, point tests", "[Tuple]") {
  RTC::Tuple a(4.3, -4.2, 3.1, 1.0);
  RTC::Tuple b = RTC::Point(4.3, -4.2, 3.1);
  REQUIRE(a.x() == Approx(4.3));
  REQUIRE(a.y() == Approx(-4.2));
  REQUIRE(a.z() == Approx(3.1));
  REQUIRE(a.w() == Approx(1.0));
  REQUIRE(a.isPoint());
  REQUIRE(!a.isVector());
  REQUIRE(a == b);
}
TEST_CASE("Tuple, vector tests", "[Tuple]") {
  RTC::Tuple a(4.3, -4.2, 3.1, 0.0);
  RTC::Tuple b = RTC::Vector(4.3, -4.2, 3.1);
  REQUIRE(a.x() == Approx(4.3));
  REQUIRE(a.y() == Approx(-4.2));
  REQUIRE(a.z() == Approx(3.1));
  REQUIRE(a.w() == Approx(1.0));
  REQUIRE(!a.isPoint());
  REQUIRE(a.isVector());
  REQUIRE(a == b);
}
