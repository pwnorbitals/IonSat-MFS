#pragma once

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



    template<typename event_t, typename trigger_t>
    struct FlightEvent {
        trigger_t trigger;
        event_t   action;
        eventStatus status;
    };

    template<typename ...flightEvents_t>
    struct FlightPlan {
        std::tuple<flightEvents_t...> events;
    };  

    void deserialize();
    void serialize();

}