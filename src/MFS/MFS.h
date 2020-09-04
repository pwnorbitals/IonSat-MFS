#pragma once
#include "RFF.h"

#include "subsystems/subsystems.h"
#include "housekeeping/housekeeping.h"
#include "watchdog/watchdog.h"
#include "modes/modes.h"
#include "flightPlan/flightPlan.h"

namespace MFS {
    inline auto setup = RFF::Setup{
        MFS::HouseKeeping::module, 
        MFS::Propagation::module,
        MFS::Modes::module
    };
}

