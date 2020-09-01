#include "MFS.h"

namespace MFS::Modes::Actions {
    void enterNominal() {
        LOGMSG("Entering nominal mode");
    }


    void exitNominal() {
        LOGMSG("Exiting nominal mode");
    }


    void enterTransmission() {
        LOGMSG("Entering transmission mode");
    }


    void exitTransmission() {
        LOGMSG("Exiting transmission mode");
    }


    void enterThrust() {
        LOGMSG("Entering thrust mode");
    }


    void exitThrust() {
        LOGMSG("Exiting thrust mode");
    }


    void enterSurvival() {
        LOGMSG("Entering survival mode");
    }


    void exitSurvival() {
        LOGMSG("Exiting survival mode");
    }
}
