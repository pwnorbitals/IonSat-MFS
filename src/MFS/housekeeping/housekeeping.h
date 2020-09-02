#pragma once

#include "MFS.h"


#define LOGMSG(msg)                \
    RFF::emit(                     \
        MFS::HouseKeeping::Event{  \
            (msg),                 \
            0,                     \
            "__FILE__ (in  __func__ , line __LINE__ )" \
        }                          \
    )


namespace MFS::HouseKeeping {
    struct Event{
        std::string_view message;
        unsigned int timestamp;
        std::string_view meta;
    };


    void loggerFunction(MFS::HouseKeeping::Event const& event);
    extern RFF::EventHandler<MFS::HouseKeeping::Event> loggerHandler;
    extern RFF::Module module;
}