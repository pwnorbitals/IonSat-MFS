#include <iostream>

#include "RFF.h"


#include "propagation/propagation.h"
#include "subsystems/subsystems.h"
#include "housekeeping/housekeeping.h"
#include "modes/modes.h"


RFF::Setup setup{
    HouseKeepingModule, 
    PropagationModule
    };

void rff_main() {}