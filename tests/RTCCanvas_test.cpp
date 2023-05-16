#include "RTCCanvas.h"
#include "RTCColor.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include <cstdint>

TEST_CASE("Canvas, creation", "[Color]")
{
    RTC::Canvas c(10,20);
    RTC::Color r(1,0,0);
    RTC::Color zero(0,0,0);
    REQUIRE(c.width() == 10);
    REQUIRE(c.height() == 20);
    for (auto i = 0; i < 10; i++){
        for(auto j = 0; j <20;j++){
            REQUIRE(c.getPixel(i,j) == zero);
        }
    }
    c.setPixel(2,3,r);
    REQUIRE(c.getPixel(2,3) == r);
}

