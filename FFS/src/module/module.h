#ifndef MODULE_H_INC
#define MODULE_H_INC

#include "local/localModule.h"
#include "remote/remoteModule.h"

namespace FFS {
    class Module {
        protected:
            virtual void sendEvent(FFS::Event) = 0;

        public:
            Module();
            ~Module();
            

    };
}

#endif