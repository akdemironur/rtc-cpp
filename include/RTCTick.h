#pragma once
#include "RTCTuple.h"
#include <utility>

namespace RTC
{
extern std::pair<Tuple, Tuple> tick(std::pair<Tuple, Tuple> env, std::pair<Tuple, Tuple> proj);
} // namespace RTC
