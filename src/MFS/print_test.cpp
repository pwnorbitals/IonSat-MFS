#include <iostream>
#include "RFF.h"

void printer(void*) {
    std::cout << "TEST" << std::endl;
    RFF::Task<9,2048>::delay(1); // * configTICK_RATE_HZ
}

RFF::Task<9, 2048> printerTask{printer, "PrinterTask"};

RFF::Setup setup{};

void rff_main() {}