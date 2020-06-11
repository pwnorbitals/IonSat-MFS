#ifndef FFS_HPP_INC
#define FFS_HPP_INC

#include <iostream>

#define OS FREERTOS

#include "OS/OS.h"
#include "event/event.h"
#include "module/module.h"


namespace FFS {
    void iotest();
}

#endif