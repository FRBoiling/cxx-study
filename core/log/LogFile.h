//
// Created by boil on 18-9-26.
//

#ifndef BOIL_LOGFILE_H
#define BOIL_LOGFILE_H


#include <boost/noncopyable.hpp>
#include <boost/scoped_ptr.hpp>
#include "../util/Types.h"
#include "../util/FileUtil.h"
#include "../util/Mutex.h"

namespace boil {

    class LogFile : boost::noncopyable {
    public:
        LogFile(const string &basename,
                off_t rollSize,
                bool threadSafe = true,
                int flushInterval = 3,
                int checkEveryN = 1024);

        ~LogFile();

        void append(const char *logline, int len);

        void flush();

        bool rollFile();

    private:
        void append_unlocked(const char *logline, int len);

        static string getLogFileName(const string &basename, time_t *now);

        const string basename_;
        const off_t rollSize_;
        const int flushInterval_;
        const int checkEveryN_;

        int count_;

        boost::scoped_ptr<MutexLock> mutex_;
        time_t startOfPeriod_;
        time_t lastRoll_;
        time_t lastFlush_;
        boost::scoped_ptr<FileUtil::AppendFile> file_;

        const static int kRollPerSeconds_ = 60 * 60 * 24;
    };

}

#endif //BOIL_LOGFILE_H
