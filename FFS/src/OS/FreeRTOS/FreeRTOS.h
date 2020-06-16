#ifndef FREERTOS_H_INC
#define FREERTOS_H_INC

#include "semaphore.h"
#include "task.h"

#include "FreeRTOS.h"

#include "eventGroup.h"
#include "messageBuffer.h"
#include "queueSet.h"
#include "semaphore.h"
#include "streamBuffer.h"
#include "task.h"
#include "timer.h"

namespace FFS {
    namespace OS {

    }

}

extern "C" {
    void vMainQueueSendPassed( void )
    {
        /* This is just an example implementation of the "queue send" trace hook. */

    }

    void vApplicationIdleHook( void )
    {

        #ifdef __GCC_POSIX__

            struct timespec xTimeToSleep, xTimeSlept;
                /* Makes the process more agreeable when using the Posix simulator. */
                xTimeToSleep.tv_sec = 1;
                xTimeToSleep.tv_nsec = 0;
                nanosleep( &xTimeToSleep, &xTimeSlept );

        #endif
    }

}
#endif
