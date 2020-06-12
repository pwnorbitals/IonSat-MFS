#ifndef LOCALMODULE_H_INC
#define LOCALMODULE_H_INC

#include <functional>
#include <tuple>

namespace FFS {
    class LocalModule {
        protected:
            std::tuple<FFS::Task> tasks;

        public:
            LocalModule();
            virtual ~LocalModule();

    };
}


#endif