//
// Created by boil on 18-9-13.
//

#include "EventLoop.h"
#include "TcpConnection.h"
#include "Async.h"

using namespace boil;

EventLoop::EventLoop()
        : isRun(false) {
    loop_ = new uv_loop_t();
    ::uv_loop_init(loop_);
}

EventLoop::EventLoop(EventLoop::Mode mode)
        : isRun(false) {
    if (mode == EventLoop::New) {
        loop_ = new uv_loop_t();
        ::uv_loop_init(loop_);
    } else {
        loop_ = uv_default_loop();
    }
}

EventLoop::~EventLoop() {
    if (loop_ != uv_default_loop()) {
        uv_loop_close(loop_);
        delete loop_;
    }
}

EventLoop *EventLoop::DefaultLoop() {
    static EventLoop *defaultLoop = new EventLoop(EventLoop::Mode::Default);
    return defaultLoop;
}

uv_loop_t *EventLoop::hanlde() {
    return loop_;
}

int EventLoop::run() {
    loopThreadId_ = std::this_thread::get_id();
    isRun = true;
    return ::uv_run(loop_, UV_RUN_DEFAULT);
}

int EventLoop::runNoWait() {
    loopThreadId_ = std::this_thread::get_id();
    isRun = true;
    return ::uv_run(loop_, UV_RUN_NOWAIT);
}


bool EventLoop::isRunInLoopThread() {
    if (isRun) {
        return std::this_thread::get_id() == loopThreadId_;
    }
    //EventLoopδ����.
    return false;
}

void EventLoop::runInThisLoop(const std::function<void()> &func) {
    if (nullptr == func)
        return;

    if (isRunInLoopThread()) {
        func();
        return;
    }
    std::function<void()> *funcptr = new std::function<void()>();
    *funcptr = func;
    Async<std::function<void()> *> *handle = new Async<std::function<void()> *>(this,
                                                                                [this](Async<std::function<void()> *> *handle,
                                                                                       std::function<void()> *funcptr) {
                                                                                    (*funcptr)();
                                                                                    delete funcptr;
                                                                                    delete handle;
                                                                                }, funcptr);
    handle->runInLoop();
}

const char *EventLoop::GetErrorMessage(int status) {
    if (WriteInfo::Disconnected == status) {
        static char info[] = "the connection is disconnected";
        return info;
    }
    return uv_strerror(status);
}