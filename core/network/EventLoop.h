//
// Created by boil on 18-9-13.
//

#ifndef BOIL_EVENT_LOOP_H
#define BOIL_EVENT_LOOP_H

#include "uv_define.h"
#include <functional>
#include <atomic>
#include <thread>

namespace boil {

    class EventLoop {
    public:
        EventLoop();

        ~EventLoop();

    public:
        enum Mode {
            Default,
            New
        };

        static EventLoop *DefaultLoop();

        int run();

        int runNoWait();

        bool isRunInLoopThread();

        void runInThisLoop(const std::function<void()> &func);

        uv_loop_t *hanlde();

        static const char *GetErrorMessage(int status);

    private:
        EventLoop(Mode mode);

        std::thread::id loopThreadId_;
        std::atomic<bool> isRun_;
        uv_loop_t *loop_;
    };

    using EventLoopPtr = std::shared_ptr<EventLoop>;

}

#endif //BOIL_EVENT_LOOP_H
