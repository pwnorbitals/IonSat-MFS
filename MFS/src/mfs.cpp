#include <iostream>
#include <thread>
#include <functional>
#include "FFS.h"

void cinFct(std::function<void(char*)> recvData) {
    auto input = std::string{};
    while(true) {
        std::cin >> input;
        FFS::Event inputEvent(input.c_str());
        recvData(inputEvent.serialize()); 
    }
}

class ConsoleModule : public FFS::RemoteModule {
    public:
        std::thread cinThread;

        ConsoleModule() : RemoteModule{}, cinThread{cinFct, recvData} {}

    protected:
        void recvData(char* buf, unsigned int len) {
            this->addIncoming(buf, len);
        }

        void sendData(char* buf) {
            std::cout << buf << std::endl;
        }
};

void consoleEvtHdlr (FFS::Event evt) {
    std::cout << "EVENT RECEIVED : " << evt.getData().packet.data << std::endl;
}

int main() {
    std::cout << "test" << std::endl;
    FFS::iotest();

    auto consoleEvent = FFS::addEventType(0x01, "consoleEvent");

    auto TestModule = FFS::LocalModule{};
    TestModule.addHandler(consoleEvent, consoleEvtHdlr);

    return FFS::start();
}