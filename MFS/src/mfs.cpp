#include <iostream>
#include <thread>
#include <functional>

#include "FFS.h"


struct consoleEvent {
    std::string msg;
};


template<typename ...ctrlr_t>
void cinFct(const FFS::Controller<ctrlr_t...>& FFS) {
    auto input = std::string{};
    while(true) {
        std::cin >> input;
        FFS.emit(consoleEvent{input});
    }
}

template<typename ...ctrlr_t>
class ConsoleModule : public FFS::RemoteModule {
        std::thread cinThread; // Simulates execution on external hardware

        public:
            ConsoleModule(const FFS::Controller<ctrlr_t...>& FFS) : RemoteModule{}, cinThread{cinFct<decltype (FFS)>, FFS} {}


            void recvData() override {
                // this->addIncoming(buf, len);
            }

            void sendData(char* buf, unsigned int inlen) override  {
                std::cout << buf << std::endl;
            }
};

void consoleEvtHdlr (consoleEvent evt) {
    std::cout << "EVENT RECEIVED : " << evt.msg << std::endl;
}





int main() {
    std::cout << "test" << std::endl;
    FFS::iotest();





    auto testMode = FFS::Mode{"test"};
    auto modes = std::make_tuple(testMode);

    // doesn't compile :
    //auto consoleChan = FFS::make_chan<consoleEvent>(consoleEvtHdlr);


    auto consoleChan = FFS::Chan{consoleEvent{}, std::make_tuple(consoleEvtHdlr)};
    auto chans = std::make_tuple(consoleChan);

    // For non-static member function
    // std::bind(&module3::print, &m3, std::placeholders::_1)

    auto controller = FFS::Controller(modes, chans);
    auto testModule = ConsoleModule{controller};

    controller.start();

    return 0;
}
