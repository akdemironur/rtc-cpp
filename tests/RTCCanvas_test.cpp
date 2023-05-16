#include "RTCCanvas.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include <cstdint>

TEST_CASE("Canvas, creation", "[Canvas]")
{
    RTC::Canvas c(4, 4);
    RTC::Color r(1, 0, 0);
    RTC::Color zero(0, 0, 0);
    REQUIRE(c.width() == 4);
    REQUIRE(c.height() == 4);
    for (auto i = 0; i < 4; i++)
    {
        for (auto j = 0; j < 4; j++)
        {
            REQUIRE(c.getPixel(i, j) == zero);
        }
    }
    c.setPixel(2, 3, r);
    REQUIRE(c.getPixel(2, 3) == r);
}
