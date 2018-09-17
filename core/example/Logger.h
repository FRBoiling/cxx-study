//
// Created by boil on 18-9-17.
//

#ifndef BOIL_LOGGER_H
#define BOIL_LOGGER_H

#include "../log/ILog.h"

class Logger: implements boil::ILog {
public:
    void warn(const std::string &data) override;

    void error(const std::string &data) override;

    void info(const std::string &data) override;

    void debug(const std::string &data) override;

};

#endif //BOIL_LOGGER_H
