#include "FFS.h"
#include <type_traits>

namespace FFS {

    template<typename ...chans_t>
    void Controller<chans_t...>::start() {

    };

    template<typename ...chans_t>
    Controller<chans_t...>::Controller(std::tuple<FFS::Mode> _modes, std::tuple<FFS::Chan<chans_t...>> _channels):
        modes{_modes}, channels{_channels} {

    };

    template<typename ...chans_t>
    Controller<chans_t...>::~Controller(){}


    template<typename ...chans_t>
    template<typename chan_t>
    void Controller<chans_t...>::emit (chan_t message) const {
        std::apply([message](auto... chan){(emitOnChan(chan,message),...);}, channels);
    };

}
