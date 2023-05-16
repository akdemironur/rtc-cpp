#include "RTCCanvas.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include <cstdint>
#include <string>
#include <sstream>
#include <iostream>

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
TEST_CASE("Canvas, ppm header", "[Canvas]")
{
    RTC::Canvas c(4, 4);
    RTC::Color r(1, 0, 0);
    RTC::Color zero(0, 0, 0);
    REQUIRE(c.width() == 4);
    REQUIRE(c.height() == 4);
    std::ostringstream oss;
    oss << "P3" << std::endl << 4 << " " << 4 << std::endl << 255 << std::endl;
    REQUIRE(c.ppmHeader().compare(oss.str()) == 0);
}
TEST_CASE("Canvas, ppm colors", "[Canvas]")
{
    RTC::Canvas c(5, 3);
    RTC::Color c1(1.5, 0, 0);
    RTC::Color c2(0, 0.5, 0);
    RTC::Color c3(-0.5, 0, 1);
    c.setPixel(0, 0, c1);
    c.setPixel(2, 1, c2);
    c.setPixel(4, 2, c3);
    std::ostringstream oss;
    oss << "255 0 0" << std::endl;
    oss << "0 0 0" << std::endl;
    oss << "0 0 0" << std::endl;
    oss << "0 0 0" << std::endl;
    oss << "0 0 0" << std::endl;
    oss << "0 0 0" << std::endl;
    oss << "0 0 0" << std::endl;
    oss << "0 128 0" << std::endl;
    oss << "0 0 0" << std::endl;
    oss << "0 0 0" << std::endl;
    oss << "0 0 0" << std::endl;
    oss << "0 0 0" << std::endl;
    oss << "0 0 0" << std::endl;
    oss << "0 0 0" << std::endl;
    oss << "0 0 255" << std::endl;
    REQUIRE(c.ppmColors().compare(oss.str()) == 0);
}
