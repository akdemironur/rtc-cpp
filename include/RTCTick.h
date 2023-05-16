#pragma once
#include "RTCTuple.h"
#include <utility>

namespace RTC
{
extern void tick(const std::pair<Tuple, Tuple> &env, std::pair<Tuple, Tuple> &proj);
} // namespace RTC
