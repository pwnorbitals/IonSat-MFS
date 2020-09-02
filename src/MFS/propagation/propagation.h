#pragma once

#include "MFS.h"
#include "SGP4.h"

namespace MFS::Propagation {

    struct TimerEvent{ std::clock_t emissionTime; };
    struct RequirePropagate{ };

    void propagatorFct(RequirePropagate const& propagation);
    void timerHandler(TimerEvent const& evt);
    void timer_15sec(void*);

    extern RFF::Task<9, 2048> timerTask;

    extern RFF::EventHandler<TimerEvent, 2> PropagatorTimer;
    extern RFF::EventHandler<RequirePropagate> propagator;
    extern RFF::Module module;
}