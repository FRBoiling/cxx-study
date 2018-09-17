//
// Created by boil on 18-9-17.
//

#include <Packet.h>
#include "EchoServer.h"

#define USED_NO_PACKET 1

EchoServer::EchoServer(boil::EventLoop *loop, boil::SocketAddr &addr) : TcpServer(loop, addr) {
    count_ = 0;
    setMessageCallback(std::bind(&EchoServer::newMessage,this,std::placeholders::_1,std::placeholders::_2,std::placeholders::_3));
}

uint64_t EchoServer::Count() {
    return count_;
}

void EchoServer::clearCount() {
    count_=0;
}

void EchoServer::newMessage(std::shared_ptr<boil::TcpConnection> connection, const char *buf, ssize_t size) {

#if     USED_NO_PACKET
    count_++;
    connection->write(buf,size,nullptr);
#else
    boil::Packet packet;
    connection->appendToBuffer(buf, size);
    while (0 == connection->readFromBuffer(packet))
    {
        count_++;
        connection->write(packet.Buffer(), packet.BufferSize(), nullptr);
    }
#endif

}
