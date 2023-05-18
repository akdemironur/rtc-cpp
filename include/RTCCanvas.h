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
    Canvas(int w, int h);
    int width() const;
    int height() const;
    Color getPixel(int i, int j) const;
    void setPixel(int i, int j, Color c);
    std::string ppmHeader() const;
    std::string ppmColors() const;
    void ppmWrite(const std::string &fileName);

  protected:
    int _w;
    int _h;
    std::vector<std::vector<Color>> _pixels;
};

} // namespace RTC
