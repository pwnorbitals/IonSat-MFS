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
        template<typename data_t>
        void do_TCReceived(TC::BufferReceived<data_t> const&) {

        }

        template<typename data_t>
        void do_SendTM(TM::BufferToSend<data_t> const&) {

        }
    }


}