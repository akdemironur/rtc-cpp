#include "RTCTuple.h"
#include "RTCCanvas.h"
#include "RTCColor.h"
#include "RTCTransformations.h"
#include "RTCTick.h"
#include <utility>
#include <numbers>
#include <iostream>

int main()
{
    // challenge 1
    auto startPoint = RTC::Point(0, 1, 0);
    auto initialVelocity = (RTC::Vector(1, 1.8, 0).getNorm()) * 11.25;
    std::pair<RTC::Tuple, RTC::Tuple> proj{startPoint, initialVelocity};
    auto gravity = RTC::Vector(0, -0.1, 0);
    auto wind = RTC::Vector(-0.01, 0, 0);
    std::pair<RTC::Tuple, RTC::Tuple> env{gravity, wind};

    RTC::Canvas canvas(900, 550);
    RTC::Color pink(159.0 / 255.0, 43.0 / 255.0, 104.0 / 255.0);

    int y = int(canvas.height() - proj.first.y());
    int x = int(proj.first.x());

    while (x >= 0 && y >= 0 && x <= canvas.width() && y <= canvas.height())
    {
        // std::cout << x << " " << y << std::endl;
        canvas.setPixel(x, y, pink);
        RTC::tick(env, proj);
        y = int(canvas.height() - proj.first.y());
        x = int(proj.first.x());
    }
    canvas.ppmWrite("deneme.ppm");

    // challenge 2
    canvas = RTC::Canvas(50, 50);
    auto p = RTC::Point(20, 0, 0);
    for (auto i = 0; i < 12; i++)
    {
        auto p_insert = p >>= RTC::translation(25, 25, 0);
        canvas.setPixel(p_insert.x(), p_insert.y(), pink);
        p = RTC::rotation_z(std::numbers::pi / 6) * p;
    }
    canvas.ppmWrite("clock.ppm");
    return 0;
}
