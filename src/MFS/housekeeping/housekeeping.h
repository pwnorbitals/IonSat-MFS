#pragma once

#include "MFS.h"


#define LOG(msg)                \
    RFF::emit(                      \
        MFS::HouseKeeping::Event{  \
            (msg),                 \
            0,                     \
            "__FILE__ (in  __func__ , line __LINE__ )" \
        }                          \
    )


#define EMIT(value)             \
    LOG("Event : " (value)); \
    RFF::emit(value);           


namespace MFS::HouseKeeping {
    struct Event{
        std::string_view message;
        unsigned int timestamp;
        std::string_view meta;
    };


    void loggerFunction(MFS::HouseKeeping::Event const& event);
    inline RFF::EventHandler<MFS::HouseKeeping::Event> loggerHandler{loggerFunction};
    inline RFF::Module module{loggerHandler};
}