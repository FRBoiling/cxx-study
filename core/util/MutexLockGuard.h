//
// Created by boil on 18-9-27.
//

#ifndef BOIL_MUTEXLOCKGUARD_H
#define BOIL_MUTEXLOCKGUARD_H


#include <boost/noncopyable.hpp>
#include "MutexLock.h"

namespace boil {
// Use as a stack variable, eg.
// int Foo::size() const
// {
//   MutexLockGuard lock(mutex_);
//   return data_.size();
// }
    class MutexLockGuard : boost::noncopyable {
    public:
        explicit MutexLockGuard(MutexLock &mutex):
        mutex_(mutex) {
                mutex_.lock();
        }

        ~MutexLockGuard() {
            mutex_.unlock();
        }

    private:

        MutexLock &mutex_;
    };

}
//
// Prevent misuse like:
// MutexLockGuard(mutex_);
// A tempory object doesn't hold the lock for long!
#define MutexLockGuard(x) error "Missing guard object name"


#endif //BOIL_MUTEXLOCKGUARD_H
