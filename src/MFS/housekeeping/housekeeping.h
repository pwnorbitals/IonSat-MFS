#pragma once

#include "MFS.h"


#define LOG(...)                \
    RFF::emit(                      \
        MFS::HouseKeeping::Event{  \
            (__VA_ARGS__),                 \
            0,                     \
            "__FILE__ (in  __func__ , line __LINE__ )" \
        }                          \
    )


#define EMIT(...)             \
    LOG("Event :  (value)"); \
    RFF::emit(__VA_ARGS__);           


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