#ifndef TASK_H_INC
#define TASK_H_INC

#include <functional>
#include "FFS_FreeRTOS.h"

namespace FFS {

    template<typename fct_t>
    class Task {
        TaskHandle_t taskHandle;
        StaticTask_t task;
        StackType_t StackBuffer;

    public:

        Task(std::function<fct_t> const& _pvTaskCode,
             std::string const& _pcName,
             configSTACK_DEPTH_TYPE _usStackDepth,
             void* _pvParameters,
             UBaseType_t _uxPriority,
             StackType_t * const puxStackBuffer,
             StaticTask_t * const pxTaskBuffer ) :

            taskHandle{xTaskCreateStatic(_pvTaskCode, _pcName.c_str(), _usStackDepth, _pvParameters, _uxPriority, &StackBuffer, &task)} {

        }


        ~Task() {
            vTaskDelete(task);
        }
    };
}

#endif
