#include "FFS.h"

namespace FFS {
    template<typename T>
    Event<T>::startMarker{"FS"};

    template<typename T>
    Event<T>::Event() {};

    template<typename T>
    Event<T>::~Event() {};

    template<typename T>
    EventDataStruct Event<T>::getData() { 
        return data;
    };

    template<typename T>
    void Event<T>::parseBuffer(char* buf) {

        emit();
    }

    template<typename T>
    char* Event<T>::serialize() {
                
    }
}