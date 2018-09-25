//
// Created by boil on 18-9-25.
//

#ifndef BOIL_FILE_H
#define BOIL_FILE_H

#include <boost/noncopyable.hpp>
#include <stdexcept>
#include "Types.h"

namespace boil {

    class File : boost::noncopyable {
    public:
        File(const char *file)
                : fp_(::fopen(file, "rb")) {
        }

        ~File() {
            if (fp_) {
                ::fclose(fp_);
            }
        }

        bool valid() const { return fp_; }

        string readBytes(int n) {
            char buf[n];
            ssize_t nr = ::fread(buf, 1, n, fp_);
            if (nr != n)
                throw std::logic_error("no enough data");
            return string(buf, n);
        }

        int32_t readInt32() {
            int32_t x = 0;
            ssize_t nr = ::fread(&x, 1, sizeof(int32_t), fp_);
            if (nr != sizeof(int32_t))
                throw std::logic_error("bad int32_t data");
            return be32toh(x);
        }

        uint8_t readUInt8() {
            uint8_t x = 0;
            ssize_t nr = ::fread(&x, 1, sizeof(uint8_t), fp_);
            if (nr != sizeof(uint8_t))
                throw std::logic_error("bad uint8_t data");
            return x;
        }

    private:
        FILE *fp_;
    };

}
#endif //BOIL_FILE_H
