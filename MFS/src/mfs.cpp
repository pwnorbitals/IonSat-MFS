#include <iostream>
#include <thread>
#include <functional>

#include "FFS.h"


struct consoleEvent {
    std::string msg;
};



void cinFct() {
    auto input = std::string{};
    while(true) {
        std::cin >> input;
        FFS::emit(consoleEvent{input});
    }
}

class ConsoleModule : public FFS::RemoteModule {
        std::thread cinThread; // Simulates execution on external hardware

        public:
            ConsoleModule() : RemoteModule{}, cinThread{cinFct} {}


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

    auto controller = FFS::Controller();

    auto testModule = ConsoleModule{};

    auto testMode = FFS::Mode{"test"};
    auto modes = std::make_tuple(testMode);

    auto consoleChanHdlrs = std::make_tuple(consoleEvtHdlr);
    auto consoleChan = FFS::make_chan<consoleEvent>(consoleChanHdlrs);
    auto chans = std::make_tuple(consoleChan);

    controller.configure(modes, chans);
    controller.start();

    return 0;
}
