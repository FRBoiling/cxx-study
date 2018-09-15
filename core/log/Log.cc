//
// Created by boil on 18-9-14.
//

#include "Log.h"

using namespace boil;

void Log::registerInterface(ILog* handle)
{
    handle_ = handle;
    funcs_[Debug] = std::bind(&ILog::debug, handle_, std::placeholders::_1);
    funcs_[Info] = std::bind(&ILog::info, handle_, std::placeholders::_1);
    funcs_[Warn] = std::bind(&ILog::warn, handle_, std::placeholders::_1);
    funcs_[Error] = std::bind(&ILog::error, handle_, std::placeholders::_1);
}
void Log::write(int level,std::string& data)
{
    if ((handle_) &&(level<= Error) && (level >= Debug))
    {
        funcs_[level](data);
    }
}
void Log::write(int level, std::string&& data)
{
    if ((handle_) && (level <= Error))
    {
        funcs_[level](data);
    }
}
void Log::warn(const std::string& data)
{
    if (handle_)
        handle_->warn(data);
}
void Log::warn(const std::string&& data)
{
    if (handle_)
        handle_->warn(data);
}
void Log::error(const std::string& data)
{
    if (handle_)
        handle_->error(data);
}
void Log::error(const std::string&& data)
{
    if (handle_)
        handle_->error(data);
}
void Log::info(const std::string& data)
{
    if (handle_)
        handle_->info(data);
}
void Log::info(const std::string&& data)
{
    if (handle_)
        handle_->info(data);
}
void Log::debug(const std::string& data)
{
    if (handle_)
        handle_->debug(data);
}
void Log::debug(const std::string&& data)
{
    if (handle_)
        handle_->debug(data);
}

//static void ToHex(std::string& message,const char* data,unsigned int size)
//{
//    for (unsigned int i = 0; i < size; i++)
//    {
//        char buf[8];
//        std::sprintf(buf, " 0x%x ", (unsigned char)data[i]);
//        message += buf;
//    }
//}