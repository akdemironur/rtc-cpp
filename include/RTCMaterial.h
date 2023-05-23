#pragma once
#include "RTCColor.h"
namespace RTC
{
class Material
{
  public:
    Material();
    Material(double ambient, double diffuse, double specular, double shininess, Color color);
    double ambient() const;
    double diffuse() const;
    double specular() const;
    double shininess() const;
    Color color() const;
    void setAmbient(double ambient);
    void setDiffuse(double diffuse);
    void setSpecular(double specular);
    void setShininess(double shininess);
    void setColor(Color color);

  protected:
    double _ambient{0.1};
    double _diffuse{0.9};
    double _specular{0.9};
    double _shininess{200.0};
    Color _color{RTC::Color(1, 1, 1)};
};
} // namespace RTC
