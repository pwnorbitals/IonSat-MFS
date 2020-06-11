#include <iostream>
#include <thread>
#include <functional>
#include "FFS.h"


FFS::EventType<char[512]> consoleEvent;


auto eventTypes = std::list<FFS::EventType> {
    consoleEvent
};

void cinFct(std::function<void(char*)> recvData) {
    auto input = std::string{};
    while(true) {
        std::cin >> input;
        FFS::Event inputEvent(ConsoleEvent, input.c_str());
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
    std::cout << "EVENT RECEIVED : " << evt.getData().data << std::endl;
}

int main() {
    std::cout << "test" << std::endl;
    FFS::iotest();

    auto testModule = FFS::ConsoleModule{};
    testModule.addHandler(eventType::consoleEvent, consoleEvtHdlr);

    FFS::start();

    return 0;
}