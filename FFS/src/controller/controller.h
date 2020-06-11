#ifndef CONTROLLER_H_INC
#define CONTROLLER_H_INC

#include <list>
#include <tuple>

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

            std::list<std::tuple<FFS::Module, FFS::MessageType>> subscribed;
            FFS::Task dispatcher;
            std::list<FFS::Module> modules;
            std::list<FFS::Mode> modes;


        public:
            Controller();
            ~Controller();
            Controller& operator()();
            void addEventType();
            void addMode();
            void emit(FFS::Event);
            void start();
    };
}

#endif