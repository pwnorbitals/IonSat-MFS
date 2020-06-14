#include "FFS.h"

#define BLOCK_DYNALLOC false

// From : https://www.embedded.com/preventing-dynamic-allocation/
// declare this function, but don't define it
#if BLOCK_DYNALLOC == true
    void *operator_blocker();
    void *operator new(std::size_t) {    return operator_blocker();    }
    void *operator new[](std::size_t) {    return operator_blocker();    }
#endif

namespace FFS {
    void iotest() { std::cout << "FFS test" << std::endl; }
}

int main() {
    FFS::iotest();
}
