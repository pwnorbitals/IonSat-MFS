#ifndef REMOTEMODULE_H_INC
#define REMOTEMODULE_H_INC

#include <cstring>

#define BUF_SIZE 512

namespace FFS {
    class RemoteModule {
        protected:
            char inBuf[BUF_SIZE];
            char outBuf[BUF_SIZE];

        public:
            RemoteModule();
            ~RemoteModule();

            virtual void recvData() = 0;
            virtual void sendData(char* buf, unsigned int inlen) = 0;
            void addIncoming(char* buf, unsigned int inlen);   
    };
};

#endif