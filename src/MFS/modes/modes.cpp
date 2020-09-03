#include "MFS.h"

namespace MFS::Modes {
    void switchMode(MFS::Modes::modeList newMode) {
        auto currentElement = actions.find(currentMode);
        assert(currentElement != actions.end());

        auto exitAction = std::get<1>(currentElement->second);
        exitAction();

        auto newElement = actions.find(newMode);
        assert(newElement != actions.end());

        auto enterAction = std::get<0>(newElement->second);
        enterAction();

        currentMode = newMode;

    }
}
namespace MFS::Modes::Actions {
    void enterNominal() {
        LOG("Entering nominal mode");
    }


    void exitNominal() {
        LOG("Exiting nominal mode");
    }


    void enterTransmission() {
        LOG("Entering transmission mode");
    }


    void exitTransmission() {
        LOG("Exiting transmission mode");
    }


    void enterThrust() {
        LOG("Entering thrust mode");
    }


    void exitThrust() {
        LOG("Exiting thrust mode");
    }


    void enterSurvival() {
        LOG("Entering survival mode");
    }


    void exitSurvival() {
        LOG("Exiting survival mode");
    }
}
