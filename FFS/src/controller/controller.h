#ifndef CONTROLLER_H_INC
#define CONTROLLER_H_INC

#include <list>
#include <tuple>
#include <memory>

#include "module/module.h"
#include "mode/mode.h"

namespace FFS {

    template<typename ref_type, typename ...types>
    struct is_any_of: std::integral_constant<bool,(std::is_same_v<ref_type,types>||...)>{};

    template<typename ref_type, typename ...types>
    inline constexpr bool is_any_of_v = is_any_of<ref_type, types...>::value;



    template<typename _message_t, typename ...receivers_t>
    class Chan {
        protected:
            std::tuple<receivers_t...> receivers;

        public:
            using message_t = _message_t;

            Chan(const _message_t&, const std::tuple<receivers_t...>& rec):receivers{rec}{}
            
            const Chan& operator<<(const _message_t& m) const {
                emit(*this,m);
                return *this;
            }
    };

    template<typename chan_t,typename message_t>
    constexpr void emit(const chan_t& c, const message_t& m) {
        static_assert(std::is_same_v<typename chan_t::message_t,message_t>, "Wrong message type for this channel");
        std::apply([m](auto... receiver){(receiver(m),...);},c.receivers);
    }


    template<typename ...chans_t>
    class Controller {
        protected:
            std::tuple<FFS::Chan<chans_t...>> channels;
            std::tuple<std::unique_ptr<FFS::Module>> modules;
            std::tuple<FFS::Mode> modes;

        public:
            Controller(std::tuple<FFS::Mode> modes, std::tuple<FFS::Chan<chans_t...>> channels);
            virtual ~Controller();
            
            template<typename chan_t> void emit(chan_t data);
            void start();

    };




}

#endif
