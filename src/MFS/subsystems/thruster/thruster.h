#pragma once

#include <tuple>
#include <map>
#include <climits>
#include <algorithm>

namespace MFS::Subsystems::Thruster {
    extern std::map<int, int> dutyTime;
    extern unsigned int altitude;
    extern double currentDutyTime;
}