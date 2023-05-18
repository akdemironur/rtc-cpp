#include "RTCCanvas.h"
namespace RTC
{
Canvas::Canvas(int w, int h)
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
int Canvas::width() const
{
    return _w;
}
int Canvas::height() const
{
    return _h;
}
Color Canvas::getPixel(int i, int j) const
{
    if (i >= 0 && j >= 0 && i < _w && j < _h)
        return _pixels[j][i];

    std::cout << "Coordinates are out of bounds!" << std::endl;
    return Color(-1, -1, -1);
}
void Canvas::setPixel(int i, int j, Color c)
{
    if (i >= 0 && j >= 0 && i < _w && j < _h)
        _pixels[j][i] = c;
    else
        std::cout << "Coordinates are out of bounds!" << std::endl;
}
std::string Canvas::ppmHeader() const
{
    std::ostringstream oss;
    oss << "P3" << std::endl << _w << " " << _h << std::endl << 255 << std::endl;
    return oss.str();
}
std::string Canvas::ppmColors() const
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
void Canvas::ppmWrite(const std::string &fileName)
{
    std::ofstream fileToWrite;
    fileToWrite.open(fileName);
    fileToWrite << ppmHeader() << std::endl << ppmColors();
    fileToWrite.close();
}

} // namespace RTC