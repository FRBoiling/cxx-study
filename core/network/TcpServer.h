//
// Created by boil on 18-9-13.
//

#ifndef _TCPSERVER_H
#define _TCPSERVER_H

#include <map>
#include "EventLoop.h"
#include "SocketAddr.h"
#include "TcpConnection.h"
#include "TcpAcceptor.h"
#include "TimerWheel.h"

namespace boil {
    class TcpServer {
    public:
        TcpServer(EventLoop *loop, SocketAddr &addr);

        TcpServer(const TimerWheel &timerWheel_);

        virtual ~TcpServer();

        void start();

        void addConnnection(std::string &name, std::shared_ptr<TcpConnection> connection);

        void removeConnnection(std::string &name);

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
        std::shared_ptr<TcpAcceptor> accetper_;
        std::map<std::string, std::shared_ptr<TcpConnection>> connnections_;


        OnMessageCallback onMessageCallback_;
        OnNewConnectCallback onNewConnectCallback_;
        OnConnectCloseCallback onConnectCloseCallback_;
        TimerWheel timerWheel_;
    };
}

#endif //_TCPSERVER_H
