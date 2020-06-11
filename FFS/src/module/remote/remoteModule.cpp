#include "remoteModule.h"

namespace FFS {
    RemoteModule::RemoteModule() : inBuf{0}, outBuf{0} {};
    RemoteModule::~RemoteModule() {};

    void RemoteModule::addIncoming(char* buf, unsigned int inlen) {
        auto curlen = strlen(inBuf);

        if (inlen >= BUF_SIZE - curlen) {
            strncpy(this->inBuf, buf, BUF_SIZE); // Needs test for inlen == BUF_SIZE - curlen to check for zero-termination
        }  else {
            strncat(this->inBuf, buf, inlen);    // Needs test too anyway
        }

        FFS::Event::ParseBuffer(inBuf);

    }; 
}