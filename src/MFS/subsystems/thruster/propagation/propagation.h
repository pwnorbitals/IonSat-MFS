#pragma once

#include "MFS.h"
#include "SGP4.h"

namespace MFS::Propagation {

    struct TimerEvent{ unsigned long emissionTime; };
    struct RequirePropagate{ };

    void propagatorFct(RequirePropagate const& propagation);
    void timerHandler(TimerEvent const& evt);
    void timer_15sec(void*);

    inline RFF::Task<9, 2048> timerTask{timer_15sec, "TimerTask"};;

    inline auto PropagatorTimer = RFF::EventHandler<TimerEvent, 2>{timerHandler};
    inline auto propagator = RFF::EventHandler<RequirePropagate>{propagatorFct};
    inline auto module = RFF::Module{PropagatorTimer, propagator};
}