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
