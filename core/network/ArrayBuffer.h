//
// Created by boil on 18-9-17.
//

#ifndef BOIL_AARRYBUFFER_H
#define BOIL_AARRYBUFFER_H

#include "IPacketBuffer.h"

//ArrayBuffer(cycle)
//---------------------------------------
//  Null  |   byte   |  byte   |  Null
//---------------------------------------
//        ��                      ��
//   read position           write position

//              ��can not write
//---------------------------------------
//  byte   |   byte   |  byte   |  byte
//---------------------------------------
//         ��          ��
//   write position  read position

//not thread safe.


namespace boil {

    struct SizeInfo {
        uint32_t size;
        uint32_t part1;
        uint32_t part2;
    };

    class ArrayBuffer : implements IPacketBuffer {
    public:
        ArrayBuffer();

        ~ArrayBuffer();

        int append(const char *data, int size) override;

        int read(Packet &packet) override;

        int usableSize();

        void usableSizeInfo(SizeInfo &info);

        int readSize();

        void readSizeInfo(SizeInfo &info);

    public:
        static const uint32_t BufferSize;

    private:
        int addWriteIndex(uint32_t size);

        int addReadIndex(uint32_t size);

    private:
        uint8_t *buffer_;
        uint32_t writeIndex_;
        uint32_t readIndex_;
    };
}


#endif //BOIL_AARRYBUFFER_H
