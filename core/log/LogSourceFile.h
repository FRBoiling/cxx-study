//
// Created by boil on 18-9-25.
//

#ifndef BOIL_LOGSOURCEFILE_H
#define BOIL_LOGSOURCEFILE_H

#include <cstring>

class LogSourceFile
{
public:
    template<int N>
    inline LogSourceFile(const char (&arr)[N])
            : data_(arr),
              size_(N-1)
    {
        const char* slash = strrchr(data_, '/'); // builtin function
        if (slash)
        {
            data_ = slash + 1;
            size_ -= static_cast<int>(data_ - arr);
        }
    }

    explicit LogSourceFile(const char* filename)
            : data_(filename)
    {
        const char* slash = strrchr(filename, '/');
        if (slash)
        {
            data_ = slash + 1;
        }
        size_ = static_cast<int>(strlen(data_));
    }

    const char* data_;
    int size_;
};

#endif //BOIL_LOGSOURCEFILE_H
