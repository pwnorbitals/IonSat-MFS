#ifndef CONTROLLER_H_INC
#define CONTROLLER_H_INC

#include <list>
#include <tuple>

namespace FFS {


    class Controller {
        protected:
            std::list<std::tuple<FFS::Module, FFS::MessageType>> subscribed;
            FFS::Task dispatcher;
            std::list<FFS::Module> modules;
            std::list<FFS::Mode> modes;


        public:
            Controller() {};
            ~Controller() {};
    };
}

#endif