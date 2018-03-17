#include "lock.hpp"
using reply::Lock;

Lock::Lock() {
    this->lck = false;
}

void Lock::lock() {
    while(lck.exchange(true));
}

void Lock::unlock() {
    lck = false;
}
