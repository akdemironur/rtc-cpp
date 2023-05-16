#include "RTCTick.h"

namespace RTC
{
void tick(const std::pair<Tuple, Tuple> &env, std::pair<Tuple, Tuple> &proj)
{
    proj.first = proj.first + proj.second;
    proj.second = proj.second + env.first + env.second;
}
} // namespace RTC
