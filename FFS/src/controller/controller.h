#ifndef CONTROLLER_H_INC
#define CONTROLLER_H_INC

#include <list>
#include <tuple>
#include <memory>

#include "module/module.h"
#include "mode/mode.h"

namespace FFS {

    template<typename T> void emit(T evt);
    void start();

    template<typename ...chans_t>
    void declareChannels();

    template<typename chan_t,typename message_t>
    constexpr void emit(const chan_t& c, const message_t& m);

    template<typename _message_t, typename ...receivers_t>
    class Chan {
        protected:
            std::tuple<receivers_t...> receivers;

        public:
            using message_t = _message_t;

            template<typename _message_t>
            chan(const std::tuple<receivers_t...>& rec)
                :receivers{rec}{}
            
            const chan& operator<<(const _message_t& m) const {
                send(*this,m);
                return *this;
            }
    };

    // Singleton class
    // BE CAREFUL WITH MULTITASKING ??!!
    template<typename ...chans_t>
    class Controller {
        protected:
            static Controller& instance;

            std::tuple<FFS::Chan<chans_t...>> channels;
            std::list<std::unique_ptr<FFS::Module>> modules;
            std::list<FFS::Mode> modes;

            Controller(std::tuple<FFS::Chan<...chans_t>> channels);

        public:
            static template<typename ...chans_t> init(std::tuple<FFS::Chan<chans_t...>> channels);
            virtual ~Controller();
            static Controller& operator()();
            void addMode();
            template<typename chan_t> void emit(FFS::Event<chan_t>);
            void start();
    };
}

#endif