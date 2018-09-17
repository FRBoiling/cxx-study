//
// Created by boil on 18-9-17.
//

#ifndef BOIL_ECHOSERVER_H
#define BOIL_ECHOSERVER_H

#include "../network/TcpServer.h"
#include "../network/EventLoop.h"

class EchoServer : extends boil::TcpServer {
public:
    EchoServer(boil::EventLoop *loop, boil::SocketAddr &addr);

    uint64_t Count();

    void clearCount();

private :
    std::atomic<uint64_t> count_;

    void newMessage(std::shared_ptr<boil::TcpConnection> connection, const char *buf, ssize_t size);
};


#endif //BOIL_ECHOSERVER_H
