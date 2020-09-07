#pragma once

namespace MFS::Subsystems {
    enum class Subsystem {
        ADCS,
        TMTC,
        EPS,
        OCS
    };
}

#include "attitude/attitude.h"
#include "communications/communications.h"
#include "power/power.h"
#include "thruster/thruster.h"