#pragma once
#include "RTCColor.h"
#include <vector>
namespace RTC
{
class Canvas
{
  public:
    Canvas(int w, int h)
    {
        _w = w;
        _h = h;

        Color zero(0, 0, 0);
        std::vector<Color> zeroVec;

        for (auto j = 0; j < _h; j++)
        {
            _pixels.push_back(zeroVec);
            for (auto i = 0; i < _w; i++)
            {
                _pixels[j].push_back(zero);
            }
        }
    }
    int width() const
    {
        return _w;
    }
    int height() const
    {
        return _h;
    }
    Color getPixel(int j, int i) const
    {
        return _pixels[j][i];
    }
    void setPixel(int j, int i, Color c)
    {
        _pixels[j][i] = c;
    }

  protected:
    int _w;
    int _h;
    std::vector<std::vector<Color>> _pixels;
};

} // namespace RTC
