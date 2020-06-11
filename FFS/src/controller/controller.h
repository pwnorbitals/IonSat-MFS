#ifndef CONTROLLER_H_INC
#define CONTROLLER_H_INC

#include <list>
#include <tuple>
#include <memory>

#include "module/module.h"
#include "mode/mode.h"

namespace FFS {

    void addEventType();
    void addMode();
    void emit(FFS::Event evt);
    void start();

    // Singleton class
    // BE CAREFUL WITH MULTITASKING ??!!
    class Controller {
        protected:
            static Controller& instance;

            std::list<std::tuple<std::unique_ptr<FFS::Module>, FFS::MessageType>> subscribed;
            FFS::Task dispatcher;
            std::list<std::unique_ptr<FFS::Module>> modules;
            std::list<FFS::Mode> modes;


        public:
            Controller();
            virtual ~Controller();
            Controller& operator()();
            void addEventType();
            void addMode();
            void emit(FFS::Event);
            void start();
    };
}

#endif