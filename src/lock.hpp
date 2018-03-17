#ifndef lock_hpp
#define lock_hpp

#include "dependencies.hpp"

#include <atomic>
using std::atomic;

namespace reply {
    
    class Lock {
        
    public:
        Lock();
        
        void lock();
        void unlock();
        
    private:
        atomic<bool> lck;
        
    };
    
}

#endif
