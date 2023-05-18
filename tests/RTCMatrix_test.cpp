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
TEST_CASE("Matrix, multiplication tests", "[Matrix]")
{
    std::vector<double> values;
    for (auto i = 1; i <= 9; i++)
        values.push_back(i);
    for (auto i = 8; i >= 2; i--)
        values.push_back(i);
    RTC::Matrix A(4, 4, values);
    values.clear();
    values.push_back(-2);
    values.push_back(1);
    values.push_back(2);
    values.push_back(3);
    values.push_back(3);
    values.push_back(2);
    values.push_back(1);
    values.push_back(-1);
    values.push_back(4);
    values.push_back(3);
    values.push_back(6);
    values.push_back(5);
    values.push_back(1);
    values.push_back(2);
    values.push_back(7);
    values.push_back(8);
    RTC::Matrix B(4, 4, values);

    values.clear();
    values.push_back(20);
    values.push_back(22);
    values.push_back(50);
    values.push_back(48);
    values.push_back(44);
    values.push_back(54);
    values.push_back(114);
    values.push_back(108);
    values.push_back(40);
    values.push_back(58);
    values.push_back(110);
    values.push_back(102);
    values.push_back(16);
    values.push_back(26);
    values.push_back(46);
    values.push_back(42);
    RTC::Matrix C(4, 4, values);
    REQUIRE(A * B == C);
}
TEST_CASE("Matrix, multiplication with tuple tests", "[Matrix]")
{
    std::vector<double> values;
    values.push_back(1);
    values.push_back(2);
    values.push_back(3);
    values.push_back(4);
    values.push_back(2);
    values.push_back(4);
    values.push_back(4);
    values.push_back(2);
    values.push_back(8);
    values.push_back(6);
    values.push_back(4);
    values.push_back(1);
    values.push_back(0);
    values.push_back(0);
    values.push_back(0);
    values.push_back(1);
    RTC::Matrix A(4, 4, values);
    RTC::Tuple b(1, 2, 3, 1);
    REQUIRE((A * b) == RTC::columnVector(RTC::Tuple(18, 24, 33, 1)));
}
TEST_CASE("Matrix, tranpose test", "[Matrix]")
{
    std::vector<double> values;
    values.push_back(0);
    values.push_back(9);
    values.push_back(3);
    values.push_back(0);
    values.push_back(9);
    values.push_back(8);
    values.push_back(0);
    values.push_back(8);
    values.push_back(1);
    values.push_back(8);
    values.push_back(5);
    values.push_back(3);
    values.push_back(0);
    values.push_back(0);
    values.push_back(5);
    values.push_back(8);
    RTC::Matrix A(4, 4, values);
    values.clear();
    values.push_back(0);
    values.push_back(9);
    values.push_back(1);
    values.push_back(0);
    values.push_back(9);
    values.push_back(8);
    values.push_back(8);
    values.push_back(0);
    values.push_back(3);
    values.push_back(0);
    values.push_back(5);
    values.push_back(5);
    values.push_back(0);
    values.push_back(8);
    values.push_back(3);
    values.push_back(8);
    RTC::Matrix A_transposed(4, 4, values);
    REQUIRE(A.transpose() == A_transposed);
}
