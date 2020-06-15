#include <iostream>
#include <thread>
#include <functional>
#include <queue>
#include <string>

#include "FFS.h"


struct consoleEvent {
    std::string msg;
};


// From : https://stackoverflow.com/questions/2721421
template<typename T>
class Queue {
   public:
      void Push ( T x ) {
          theQueue.push( x );
          for (auto i = 0; i < theCallBacks.size(); i++) { theCallBacks[i](*this); }
      }
      T Pop() { auto data = T{theQueue.front()}; theQueue.pop(); return data; }
      void Register( std::function<void(Queue<std::string>&)> ql ) { theCallBacks.push_back( ql ); }

  private:
    std::queue <T> theQueue;
    std::vector<std::function<void(Queue<std::string>&)>> theCallBacks;

};

void cinFct(Queue<std::string> recvQ, Queue<std::string> sendQ) {
    auto input = std::string{};
    while(true) {
        std::cin >> input;
        sendQ.Push(input);
    }
}


template<typename ctrlr_t>
class ConsoleModule{

        ctrlr_t FFS;
        Queue<std::string> sendQ;
        Queue<std::string> recvQ;
        std::thread cinThread; // Simulates execution on external hardware

        public:
            void recvData(Queue<std::string>& q) {
                auto recvd = q.Pop();
                std::cout << "RECEIVED FROM THREAD : " << recvd << std::endl;
                auto evt = consoleEvent{recvd};
                FFS.get().emit(evt);
            }

            void sendData(Queue<std::string>& q, std::string s)  { q.Push(s); }

            ConsoleModule(ctrlr_t _FFS) : FFS{_FFS}, sendQ{}, recvQ{}, cinThread{cinFct, sendQ, recvQ} {
                //auto fct = std::function{[=](auto && ...args) { recvData(args...); }};
                recvQ.Register(std::bind(&ConsoleModule::recvData, *this, std::placeholders::_1));
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

    auto controller = FFS::Controller{modes, chans};
    auto testModule = ConsoleModule{std::cref(controller)};

    controller.start();

    return 0;
}
