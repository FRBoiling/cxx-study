//
// Created by boil on 18-9-14.
//

#ifndef BOIL_LOG_H
#define BOIL_LOG_H


#include <string>
#include <functional>
#include "ILog.h"

namespace boil {

    class Log {

    public:
        enum Level {
            Debug = 0,
            Info,
            Warn,
            Error
        };

        using OutMessageType = std::function<void(const std::string &)>;

        static Log *Instance() {
            static Log single;
            return &single;
        }

    private:
        OutMessageType funcs_[Error + 1];

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
}

#endif //BOIL_LOG_H
