#include "FFS.h"

namespace FFS {
    LocalModule::LocalModule() {};
    LocalModule::~LocalModule() {};

    void LocalModule::addHandler(eventType type, std::function<void(eventType)> handler) {
        
    }

}