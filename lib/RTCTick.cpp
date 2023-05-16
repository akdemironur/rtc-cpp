#include "RTCTick.h"

namespace RTC
{
std::pair<Tuple, Tuple> tick(std::pair<Tuple, Tuple> env, std::pair<Tuple, Tuple> proj)
{
    proj.first = proj.first + proj.second;
    proj.second = proj.second + env.first + env.second;
    return proj;
}
} // namespace RTC
