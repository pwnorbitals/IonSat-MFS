#pragma once

#include "MFS.h"
#include "SGP4.h"

namespace MFS::Propagation {

    struct TimerEvent{ std::clock_t emissionTime; };
    struct RequirePropagate{ };

    void propagator(RequirePropagate const& propagation);
    void timerHandler(TimerEvent const& evt);
    void timer_15sec(void*);

    RFF::Task<9, 2048> timerTask{timer_15sec, "TimerTask"};

    RFF::EventHandler<TimerEvent, 2> PropagatorTimer{timerHandler};
    RFF::EventHandler<RequirePropagate> Propagator{propagator};
    RFF::Module module{PropagatorTimer, Propagator};
}