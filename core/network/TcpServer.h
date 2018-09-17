//
// Created by boil on 18-9-13.
//

#ifndef BOIL_TCPSERVER_H
#define BOIL_TCPSERVER_H
#include <map>
#include "EventLoop.h"
#include "SocketAddr.h"
#include "TcpConnection.h"
#include "TcpAcceptor.h"
#include "TimerWheel.h"
#include "../util/abstract.h"

namespace boil {

    abstract TcpServer {
    public:
        TcpServer(EventLoop *loop, SocketAddr &addr);

        TcpServer(const TimerWheel &timerWheel_);

        virtual ~TcpServer();

        void start();

        void addConnection(std::string &name, std::shared_ptr<TcpConnection> connection);

        void removeConnection(std::string &name);

        std::shared_ptr<TcpConnection> getConnnection(std::string &name);

        void closeConnection(std::string &name);

        void onMessage(std::shared_ptr<TcpConnection> connection, const char *buf, ssize_t size);

        void setMessageCallback(OnMessageCallback callback);

        void setNewConnectCallback(OnNewConnectCallback callback);

        void setConnectCloseCallback(OnConnectCloseCallback callback);

        void write(std::shared_ptr<TcpConnection> connection, const char *buf, unsigned int size,
                   AfterWriteCallback callback = nullptr);

        void write(std::string &name, const char *buf, unsigned int size, AfterWriteCallback callback = nullptr);

        void writeInLoop(std::shared_ptr<TcpConnection> connection, const char *buf, unsigned int size,
                         AfterWriteCallback callback);

        void writeInLoop(std::string &name, const char *buf, unsigned int size, AfterWriteCallback callback);

        void setTimeout(unsigned int seconds);

    protected:
        EventLoop *loop_;
    private:
        SocketAddr::IPV ipv_;
        std::shared_ptr<TcpAcceptor> acceptor_;
        std::map<std::string, std::shared_ptr<TcpConnection>> connections_;

        OnMessageCallback onMessageCallback_;
        OnNewConnectCallback onNewConnectCallback_;
        OnConnectCloseCallback onConnectCloseCallback_;
        TimerWheel timerWheel_;
    };
}

#endif //BOIL_TCPSERVER_H
