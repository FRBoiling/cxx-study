//
// Created by boil on 18-9-13.
//

#ifndef BOIL_TCP_ACCEPTOR_H
#define BOIL_TCP_ACCEPTOR_H


#include "SocketAddr.h"
#include "EventLoop.h"

namespace boil {

    using NewConnectionCallback  =    std::function<void(EventLoop *, uv_tcp_t *)>;

    class TcpAcceptor {
    public:
        TcpAcceptor(EventLoop *loop, SocketAddr &addr);

        virtual ~TcpAcceptor();

        void listen();

        bool isListen();

        void setNewConnectionCallback(NewConnectionCallback callback);

        EventLoop *Loop();

        void onNewConnect(uv_tcp_t *client);

    private:
        bool listened_;
        EventLoop *loop_;
        NewConnectionCallback callback_;

        uv_tcp_t server_;
    };

}

#endif //BOIL_TCP_ACCEPTOR_H
