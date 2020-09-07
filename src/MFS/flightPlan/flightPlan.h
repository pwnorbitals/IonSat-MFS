#pragma once

#include "MFS.h"
#include "subsystems/communications/communications.h"

#include <boost/container/static_vector.hpp>

namespace MFS::FlightPlan {

    struct timeTrigger {
        unsigned long timestamp;
    };

    /*
    template<typename event_t>
    struct eventTrigger {
        event_t event
    };  
    */

    enum class eventStatus {
        ENABLED,
        DISABLED,
        EXECUTED
    };



    template<typename event_t>
    struct FlightEvent {
        timeTrigger trigger;
        event_t   action;
        eventStatus status;
    };

    struct NewFlightEvent {
        MFS::Subsystems::Communications::TCList event;
    };

    struct FlightEventTrigger {
        
    };

    // Should be Singleton
    // Delete after a given time
    struct FlightPlan {
        boost::container::static_vector<FlightEvent<int>, 512> events;
    };  

    void addFlightEvent(NewFlightEvent const&); // Setup a wake-up timer
    void FlightEventTriggered(FlightEventTrigger const&);
    inline auto FlightEventHandler = RFF::EventHandler<NewFlightEvent>{addFlightEvent};
    inline auto EventTriggerHandler = RFF::EventHandler<FlightEventTrigger>{FlightEventTriggered};
    inline auto FlightPlanModule = RFF::Module{FlightEventHandler, EventTriggerHandler};


}