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

    extern std::map<MFS::Modes::modeList, std::tuple<void(*)(), void(*)(void)>> actions;
    extern modeList currentMode;
    void switchMode(MFS::Modes::modeList newMode);
    
}