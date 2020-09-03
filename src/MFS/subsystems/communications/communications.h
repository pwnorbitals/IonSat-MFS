#pragma once

namespace MFS::Subsystems::Communications {

    enum class TCList {
        REBOOT,
        
        SEND_HOUSEKEEPING,
        SEND_OBCLOGS,
        SEND_ADCSLOGS,
        SEND_COMMLOGS,
        SEND_EPSLOGS
    };

    struct BufferReceived {
        int length;
        std::vector<char> data;
    };

    struct DecodedTC {
        TCList command;
    };

    void TC_Decode(BufferReceived const& buf);

}