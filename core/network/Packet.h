//
// Created by boil on 18-9-17.
//

#ifndef BOIL_PACKET_H
#define BOIL_PACKET_H

//Packet:
//------------------------------------------------
//  head  |  size   | reserve | data   |  end   |
// 1 byte | 2 bytes | 4 bytes | N bytes| 1 byte |
//------------------------------------------------
#include <string>

namespace boil {
    class Packet {
    public:
        Packet();
        ~Packet();

        void fill(const char* data, uint16_t size);
        void update(char* data, uint16_t size);
        void clear();

        const char* getData();
        const uint16_t DataSize();
        const char* Buffer();
        const uint16_t BufferSize();

        template<typename NumType>
        static void UnpackNum(const uint8_t* data, NumType& num);

        template<typename NumType>
        static void PackNum(char* data, NumType size);

        static uint32_t PacketMinSize();

    public:
        enum DataMode
        {
            BigEndian,
            LittleEndian
        };

        static uint8_t HeadByte;
        static uint8_t EndByte;
        static DataMode Mode;
        uint32_t reserve_;

    private:
        char* buffer_;
        uint16_t bufferSize_;
    };

    template<typename NumType>
    inline void Packet::UnpackNum(const uint8_t* data, NumType& num)
    {
        num = 0;
        auto size = static_cast<int>(sizeof(NumType));
        if (Packet::DataMode::BigEndian == Packet::Mode)
        {
            for (int i = 0; i < size; i++)
            {
                num <<= 8;
                num |= data[i];

            }
        }
        else
        {
            for (int i = size-1; i >= 0; i--)
            {
                num <<= 8;
                num |= data[i];
            }
        }
    }

    template<typename NumType>
    inline void Packet::PackNum(char* data, NumType num)
    {
        int size = static_cast<int>(sizeof(NumType));
        if (Packet::DataMode::BigEndian == Packet::Mode)
        {
            for (int i = size-1; i >= 0; i--)
            {
                data[i] = num & 0xff;
                num >>= 8;
            }
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                data[i] = num & 0xff;
                num >>= 8;
            }
        }
    }
}



#endif //BOIL_PACKET_H
