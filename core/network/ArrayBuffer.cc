//
// Created by boil on 18-9-17.
//

#include "ArrayBuffer.h"

using namespace boil;

const uint32_t ArrayBuffer::BufferSize = (1 << 13) + 1;

ArrayBuffer::ArrayBuffer()
        :writeIndex_(0),
         readIndex_(0)
{
    buffer_ = new uint8_t[BufferSize];
}

ArrayBuffer::~ArrayBuffer()
{
    delete[] buffer_;
}


int ArrayBuffer::append(const char* data, int size)
{
    SizeInfo info;
    usableSizeInfo(info);

    if (info.size < (uint32_t)size)
    {
        //���治��
        return 0;
    }
    if (info.part1 >= (uint32_t)size)
    {
        std::copy(data, data + size, buffer_ + writeIndex_);
    }
    else
    {
        std::copy(data, data + info.part1, buffer_ + writeIndex_);
        std::copy(data + info.part1, data + size, buffer_);
    }
    addWriteIndex(size);
    return size;

}

int ArrayBuffer::read(Packet& packet)
{
    while (true)
    {
        while ((readIndex_ != writeIndex_) &&( buffer_[readIndex_] != Packet::HeadByte))
        {
            addReadIndex(1);
        }
        SizeInfo info;
        readSizeInfo(info);
        if (info.size <= Packet::PacketMinSize())
        {
            return -1;
        }

        uint8_t cnt[2];
        int index = readIndex_;
        for (int i = 0; i < 2; i++)
        {
            if (++index == BufferSize)
                index = 0;
            cnt[i] = buffer_[index];
        }
        uint16_t size;
        Packet::UnpackNum(cnt, size);
        if (size + Packet::PacketMinSize() > info.size)
        {
            return -1;
        }
        if (info.part1 >= size + Packet::PacketMinSize())
        {
            int end = readIndex_ + size + Packet::PacketMinSize() - 1;
            if (buffer_[end] != Packet::EndByte)
            {
                //����һ�ֽ�����Ѱ�Ұ�ͷ��
                addReadIndex(1);
                continue;
            }
            char* data = new char[size + Packet::PacketMinSize()];
            std::copy(buffer_+readIndex_, buffer_ + readIndex_ + size + Packet::PacketMinSize(), data);
            packet.update(data, (uint16_t)(size + Packet::PacketMinSize()));
            addReadIndex(size + Packet::PacketMinSize());
            return 0;
        }
        else
        {
            int end = size+ Packet::PacketMinSize()-info.part1-1;
            if (buffer_[end] != Packet::EndByte)
            {
                //����һ�ֽ�����Ѱ�Ұ�ͷ��
                addReadIndex(1);
                continue;
            }
            char* data = new char[size + Packet::PacketMinSize()];
            std::copy(buffer_ + readIndex_, buffer_ + BufferSize, data);
            int remain = size + Packet::PacketMinSize() - info.part1;
            std::copy(buffer_, buffer_ + remain, data+info.part1);
            packet.update(data, (uint16_t)(size + Packet::PacketMinSize()));
            addReadIndex(size + Packet::PacketMinSize());
            return 0;
        }
    }
}

int ArrayBuffer::usableSize()
{
    int usable;
    if (writeIndex_ < readIndex_)
    {
        usable = readIndex_ - writeIndex_ - 1;
    }
    else
    {
        usable = BufferSize + readIndex_- writeIndex_-1;
    }
    return usable;
}

void ArrayBuffer::usableSizeInfo(SizeInfo& info)
{
    if (writeIndex_ < readIndex_)
    {
        info.part1 = readIndex_ - writeIndex_ - 1;
        info.part2 = 0;
    }
    else
    {
        bool readIsZore = (0 == readIndex_);
        info.part1 = readIsZore ? BufferSize - writeIndex_-1: BufferSize - writeIndex_;
        info.part2 = readIsZore ? 0 : readIndex_ - 1;
    }
    info.size = info.part1 + info.part2;
}

int ArrayBuffer::readSize()
{
    int read;
    if (writeIndex_ >= readIndex_)
    {
        read = writeIndex_ - readIndex_;
    }
    else
    {
        read = BufferSize - readIndex_ + writeIndex_;
    }
    return read;
}

void ArrayBuffer::readSizeInfo(SizeInfo& info)
{
    if (writeIndex_ >= readIndex_)
    {
        info.part1 = writeIndex_ - readIndex_;
        info.part2 = 0;
    }
    else
    {
        info.part1 = BufferSize - readIndex_;
        info.part2 = writeIndex_;
    }
    info.size = info.part1 + info.part2;
}

int ArrayBuffer::addWriteIndex(uint32_t size)
{
    if (size > BufferSize)
        return -1;
    writeIndex_ += size;
    if (writeIndex_ >= BufferSize)
        writeIndex_ -= BufferSize;
    return 0;
}

int ArrayBuffer::addReadIndex(uint32_t size)
{
    if (size > BufferSize)
        return -1;
    readIndex_ += size;
    if (readIndex_ >= BufferSize)
        readIndex_ -= BufferSize;
    return 0;
}