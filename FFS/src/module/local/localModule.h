#ifndef LOCALMODULE_H_INC
#define LOCALMODULE_H_INC

#include <functional>

namespace FFS {
    class LocalModule {
        protected:
            std::list<std::pair<eventType, std::function<void(eventType)>>> handlers;

        public:
            LocalModule();
            virtual ~LocalModule();

            void addHandler(eventType type, std::function<void(eventType)> handler);
    };
}


#endif