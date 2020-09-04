#pragma once

namespace MFS::Subsystems::Communications {

    enum class TCList {
        // Mission
        // For each : 
        //    Param : trigger, skipOnTimeSync
        //    Response: success
        ADCS_CHANGEMODE,    // Param : 0, Response: 
        ADCS_GET,       // Param : [key], Response: [values]
        ADCS_SET,      // Param : [key, value], Response: success
        OCS_CHANGEALTITUDE, // Param : 0, Response: 
        DEPLOY_PANELS,      // Param : 0, Response: tries, 
        PROPAGATOR_GET,  // Param : 0, Response: 
        PROPAGATOR_SET,  // Param : [key, value], Response: 
        CHANGE_MODE,     // Param : newMode

        // OBC
        // For each :
        //    Param : 
        //    Response: 
        REBOOT,             // Param : trigger
        MEM_STATUS,         // Param : , Response :
        CPU_STATS,          // Param : , Response :
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
        SEND_HOUSEKEEPING,   // Param : timestamp / timedelta
        HOUSEKEEPING_CONFIG, // Param : key, value, force
        SEND_LOGS,           // Param : subsystem
        LOGS_CONFIG,         // Param: key, value, force



    };

    struct Command {

    };

    namespace Commands {

        using Command = MFS::Subsystems::Communications::Command;

        struct Reboot : Command {
            unsigned int execTime; // 0 = NOW
        }; // 

        struct SendHousekeeping : Command {

        };

        struct SendOBCLogs  : Command {

        };
        
        struct SendADCSLogs : Command  {

        };

        struct SendCommLogs  : Command {

        };

        struct SendEPSLogs  : Command {
            
        };

        struct ADCSChangeMode  : Command {
            unsigned int execTime; // 0 = NOW

        }; // FlightPlan.add

        struct ListEvents  : Command {

        }; // Answer with event type + time + status

        struct CancelEvent  : Command {
            unsigned int eventId;
        }; // FlightPlan.cancel

        struct TimeSync  : Command {
            unsigned int execTime; // 0 = NOW
            unsigned int frequency; // 0 = NEVER, otherwise overwrite other TimeSync events

        };

        struct OCSChangeAltitude  : Command {
            unsigned int target;
            unsigned int min; // 0 = undefined
            unsigned int max; // 0 = undefined
        };

        struct UpdateBlob  : Command {

        };

    }

    

    namespace Events {
        struct TCReceived {

        };

        void do_TCReceived(TCReceived const&);

        struct SendTM {

        };

        void do_SendTM(SendTM const&);

        inline auto TCHandler = RFF::EventHandler<TCReceived>{do_TCReceived};
        inline auto TMHandler = RFF::EventHandler<SendTM>{do_SendTM};

        inline auto module = RFF::Module{TCHandler, TMHandler}; 
    }

    namespace TC {
        template<typename data_t>
        struct BufferReceived {
            data_t data;
        };

        struct DecodedTC {
            TCList command;
        };

        template<typename data_t>
        void TC_Decode(BufferReceived<data_t> const&);
    }

    
    namespace TM {

        

        template<typename data_t>
        struct BufferToSend {
            data_t data;
        };

        struct TMToEncode {
            TCList TMType;
            Command TMData;
        };

        template<typename data_t>
        void TM_Encode(BufferToSend<data_t> const&);

    }
    
    inline auto& module = Events::module;

}
