#include "MFS.h"

namespace MFS::FlightPlan {
    void addFlightEvent(NewFlightEvent const& evt) {
         // Setup a wake-up timer
         RFF::Timer<FlightEventTrigger>(FlightEventTriggered, evt.event);
    }

    void FlightEventTriggered(FlightEventTrigger const&) {
        EMIT(FlightEvent<int>{});
    }
}