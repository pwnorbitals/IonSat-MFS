#pragma once

#include "MFS.h"

namespace MFS::Watchdog {
    enum class EventList {
        UNRESPONSIVE
    };

    struct Event {
        EventList cause;
    };  
}