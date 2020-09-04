#pragma once

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
        struct Reboot {
            unsigned int execTime; // 0 = NOW
        }; // 

        struct SendHousekeeping{

        };

        struct SendOBCLogs {

        };
        
        struct SendADCSLogs {

        };

        struct SendCommLogs {

        };

        struct SendEPSLogs {
            
        };

        struct ADCSChangeMode {
            unsigned int execTime; // 0 = NOW

        }; // FlightPlan.add

        struct ListEvents {

        }; // Answer with event type + time + status

        struct CancelEvent {
            unsigned int eventId;
        }; // FlightPlan.cancel

        struct TimeSync {
            unsigned int execTime; // 0 = NOW
            unsigned int frequency; // 0 = NEVER, otherwise overwrite other TimeSync events

        };

        struct OCSChangeAltitude {
            unsigned int target;
            unsigned int min; // 0 = undefined
            unsigned int max; // 0 = undefined
        };

        struct UpdateBlob {

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
