//
// Created by boil on 18-9-14.
//

#ifndef BOIL_LOG_H
#define BOIL_LOG_H

#include "ILog.h"
#include "LogLevel.h"
#include <functional>
#include <string.h>

namespace boil {

    class Log {

    public:

        using OutMessageType = std::function<void(const std::string &)>;

        static Log *Instance() {
            static Log single;
            return &single;
        }

    private:
        OutMessageType funcs_[ERROR + 1];

        Log() : handle_(nullptr) {
        }

        ILog *handle_;

    public:
        void registerInterface(ILog *handle);

        void write(int level, std::string &data);

        void write(int level, std::string &&data);

        void warn(const std::string &data);

        void warn(const std::string &&data);

        void error(const std::string &data);

        void error(const std::string &&data);

        void info(const std::string &data);

        void info(const std::string &&data);

        void debug(const std::string &data);

        void debug(const std::string &&data);

    };

    const char* strerror_tl(int savedErrno);

}

#endif //BOIL_LOG_H
