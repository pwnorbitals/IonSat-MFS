#pragma once

#include "MFS.h"
#include "flightPlan/flightPlan.h"

namespace MFS::Subsystems::Communications {

    enum class TCList {
        // Mission
        // For each : 
        //    Param : trigger, skipOnTimeSync
        //    Response: success
        ADCS_CHANGEMODE,    // Param : 0, Response: 
        OCS_CHANGEALTITUDE, // Param : 0, Response: 
        DEPLOY_PANELS,      // Param : 0, Response: tries, 
        PROPAGATOR_STATUS,  // Param : 0, Response: 
        PROPAGATOR_CONFIG,  // Param : key, value, Response: 

        // OBC
        // For each :
        //    Param : 
        //    Response: 
        REBOOT,             // Param : trigger
        MEM_STATUS,         // 
        CPU_STATS,          // 
        SAFEMODE_ENTER,     // Param : trigger
        SAFEMODE_EXIT,      // Param : trigger
        BEACON_CONFIG,      // Param : key, value, force, Response: success

        // FLIGHT PLAN
        LIST_EVENTS,        // Param: 0, Response: [ID, type, timestamp, status, skipOnTimeSync]
        CANCEL_EVENT,       // Param :eventID
        SYNC_TIME,          // Response : new timestamp
        

        // SOFTWARE UPDATES
        UPDATE_NEW,     // Param : subsystem
        UPDATE_BLOB,    // Param : 0, Response: success. Each blob has CRC, full update has CRC
        UPDATE_STATUS,  // Param : 0, Response: [ID, subsystem, fullSize, CRC, blobSize, blobCount, [blobNumber, CRC, receivedSize]]
        APPLY_UPDATE,   // Param : 0, Response: success
        
        // DEBUG
        SEND_HOUSEKEEPING, // Param : timestamp / timedelta
        HOUSEKEEPING_CONFIG, // Param : key, value, force
        SEND_LOGS,         // Param : subsystem
        LOGS_CONFIG,         // Param: key, value, force

    };

    namespace Commands {
        template<TCList T>
        struct Command {
            
        };

        template<>
        struct Command<TCList::ADCS_CHANGEMODE> {
            MFS::FlightPlan::timeTrigger trigger;
        };

        template<>
        struct Command<TCList::REBOOT> {
            unsigned int execTime; // 0 = NOW
        }; // 

        template<>
        struct Command<TCList::SEND_HOUSEKEEPING>{

        };

        template<>
        struct Command<TCList::SEND_LOGS> {
            MFS::Subsystems::Subsystem target;
        };
        
        template<>
        struct Command<TCList::LIST_EVENTS> {
            
        }; // Answer with event type + time + status

        template<>
        struct Command<TCList::CANCEL_EVENT> {
            unsigned int eventId;
        }; // FlightPlan.cancel

        template<>
        struct Command<TCList::SYNC_TIME> {
            MFS::FlightPlan::timeTrigger executionTime;
            unsigned int frequency; // 0 = NEVER, otherwise overwrite other TimeSync events

        };

        template<>
        struct Command<TCList::OCS_CHANGEALTITUDE> {
            unsigned int target;
            unsigned int min; // 0 = undefined
            unsigned int max; // 0 = undefined
        };

        template<>
        struct Command<TCList::UPDATE_BLOB> {

        };

    }

    

    struct BufferReceived {
        int length;
        std::vector<char> data;
    };

    struct DecodedTC {
        TCList command;
    };

    void TC_Decode(BufferReceived const& buf);

}