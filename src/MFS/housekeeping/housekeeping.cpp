#include "MFS.h"

namespace MFS::HouseKeeping {
    void loggerFunction(MFS::HouseKeeping::Event const& event) {
        std::cout << event.message << " at " << event.timestamp << " on " << event.meta << std::endl;
    }
}