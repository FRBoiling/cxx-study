//
// Created by boil on 18-9-17.
//

#include <iostream>
#include "Logger.h"
#include "../util/TimeZone.h"

void Logger::warn(const std::string &data) {
    std::cout << "[warn] :" << data << std::endl;
}

void Logger::error(const std::string &data) {
    std::cout << "[error] :" << data << std::endl;
}

void Logger::info(const std::string &data) {
    std::cout << "[info] :" << data << std::endl;
}

void Logger::debug(const std::string &data) {
    std::cout << "[debug] :" << data << std::endl;
}
