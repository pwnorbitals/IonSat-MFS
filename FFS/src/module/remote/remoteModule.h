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
            RemoteModule() : inBuf{0}, outBuf{0} {};
            ~RemoteModule() {};

            virtual void recvData() = 0;
            virtual void sendData(char* buf, unsigned int inlen) = 0;

            void addIncoming(char* buf, unsigned int inlen) {
                unsigned int curlen = strlen(inBuf);

                if (inlen >= BUF_SIZE - curlen) {
                    strncpy(this->inBuf, buf, BUF_SIZE); // Needs test for inlen == BUF_SIZE - curlen to check for zero-termination
                }  else {
                    strncat(this->inBuf, buf, inlen);    // Needs test too anyway
                }

                FFS::Event::ParseBuffer(inBuf);

            };   
    };
};

#endif