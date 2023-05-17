#include "RTCMatrix.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include <cstdint>

TEST_CASE("Matrix, creation tests", "[Matrix]")
{
    std::vector<double> values;
    values.push_back(1);
    values.push_back(2);
    values.push_back(3);
    values.push_back(4);
    values.push_back(5.5);
    values.push_back(6.5);
    values.push_back(7.5);
    values.push_back(8.5);
    values.push_back(9);
    values.push_back(10);
    values.push_back(11);
    values.push_back(12);
    values.push_back(13.5);
    values.push_back(14.5);
    values.push_back(15.5);
    values.push_back(16.5);
    RTC::Matrix M(4, 4, values);
    REQUIRE_THAT(M(0, 0), Catch::Matchers::WithinAbs(1, 1e-8));
    REQUIRE_THAT(M(0, 3), Catch::Matchers::WithinAbs(4, 1e-8));
    REQUIRE_THAT(M(1, 0), Catch::Matchers::WithinAbs(5.5, 1e-8));
    REQUIRE_THAT(M(1, 2), Catch::Matchers::WithinAbs(7.5, 1e-8));
    REQUIRE_THAT(M(2, 2), Catch::Matchers::WithinAbs(11, 1e-8));
    REQUIRE_THAT(M(3, 0), Catch::Matchers::WithinAbs(13.5, 1e-8));
    REQUIRE_THAT(M(3, 2), Catch::Matchers::WithinAbs(15.5, 1e-8));

    values.clear();
    values.push_back(-3);
    values.push_back(5);
    values.push_back(1);
    values.push_back(-2);
    M = RTC::Matrix(2, 2, values);
    REQUIRE_THAT(M(0, 0), Catch::Matchers::WithinAbs(-3, 1e-8));
    REQUIRE_THAT(M(0, 1), Catch::Matchers::WithinAbs(5, 1e-8));
    REQUIRE_THAT(M(1, 0), Catch::Matchers::WithinAbs(1, 1e-8));
    REQUIRE_THAT(M(1, 1), Catch::Matchers::WithinAbs(-2, 1e-8));

    values.clear();
    values.push_back(-3);
    values.push_back(5);
    values.push_back(0);
    values.push_back(1);
    values.push_back(-2);
    values.push_back(-7);
    values.push_back(0);
    values.push_back(1);
    values.push_back(1);
    M = RTC::Matrix(3, 3, values);
    REQUIRE_THAT(M(0, 0), Catch::Matchers::WithinAbs(-3, 1e-8));
    REQUIRE_THAT(M(1, 1), Catch::Matchers::WithinAbs(-2, 1e-8));
    REQUIRE_THAT(M(2, 2), Catch::Matchers::WithinAbs(1, 1e-8));
    M(2, 2) = 7;
    REQUIRE_THAT(M(2, 2), Catch::Matchers::WithinAbs(7, 1e-8));

    std::vector<double> vals1, vals2;
    vals1.push_back(1);
    vals1.push_back(2);
    vals1.push_back(3);
    vals1.push_back(4);
    vals1.push_back(5);
    vals1.push_back(6);
    vals1.push_back(7);
    vals1.push_back(8);
    vals1.push_back(9);
    vals2.push_back(1);
    vals2.push_back(2);
    vals2.push_back(3);
    vals2.push_back(4);
    vals2.push_back(5);
    vals2.push_back(6);
    vals2.push_back(7);
    vals2.push_back(8);
    vals2.push_back(9);
    RTC::Matrix A(3, 3, vals1);
    RTC::Matrix B(3, 3, vals2);
    REQUIRE(A == B);
    REQUIRE(A != M);
}
