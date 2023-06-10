#include "RTCWorld.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include <cstdint>

TEST_CASE("World, creation", "[World]")
{
    auto w = RTC::World();
    REQUIRE(w.numOfObjects() == 0);
    REQUIRE(w.lightSource == RTC::Light());
}
