#include "RTCTransformations.h"
#include <math.h>
namespace RTC
{
Matrix translation(double x, double y, double z)
{
    auto A = identityMatrix(4);
    A(0, 3) = x;
    A(1, 3) = y;
    A(2, 3) = z;
    return A;
}
Matrix scaling(double x, double y, double z)
{
    auto A = identityMatrix(4);
    A(0, 0) = x;
    A(1, 1) = y;
    A(2, 2) = z;
    return A;
}
Matrix rotation_x(double radAngle)
{
    auto A = identityMatrix(4);
    A(1, 1) = std::cos(radAngle);
    A(1, 2) = -std::sin(radAngle);
    A(2, 1) = std::sin(radAngle);
    A(2, 2) = std::cos(radAngle);
    return A;
}
Matrix rotation_y(double radAngle)
{
    auto A = identityMatrix(4);
    A(0, 0) = std::cos(radAngle);
    A(2, 0) = -std::sin(radAngle);
    A(0, 2) = std::sin(radAngle);
    A(2, 2) = std::cos(radAngle);
    return A;
}
Matrix rotation_z(double radAngle)
{
    auto A = identityMatrix(4);
    A(0, 0) = std::cos(radAngle);
    A(0, 1) = -std::sin(radAngle);
    A(1, 0) = std::sin(radAngle);
    A(1, 1) = std::cos(radAngle);
    return A;
}
Matrix shearing(double xy, double xz, double yx, double yz, double zx, double zy)
{
    auto A = identityMatrix(4);
    A(0, 1) = xy;
    A(0, 2) = xz;
    A(1, 0) = yx;
    A(1, 2) = yz;
    A(2, 0) = zx;
    A(2, 1) = zy;
    return A;
}
Tuple operator>(const Tuple &b, const Matrix &A)
{
    return A * b;
}
Matrix operator>(const Matrix &B, const Matrix &A)
{
    return A * B;
}
} // namespace RTC