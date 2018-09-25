//
// Created by boil on 18-9-13.
//

#include <Log.h>
#include "TcpAcceptor.h"

using namespace boil;

TcpAcceptor::TcpAcceptor(EventLoop *loop, SocketAddr &addr)
:loop_(loop),
callback_(nullptr){
    uv_tcp_init(loop_->hanlde(), &server_);
    uv_tcp_bind(&server_, addr.Addr(),0);
    server_.data = (void* )this;
}

TcpAcceptor::~TcpAcceptor() {

}

void TcpAcceptor::listen() {
    uv_listen((uv_stream_t*) &server_, 128,
                [](uv_stream_t *server, int status)
                {
                    if (status < 0)
                    {
                        Log::Instance()->error (std::string("new connection error :")+ EventLoop::GetErrorMessage(status));
                        return;
                    }
                    TcpAcceptor* accept = static_cast<TcpAcceptor*>(server->data);
                    uv_tcp_t* client =new uv_tcp_t();
                    ::uv_tcp_init(accept->Loop()->hanlde(), client);

                    if ( 0 == ::uv_accept(server, (uv_stream_t*) client))
                    {
                        accept->onNewConnect(client);
                    }
                    else
                    {
                        ::uv_close((uv_handle_t*) client, NULL);
                        delete client;
                    }
                });
    listened_ = true;
}

bool TcpAcceptor::isListen() {
    return listened_;
}

void TcpAcceptor::setNewConnectionCallback(NewConnectionCallback callback) {
    callback_ = callback;
}

EventLoop *TcpAcceptor::Loop() {
    return loop_;
}

void TcpAcceptor::onNewConnect(uv_tcp_t *client) {
    if(nullptr !=callback_)
    {
        callback_(loop_,client);
    }
}
