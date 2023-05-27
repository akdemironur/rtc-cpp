#include "RTCLight.h"
#include "RTCTuple.h"
#include "RTCCanvas.h"
#include "RTCColor.h"
#include "RTCTransformations.h"
#include "RTCTick.h"
#include "RTCRay.h"
#include "RTCShape.h"
#include "RTCMaterial.h"
#include "RTCLight.h"
#include <utility>
#include <numbers>
#include <iostream>

int main()
{
    auto rayOrigin = RTC::Point(0, 0, -5);
    auto wallZ = 10.0;
    auto wallSize = 7.0;
    auto canvasPixels = 800;
    auto pixelSize = wallSize / canvasPixels;
    auto half = wallSize / 2.0;
    auto canvas = RTC::Canvas(canvasPixels, canvasPixels);
    auto color = RTC::Color(1, 0, 0);
    auto shape = RTC::Sphere();
    shape.material.setColor(RTC::Color(37.0 / 255.0, 150.0 / 255.0, 190.0 / 255.0));
    auto lightPosition = RTC::Point(-10, 10, -10);
    auto lightColor = RTC::Color(1, 1, 1);
    auto light = RTC::Light(lightColor, lightPosition);

    for (int y = 0; y < canvasPixels; y++)
    {
        auto worldY = half - pixelSize * y;
        for (int x = 0; x < canvasPixels; x++)
        {
            auto worldX = -half + pixelSize * x;
            auto position = RTC::Point(worldX, worldY, wallZ);
            auto r = RTC::Ray(rayOrigin, (position - rayOrigin).getNorm());
            shape.intersect(r);
            auto h = shape.hit();
            if (h != std::nullopt)
            {
                auto point = r.position(h.value().first);
                auto normal = shape.normalAt(point);
                auto eye = -r.direction();
                auto c = RTC::lighting(shape.material, light, point, eye, normal);
                canvas.setPixel(x, y, c);
            }
        }
    }
    canvas.ppmWrite("sphere.ppm");
    return 0;
}
