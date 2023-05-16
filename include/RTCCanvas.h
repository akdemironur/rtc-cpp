#pragma once
#include "RTCColor.h"
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
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
    Color getPixel(int i, int j) const
    {
        if (i >= 0 && j >= 0 && i < _w && j < _h)
            return _pixels[j][i];

        std::cout << "Coordinates are out of bounds!" << std::endl;
        return Color(-1, -1, -1);
    }
    void setPixel(int i, int j, Color c)
    {
        if (i >= 0 && j >= 0 && i < _w && j < _h)
            _pixels[j][i] = c;
        else
            std::cout << "Coordinates are out of bounds!" << std::endl;
    }
    std::string ppmHeader() const
    {
        std::ostringstream oss;
        oss << "P3" << std::endl << _w << " " << _h << std::endl << 255 << std::endl;
        return oss.str();
    }
    std::string ppmColors() const
    {
        std::ostringstream oss;
        for (auto pp : _pixels)
        {
            for (auto p : pp)
            {
                oss << p << std::endl;
            }
        }
        return oss.str();
    }
    void ppmWrite(const std::string &fileName)
    {
        std::ofstream fileToWrite;
        fileToWrite.open(fileName);
        fileToWrite << ppmHeader() << std::endl << ppmColors();
        fileToWrite.close();
    }

  protected:
    int _w;
    int _h;
    std::vector<std::vector<Color>> _pixels;
};

} // namespace RTC
