//
// Created by boil on 18-9-13.
//

#include "TimerWheel.h"

using namespace boil;

TimerWheel::TimerWheel(EventLoop *loop)
        : TimerWheel(loop, 0) {

}

TimerWheel::TimerWheel(EventLoop *loop, unsigned int timeout)
        : index_(0),
          timeoutSec_(timeout),
          timer_(loop, 1000, 1000,
                 std::bind(&TimerWheel::wheelCallback, this, std::placeholders::_1, std::placeholders::_2), nullptr) {

}

void TimerWheel::setTimeout(unsigned int second) {
    timeoutSec_ = second;
}

void TimerWheel::start() {
    if(timeoutSec_)
    {
        wheel.resize(timeoutSec_);
        timer_.start();
    }
}

void TimerWheel::insert(std::shared_ptr<TcpConnection> connection) {
    if(!timeoutSec_)
        return;
    std::shared_ptr<ConnectionElement> conn = connection->Element().lock();
    if(conn)
    {
        wheel[index_].insert(conn);
    }
}

void TimerWheel::insertNew(std::shared_ptr<TcpConnection> connection) {
    if(!timeoutSec_)
        return;
    std::shared_ptr<ConnectionElement> conn(new ConnectionElement(connection));
    connection->setElement(conn);
    wheel[index_].insert(conn);
}

void TimerWheel::wheelCallback(Timer<void *> *, void *) {
    if(!timeoutSec_)
        return;
    if(++index_ ==timeoutSec_)
    {
        index_=0;
    }
    wheel[index_].clear();
}
