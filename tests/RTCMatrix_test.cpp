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
    REQUIRE(A * RTC::identityMatrix(4) == A);
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
    auto id4 = RTC::identityMatrix(4);
    auto id42 = id4;
    REQUIRE(id4.transpose() == id42);
}
TEST_CASE("Matrix, determinant test", "[Matrix]")
{
    std::vector<double> values;
    values.push_back(1);
    values.push_back(5);
    values.push_back(-3);
    values.push_back(2);
    RTC::Matrix A(2, 2, values);
    REQUIRE_THAT(A.determinant(), Catch::Matchers::WithinAbs(17, 1e-8));
}
TEST_CASE("Matrix, submatrix test", "[Matrix]")
{

    std::vector<double> values;
    values.push_back(1);
    values.push_back(5);
    values.push_back(0);
    values.push_back(-3);
    values.push_back(2);
    values.push_back(7);
    values.push_back(0);
    values.push_back(6);
    values.push_back(-3);
    RTC::Matrix A(3, 3, values);
    values.clear();
    values.push_back(-3);
    values.push_back(2);
    values.push_back(0);
    values.push_back(6);
    RTC::Matrix A_sub(2, 2, values);
    REQUIRE(A.submatrix(0, 2) == A_sub);

    values.clear();
    values.insert(values.end(), {-6, 1, 1, 6, -8, 5, 8, 6, -1, 0, 8, 2, -7, 1, -1, 1});
    RTC::Matrix B(4, 4, values);
    values.clear();
    values.insert(values.end(), {-6, 1, 6, -8, 8, 6, -7, -1, 1});
    RTC::Matrix B_sub(3, 3, values);
    REQUIRE(B.submatrix(2, 1) == B_sub);
}
TEST_CASE("Matrix, minor/cofactor test", "[Matrix]")
{
    std::vector<double> values;
    values.insert(values.end(), {3, 5, 0, 2, -1, -7, 6, -1, 5});
    RTC::Matrix A(3, 3, values);
    auto B = A.submatrix(1, 0);
    REQUIRE_THAT(B.determinant(), Catch::Matchers::WithinAbs(25, 1e-8));
    REQUIRE_THAT(A.minor(1, 0), Catch::Matchers::WithinAbs(25, 1e-8));
    REQUIRE_THAT(A.cofactor(1, 0), Catch::Matchers::WithinAbs(-25, 1e-8));
    REQUIRE_THAT(A.minor(0, 0), Catch::Matchers::WithinAbs(-12, 1e-8));
    REQUIRE_THAT(A.cofactor(0, 0), Catch::Matchers::WithinAbs(-12, 1e-8));
}

TEST_CASE("Matrix, minor/cofactor/det test", "[Matrix]")
{
    std::vector<double> values;
    values.insert(values.end(), {1, 2, 6, -5, 8, -4, 2, 6, 4});
    RTC::Matrix A(3, 3, values);
    REQUIRE_THAT(A.cofactor(0, 0), Catch::Matchers::WithinAbs(56, 1e-8));
    REQUIRE_THAT(A.cofactor(0, 1), Catch::Matchers::WithinAbs(12, 1e-8));
    REQUIRE_THAT(A.cofactor(0, 2), Catch::Matchers::WithinAbs(-46, 1e-8));
    REQUIRE_THAT(A.determinant(), Catch::Matchers::WithinAbs(-196, 1e-8));
    values.clear();
    values.insert(values.end(), {-2, -8, 3, 5, -3, 1, 7, 3, 1, 2, -9, 6, -6, 7, 7, -9});
    A = RTC::Matrix(4, 4, values);
    REQUIRE_THAT(A.cofactor(0, 0), Catch::Matchers::WithinAbs(690, 1e-8));
    REQUIRE_THAT(A.cofactor(0, 1), Catch::Matchers::WithinAbs(447, 1e-8));
    REQUIRE_THAT(A.cofactor(0, 2), Catch::Matchers::WithinAbs(210, 1e-8));
    REQUIRE_THAT(A.cofactor(0, 3), Catch::Matchers::WithinAbs(51, 1e-8));
    REQUIRE_THAT(A.determinant(), Catch::Matchers::WithinAbs(-4071, 1e-8));
}
