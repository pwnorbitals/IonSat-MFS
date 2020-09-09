#pragma once

#include "MFS.h"
#include <string_view>


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
    struct Event{ // TODO : fix 
        std::string_view message;
        unsigned int timestamp;
        std::string_view meta;
    };


    void loggerFunction(MFS::HouseKeeping::Event const& event);
    inline auto loggerHandler = RFF::EventHandler<MFS::HouseKeeping::Event>{loggerFunction};
    inline auto module = RFF::Module{loggerHandler};
}