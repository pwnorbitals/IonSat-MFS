#pragma once

#include <tuple>

namespace MFS::Modes {
    enum class modeList {
        NOMINAL,
        TRANSMISSION,
        THRUST,
        SURVIVAL
    };

    namespace Actions {
        void enterNominal();
        void exitNominal();
        void enterTransmission();
        void exitTransmission();
        void enterThrust();
        void exitThrust();
        void enterSurvival(); 
        void exitSurvival();
    }

    // TODO : switch to static map
    std::map<MFS::Modes::modeList, std::tuple<void(*)(), void(*)(void)>> actions {
        {modeList::NOMINAL, std::make_tuple(Actions::enterNominal, Actions::exitNominal)},
        {modeList::TRANSMISSION, std::make_tuple(Actions::enterTransmission, Actions::exitTransmission)},
        {modeList::THRUST, std::make_tuple(Actions::enterThrust, Actions::exitThrust)},
        {modeList::SURVIVAL, std::make_tuple(Actions::enterSurvival, Actions::exitSurvival)},
    };

    modeList currentMode = MFS::Modes::modeList::SURVIVAL;

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