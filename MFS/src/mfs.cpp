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
        std::thread cinThread; // Simulates execution on another hardware

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


    auto testModule = ConsoleModule{};

    FFS::init(std::make_tuple(FFS::Mode{"test"}), std::make_tuple(FFS::Chan{consoleEvent{}, std::make_tuple(consoleEvtHdlr)}));
    


    FFS::start();

    return 0;
}
