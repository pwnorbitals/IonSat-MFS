#ifndef TASK_H_INC
#define TASK_H_INC

#include <functional>
#include "FreeRTOS.h"

namespace FFS {

    template<typename fct_t>
    class Task {
        TaskHandle_t task;

    public:

        Task(std::function<fct_t> _pvTaskCode,
             std::string const& _pcName,
             configSTACK_DEPTH_TYPE _usStackDepth,
             void* _pvParameters,
             UBaseType_t _uxPriority,
             StackType_t * const puxStackBuffer,
             StaticTask_t * const pxTaskBuffer ) :
            task{xTaskCreateStatic(_pvTaskCode, _pcName.c_str(), _usStackDepth, _pvParameters, _uxPriority, task)} {
        }


        ~Task() {
            vTaskDelete(task);
        }
    };
}

#endif
