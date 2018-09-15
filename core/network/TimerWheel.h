//
// Created by boil on 18-9-13.
//

#ifndef BOIL_TIMERWHEEL_H
#define BOIL_TIMERWHEEL_H

#include <set>
#include <vector>
#include "EventLoop.h"
#include "TcpConnection.h"
#include "ConnectionElement.h"

namespace boil {

    class TimerWheel {
    public:
        TimerWheel(EventLoop *loop);

        TimerWheel(EventLoop *loop, unsigned int timeout);

        void setTimeout(unsigned int);

        void start();

        void insert(std::shared_ptr<TcpConnection> connnection);

        void insertNew(std::shared_ptr<TcpConnection> connection);

    private:
        unsigned int index_;
        unsigned int timeoutSec_;
        Timer<void *> timer_;

        std::vector<std::set<std::shared_ptr<ConnectionElement>>> wheel;

        void wheelCallback(Timer<void *> *, void *);
    };

}

#endif //BOIL_TIMERWHEEL_H
