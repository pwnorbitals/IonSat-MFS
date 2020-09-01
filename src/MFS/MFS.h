#pragma once
#include "RFF.h"

#include "propagation/propagation.h"
#include "subsystems/subsystems.h"
#include "housekeeping/housekeeping.h"
#include "modes/modes.h"

namespace MFS {
    RFF::Setup setup{
        MFS::HouseKeeping::module, 
        MFS::Propagation::module
    };
}

