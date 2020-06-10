#include <iostream>
#include <thread>
#include <functional>
#include "FFS.h"

void cinFct(std::function recvData) {
    std::string input;
    std::cin >> input;

    recvData(input.c_str());
}


class ConsoleModule : public FFS::RemoteModule {
    public:
        std::thread cinThread;

        ConsoleModule() : RemoteModule{}, cinThread{cinFct, recvData} {}

    protected:
        void recvData(char* buf) {
            this->addIncoming(buf);
        }

        void sendData(char* buf) {
            std::cout << buf << std::endl;
        }
};

void testEvtHdlr (FFS::Event evt) {
    std::cout << evt.getData().packet.data << std::endl;
}

int main() {
    std::cout << "test" << std::endl;
    FFS::iotest();

    testEvent = FFS::addEventType(0x01, "testEvent");

    FFS::LocalModule TestModule();
    TestModule.addHandler(testEvent, )

    return 0;
}