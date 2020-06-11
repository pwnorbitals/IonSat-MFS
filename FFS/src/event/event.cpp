#include "FFS.h"

namespace FFS {
    Event::Event() {};

    Event::~Event() {};

    EventDataStruct Event::getData() { 
        return data;
    };

    void Event::parseBuffer(char* buf) {

        FFS::emit();
    }

    char* serialize() {
                
    }
}