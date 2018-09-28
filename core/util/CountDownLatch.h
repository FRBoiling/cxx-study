//
// Created by boil on 18-9-26.
//

#ifndef BOIL_COUNTDOWNLATCH_H
#define BOIL_COUNTDOWNLATCH_H

#include <boost/noncopyable.hpp>
#include "MutexLockGuard.h"
#include "Condition.h"

namespace boil
{

    class CountDownLatch : boost::noncopyable
    {
    public:

        explicit CountDownLatch(int count);

        void wait();

        void countDown();

        int getCount() const;

    private:
        mutable MutexLock mutex_;
        Condition condition_;
        int count_;
    };

}


#endif //BOIL_COUNTDOWNLATCH_H
