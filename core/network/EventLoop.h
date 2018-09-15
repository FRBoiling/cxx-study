//
// Created by boil on 18-9-13.
//

#ifndef _EVENTLOOP_H
#define _EVENTLOOP_H

#include <functional>
#include <thread>
#include <atomic>
#include "uv_define.h"

class EventLoop {
public:
    EventLoop();
    ~EventLoop();

public:
    enum Mode
    {
        Default,
        New
    };

    static EventLoop* DefalutLoop();

    int run();
    int runNoWait();
    bool isRunInLoopThread();
    void runInThisLoop(const std::function<void()>& func);
    uv_loop_t* hanlde();

    static const char* GetErrorMessage(int status);

private:
    EventLoop(Mode mode);

    std::thread::id loopThreadId_;
    std::atomic<bool> isRun;
    uv_loop_t* loop_;
};

using EventLoopPtr = std::shared_ptr<EventLoop>;

#endif //_EVENTLOOP_H
