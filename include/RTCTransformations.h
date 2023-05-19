#pragma once
#include "RTCMatrix.h"
namespace RTC
{
extern Matrix translation(double x, double y, double z);
extern Matrix scaling(double x, double y, double z);
extern Matrix rotation_x(double radAngle);
extern Matrix rotation_y(double radAngle);
extern Matrix rotation_z(double radAngle);
extern Matrix shearing(double xy, double xz, double yx, double yz, double zx, double zy);
extern Tuple operator>(const Tuple &b, const Matrix &A);
extern Matrix operator>(const Matrix &B, const Matrix &A);
} // namespace RTC
