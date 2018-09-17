//
// Created by boil on 18-9-17.
//

#include "Packet.h"

using namespace boil;

uint8_t Packet::HeadByte = 0x7e;
uint8_t Packet::EndByte = 0xe7;
Packet::DataMode Packet::Mode = Packet::DataMode::LittleEndian;

Packet::Packet()
        : reserve_(0),
          buffer_(nullptr),
          bufferSize_(0) {

}

Packet::~Packet() {
    clear();
}

void Packet::fill(const char *data, uint16_t size) {
    clear();

    bufferSize_ = size + PacketMinSize();
    buffer_ = new char[bufferSize_];

    buffer_[0] = HeadByte;
    PackNum(&buffer_[1], size);
    PackNum(&buffer_[3], reserve_);

    std::copy(data, data + size, buffer_ + sizeof(HeadByte) + sizeof(bufferSize_) + sizeof(reserve_));
    buffer_[size + PacketMinSize() - 1] = EndByte;
}

void Packet::update(char *data, uint16_t size) {
    clear();
    UnpackNum((const uint8_t *) (&data[3]), reserve_);
    buffer_ = data;
    bufferSize_ = size;
}


void Packet::clear() {
    if (0 != bufferSize_) {
        delete[] buffer_;
        bufferSize_ = 0;
    }
}

const char *Packet::getData() {
    return buffer_ + sizeof(HeadByte) + sizeof(bufferSize_) + sizeof(reserve_);
}

const uint16_t Packet::DataSize() {
    return bufferSize_ - PacketMinSize();
}

const char *Packet::Buffer() {
    return buffer_;
}

const uint16_t Packet::BufferSize() {
    return bufferSize_;
}

uint32_t Packet::PacketMinSize() {
    return 8;
}