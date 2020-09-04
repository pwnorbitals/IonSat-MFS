#include "MFS.h"

namespace MFS::Subsystems::Communications {

    namespace TC {
        template<typename data_t>
        void TC_Decode(BufferReceived<data_t> const&) {

        }
    }

    namespace TM {
        template<typename data_t>
        void TM_Encode(BufferToSend<data_t> const&) {

        }
    }

    namespace Events {
        void do_TCReceived(TCReceived const&) {

        }

        void do_SendTM(SendTM const&) {
            
        }
    }


}