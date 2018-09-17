//
// Created by boil on 18-9-14.
//

#ifndef BOIL_ILOG_H
#define BOIL_ILOG_H


#include <string>
#include "../util/interface.h"

namespace boil{
    interface ILog {
    public:
        virtual ~ILog() {}

        virtual void warn(const std::string &data) = 0;

        virtual void error(const std::string &data) = 0;

        virtual void info(const std::string &data) = 0;

        virtual void debug(const std::string &data) = 0;
    };
}


#endif //BOIL_ILOG_H
