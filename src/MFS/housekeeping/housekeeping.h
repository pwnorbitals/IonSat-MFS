#pragma once

#include "MFS.h"

#define LOGMSG(msg) (RFF::emit(HouseKeepingEvent{msg, 0, {__FILE__"(in "__func__", line "__LINE__}}))


struct HouseKeepingEvent{
    std::string_view message;
    unsigned int timestamp;
    std::string_view meta;
};


extern void (*logger)(HouseKeepingEvent const&);
RFF::EventHandler<HouseKeepingEvent> HouseKeepingLogger{logger}
RFF::Module HouseKeepingModule{HouseKeepingLogger};