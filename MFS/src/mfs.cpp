#include <iostream>
#include <thread>
#include <functional>
#include <queue>
#include <string>
#include <csignal>

#include "FFS.h"


struct consoleEvent {
    std::string msg;
};

struct signalEvent {
    int signal;
};


// From : https://stackoverflow.com/questions/2721421
template<typename T>
class Queue {
   public:
      void Push ( T x ) {
          theQueue.push( x );
          for (auto c : theCallBacks) { c(*this); }
      }
      T Pop() { auto data = T{theQueue.front()}; theQueue.pop(); return data; }
      void Register( std::function<void(Queue<T>&)> ql ) { theCallBacks.push_back( ql ); }

  private:
    std::queue <T> theQueue;
    std::vector<std::function<void(Queue<T>&)>> theCallBacks;

};

void cinFct(Queue<std::string>& recvQ, Queue<std::string>& sendQ) {
    auto go = true;
    recvQ.Register([&go](Queue<std::string>& q) { if(q.Pop() == "stop") { go = false; }});
    auto input = std::string{};
    while(go) {
        std::cin >> input;
        sendQ.Push(input);
    }
}


template<typename ctrlr_t>
class ConsoleModule{

        ctrlr_t& FFS;
        Queue<std::string> sendQ;
        Queue<std::string> recvQ;
        std::thread cinThread; // Simulates execution on external hardware

        public:
            void recvData(Queue<std::string>& q) {
                auto recvd = q.Pop();
                std::cout << "RECEIVED FROM THREAD : " << recvd << std::endl;
                FFS.emit(consoleEvent{recvd});
            }

            void sendData(Queue<std::string>& q, std::string s)  { q.Push(s); }

            ConsoleModule(ctrlr_t& _FFS) : FFS{_FFS}, sendQ{}, recvQ{} {
                std::thread t([this]() { cinFct(recvQ, sendQ); });
                cinThread = std::move(t);
                recvQ.Register([this](Queue<std::string>& q) -> void {this->recvData(q);});
                // recvQ.Register(std::bind(&ConsoleModule::recvData, this, std::placeholders::_1));
            }

            ~ConsoleModule() { sendQ.Push("stop"); cinThread.join(); }
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
    // auto consoleChan = FFS::make_chan<consoleEvent>(consoleEvtHdlr);

    auto consoleChan = FFS::Chan{consoleEvent{}, std::make_tuple(consoleEvtHdlr)};
    auto chans = std::make_tuple(consoleChan);

    // For non-static member function
    // std::bind(&module3::print, &m3, std::placeholders::_1)

    auto controller = FFS::Controller{modes, chans};
    auto testModule = ConsoleModule{controller};

    // std::signal(SIGINT, [&](int signum) -> void { controller.emit(signalEvent{signum});  });

    controller.start();

    return 0;
}
