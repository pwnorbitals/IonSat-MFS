#pragma once

#include "MFS.h"
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

    struct ModeChange {
        modeList previous;
        modeList current;
    };


    // TODO : switch to static map
    inline std::map<MFS::Modes::modeList, std::tuple<void(*)(), void(*)(void)>> actions {
        {modeList::NOMINAL, std::make_tuple(Actions::enterNominal, Actions::exitNominal)},
        {modeList::TRANSMISSION, std::make_tuple(Actions::enterTransmission, Actions::exitTransmission)},
        {modeList::THRUST, std::make_tuple(Actions::enterThrust, Actions::exitThrust)},
        {modeList::SURVIVAL, std::make_tuple(Actions::enterSurvival, Actions::exitSurvival)},
    };

    inline modeList currentMode = MFS::Modes::modeList::SURVIVAL;

    void switchMode(MFS::Modes::modeList newMode);

    namespace Listeners {
        void WDEventHandler(MFS::Watchdog::Event const&);

        inline auto watchdogListener = RFF::EventHandler<MFS::Watchdog::Event, 9>{WDEventHandler};
        
    }

    inline auto module = RFF::Module{Listeners::watchdogListener};

}