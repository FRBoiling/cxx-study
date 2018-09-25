//
// Created by boil on 18-9-20.
//

#ifndef BOIL_TIMEZONE_H
#define BOIL_TIMEZONE_H

#include "copyable.h"
#include "Types.h"
#include "Date.h"
#include <time.h>
#include <memory>
#include <vector>

namespace boil {

    class TimeZone : public copyable {
    public:
        explicit TimeZone(const char *zonefile);

        TimeZone(int eastOfUtc, const char *tzname);  // a fixed timezone
        TimeZone() {}  // an invalid timezone


        // default copy ctor/assignment/dtor are Okay.
        bool valid() const {
            // 'explicit operator bool() const' in C++11
            return static_cast<bool>(data_);
        }

        struct tm toLocalTime(time_t secondsSinceEpoch) const;

        time_t fromLocalTime(const struct tm &) const;

        // gmtime(3)
        static struct tm toUtcTime(time_t secondsSinceEpoch, bool yday = false);

        // timegm(3)
        static time_t fromUtcTime(const struct tm &);

        // year in [1900..2500], month in [1..12], day in [1..31]
        static time_t fromUtcTime(int year, int month, int day, int hour, int minute, int seconds);

        struct Data;

    private:
        std::shared_ptr<Data> data_;
    };

    struct Localtime {
        time_t gmtOffset;
        bool isDst;
        int arrbIdx;

        Localtime(time_t offset, bool dst, int arrb)
                : gmtOffset(offset), isDst(dst), arrbIdx(arrb) {}
    };


    struct Transition {
        time_t gmttime;
        time_t localtime;
        int localtimeIdx;

        Transition(time_t t, time_t l, int localIdx)
                : gmttime(t), localtime(l), localtimeIdx(localIdx) {}
    };

    struct Comp
    {
        bool compareGmt;

        Comp(bool gmt)
                : compareGmt(gmt)
        {
        }

        bool operator()(const Transition& lhs, const Transition& rhs) const
        {
            if (compareGmt)
                return lhs.gmttime < rhs.gmttime;
            else
                return lhs.localtime < rhs.localtime;
        }

        bool equal(const Transition& lhs, const Transition& rhs) const
        {
            if (compareGmt)
                return lhs.gmttime == rhs.gmttime;
            else
                return lhs.localtime == rhs.localtime;
        }
    };


}

#endif //BOIL_TIMEZONE_H
