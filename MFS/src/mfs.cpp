#include <iostream>
#include <thread>
#include <functional>

#include "FFS.h"


struct consoleEvent {
    std::string msg;
};







void cinFct(std::function<void(char*)> recvData) {
    auto input = std::string{};
    while(true) {
        std::cin >> input;
        FFS::emit(consoleEvent{input});
    }
}

class ConsoleModule : public FFS::RemoteModule {
        std::thread cinThread;

        ConsoleModule() : RemoteModule{}, cinThread{cinFct, recvData} {}


        virtual void recvData(char* buf, unsigned int len) {
            this->addIncoming(buf, len);
        }

        void sendData(char* buf) {
            std::cout << buf << std::endl;
        }
};

void consoleEvtHdlr (consoleEvent evt) {
    std::cout << "EVENT RECEIVED : " << evt.msg << std::endl;
}

int main() {
    std::cout << "test" << std::endl;
    FFS::iotest();

    FFS::declareChannels<consoleEvent>();

    auto testModule = ConsoleModule{};





    FFS::start();

    return 0;
}