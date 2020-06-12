#include "FFS.h"
#include <type_traits>

namespace FFS {

    template<typename ...chans_t>
    void Controller<chans_t...>::addMode() {

    };

    

    template<typename ref_type, typename ...types>
    struct is_any_of: std::integral_constant<bool,(std::is_same_v<ref_type,types>||...)>{};

    template<typename ref_type, typename ...types>
    inline constexpr bool is_any_of_v = is_any_of<ref_type, types...>::value;

    template<typename chan_t>
    void emit(FFS::Event<chan_t> evt) {
        auto ctrlr = Controller::Controller()


    };

    
    template<typename chan_t,typename message_t>
    constexpr void emit(const chan_t& c, const message_t& m) {
        static_assert(std::is_same_v<typename chan_t::message_t,message_t>,"Wrong message type for this channel");
        std::apply([m](auto... receiver){(receiver(m),...);},c.receivers);
    }

    void start() {

    };

    template<typename ...chans_t>
    void Controller<chans_t...>::start() {

    };

    template<typename ...chans_t>
    Controller<chans_t...>::Controller(std::tuple<FFS::Chan<chans_t...>> channels) :
        subscribed{channels} {
        
    };

    template<typename ...chans_t>
    Controller<chans_t...>::~Controller() {

    };

    template<typename ...chans_t>
    Controller<chans_t...>& Controller<chans_t...>::operator()() {
        return instance;
    };

    template<typename ...chans_t>
    Controller<chans_t...>& Controller<chans_t...>::declareChannels(std::tuple<FFS::Chan<chans_t...>> channels) {
        instance = Controller{channels};
    }

}