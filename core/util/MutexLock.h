//
// Created by boil on 18-9-27.
//

#ifndef BOIL_MUTEXLOCK_H
#define BOIL_MUTEXLOCK_H

#include "Mutex.h"
#include "CurrentThread.h"
#include <pthread.h>
#include <boost/noncopyable.hpp>

namespace boil {

// Use as data member of a class, eg.
//
// class Foo
// {
//  public:
//   int size() const;
//
//  private:
//   mutable MutexLock mutex_;
//   std::vector<int> data_; // GUARDED BY mutex_
// };
    class MutexLock : boost::noncopyable {
    public:
        MutexLock()
                : holder_(0) {
            MCHECK(pthread_mutex_init(&mutex_, NULL));
        }

        ~MutexLock() {
            assert(holder_ == 0);
            MCHECK(pthread_mutex_destroy(&mutex_));
        }

        // must be called when locked, i.e. for assertion
        bool isLockedByThisThread() const {
            return holder_ == CurrentThread::tid();
        }

        void assertLocked() const {
            assert(isLockedByThisThread());
        }

        // internal usage

        void lock() {
            MCHECK(pthread_mutex_lock(&mutex_));
            assignHolder();
        }

        void unlock() {
            unassignHolder();
            MCHECK(pthread_mutex_unlock(&mutex_));
        }

        pthread_mutex_t *getPthreadMutex() /* non-const */
        {
            return &mutex_;
        }

    private:
        friend class Condition;

        class UnassignGuard : boost::noncopyable {
        public:
            UnassignGuard(MutexLock &owner)
                    : owner_(owner) {
                owner_.unassignHolder();
            }

            ~UnassignGuard() {
                owner_.assignHolder();
            }

        private:
            MutexLock &owner_;
        };

        void unassignHolder() {
            holder_ = 0;
        }

        void assignHolder() {
            holder_ = CurrentThread::tid();
        }

        pthread_mutex_t mutex_;
        pid_t holder_;
    };

}
#endif //BOIL_MUTEXLOCK_H
