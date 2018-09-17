//
// Created by boil on 18-9-17.
//

#ifndef BOIL_PACKETBUFFER_H
#define BOIL_PACKETBUFFER_H

#include "Packet.h"
#include "../util/interface.h"

namespace boil{

interface IPacketBuffer
{

public:
    virtual int append(const char* data, int size) = 0;
    virtual int read(Packet& packet) = 0;
};
}


#endif //BOIL_PACKETBUFFER_H
