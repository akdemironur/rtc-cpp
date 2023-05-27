#include "RTCLight.h"
#include "RTCTuple.h"
namespace RTC
{
Light::Light()
{
    _intensity = RTC::Color();
    _position = RTC::Point(0, 0, 0);
}
Light::Light(Color intensity, Tuple position)
{
    _intensity = intensity;
    _position = position;
}
Color Light::intensity() const
{
    return _intensity;
}
Tuple Light::position() const
{
    return _position;
}
Color lighting(Material material, Light light, Tuple point, Tuple eyev, Tuple normalv)
{
    Color resultLight;
    Tuple effectiveColor = material.color() * light.intensity();
    Tuple lightv = (light.position() - point).getNorm();
    Tuple ambient = effectiveColor * material.ambient();
    double lightDotNormal = dot(lightv, normalv);
    Tuple diffuse, specular;
    if (lightDotNormal < 0)
    {
        diffuse = Point(0, 0, 0);
        specular = Point(0, 0, 0);
    }
    else
    {
        diffuse = effectiveColor * material.diffuse() * lightDotNormal;

        Tuple reflectv = reflect(-lightv, normalv);
        double reflectDotEye = dot(reflectv, eyev);
        if (reflectDotEye <= 0)
        {
            specular = Color();
        }
        else
        {
            double factor = std::pow(reflectDotEye, material.shininess());
            specular = light.intensity() * material.specular() * factor;
        }
    }
    resultLight = ambient + diffuse + specular;
    return resultLight;
}
} // namespace RTC