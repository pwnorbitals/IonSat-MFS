#pragma once
#include "RFF.h"

#include "propagation/propagation.h"
#include "subsystems/subsystems.h"
#include "housekeeping/housekeeping.h"
#include "modes/modes.h"

namespace MFS {
    inline auto setup = RFF::Setup{
        MFS::HouseKeeping::module, 
        MFS::Propagation::module
    };
}

