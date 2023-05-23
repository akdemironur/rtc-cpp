#include "RTCMaterial.h"
namespace RTC
{

Material::Material()
{
}
Material::Material(double ambient, double diffuse, double specular, double shininess, Color color)
{
    _ambient = ambient;
    _diffuse = diffuse;
    _specular = specular;
    _shininess = shininess;
    _color = color;
}
double Material::ambient() const
{
    return _ambient;
}
double Material::diffuse() const
{
    return _diffuse;
}
double Material::specular() const
{
    return _specular;
}
double Material::shininess() const
{
    return _shininess;
}
Color Material::color() const
{
    return _color;
}
void Material::setAmbient(double ambient)
{
    _ambient = ambient;
}
void Material::setDiffuse(double diffuse)
{
    _diffuse = diffuse;
}
void Material::setSpecular(double specular)
{
    _specular = specular;
}
void Material::setShininess(double shininess)
{
    _shininess = shininess;
}
void Material::setColor(Color color)
{
    _color = color;
}
} // namespace RTC