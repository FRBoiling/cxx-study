//
// Created by boil on 18-9-13.
//

#include <Log.h>
#include "TcpServer.h"


using namespace boil;

using namespace std;

TcpServer::TcpServer(EventLoop *loop, SocketAddr &addr)
        : loop_(loop),
          ipv_(addr.Ipv()),
          accetper_(new TcpAcceptor(loop, addr)),
          onMessageCallback_(nullptr),
          onNewConnectCallback_(nullptr),
          onConnectCloseCallback_(nullptr),
          timerWheel_(loop) {
    accetper_->setNewConnectinonCallback([this](EventLoop *loop, uv_tcp_t *client) {
        string key;
        SocketAddr::AddrToStr(client, key, ipv_);

        Log::Instance()->info("new connect  " + key);


        shared_ptr<TcpConnection> connection(new TcpConnection(loop, key, client));
        if (connection) {
            connection->setMessageCallback(
                    std::bind(&TcpServer::onMessage, this, placeholders::_1, placeholders::_2, placeholders::_3));
            connection->setConnectCloseCallback(std::bind(&TcpServer::closeConnection, this, placeholders::_1));

            addConnnection(key, connection);
            timerWheel_.insertNew(connection);
            if (onNewConnectCallback_)
                onNewConnectCallback_(connection);
        } else {
            Log::Instance()->error("create connection fail. :" + key);
        }

    });

}

TcpServer::TcpServer(const TimerWheel &timerWheel_) {

}

TcpServer::~TcpServer() {

}

void TcpServer::start() {
    timerWheel_.start();
    accetper_->listen();
}

void TcpServer::addConnnection(std::string &name, std::shared_ptr<TcpConnection> connection) {
    connnections_.insert(pair<string, shared_ptr<TcpConnection>>(std::move(name), connection));
}

void TcpServer::removeConnnection(std::string &name) {
    connnections_.erase(name);
}

std::shared_ptr<TcpConnection> TcpServer::getConnnection(std::string &name) {
    auto rst = connnections_.find(name);
    if (rst == connnections_.end()) {
        return nullptr;
    }
    return rst->second;
}

void TcpServer::closeConnection(std::string &name) {
    auto connection = getConnnection(name);
    if (nullptr != connection) {
        connection->close([this](std::string &name) {
            auto connection = getConnnection(name);
            if (nullptr != connection) {
                if (onConnectCloseCallback_) {
                    onConnectCloseCallback_(connection);
                }
                connnections_.erase(name);
            }

        });
    }
}

void TcpServer::onMessage(std::shared_ptr<TcpConnection> connection, const char *buf, ssize_t size) {
    if(onMessageCallback_)
        onMessageCallback_(connection,buf,size);
    timerWheel_.insert(connection);
}

void TcpServer::setMessageCallback(OnMessageCallback callback) {
    onMessageCallback_ = callback;
}

void TcpServer::setNewConnectCallback(OnNewConnectCallback callback) {
    onNewConnectCallback_ = callback;
}

void TcpServer::setConnectCloseCallback(OnConnectCloseCallback callback) {
    onConnectCloseCallback_ = callback;
}

void TcpServer::write(std::shared_ptr<TcpConnection> connection, const char *buf, unsigned int size,
                      AfterWriteCallback callback) {
    if(connection)
    {
        connection->write(buf,size, callback);
    }
    else if (callback)
    {
        WriteInfo info = { WriteInfo::Disconnected,const_cast<char*>(buf),size };
        callback(info);
    }
}

void TcpServer::write(std::string &name, const char *buf, unsigned int size, AfterWriteCallback callback) {
    auto connection = getConnnection(name);
    if(connection)
    {
        connection->write(buf,size, callback);
    }
    else if (callback)
    {
        WriteInfo info = { WriteInfo::Disconnected,const_cast<char*>(buf),size };
        callback(info);
    }
}

void TcpServer::writeInLoop(std::shared_ptr<TcpConnection> connection, const char *buf, unsigned int size,
                            AfterWriteCallback callback) {
    if(connection)
    {
        connection->writeInLoop(buf,size,callback);
    }
    else if (callback)
    {
        Log::Instance()->warn("try write a disconnect connection.");
        WriteInfo info = { WriteInfo::Disconnected,const_cast<char*>(buf),size };
        callback(info);
    }
}

void TcpServer::writeInLoop(std::string &name, const char *buf, unsigned int size, AfterWriteCallback callback) {
    auto connection = getConnnection(name);
    if(connection)
    {
        connection->writeInLoop(buf,size,callback);
    }
    else if (callback)
    {
        Log::Instance()->warn(std::string("try write a disconnect connection.")+name);
        WriteInfo info = { WriteInfo::Disconnected,const_cast<char*>(buf),size };
        callback(info);
    }
}

void TcpServer::setTimeout(unsigned int seconds) {
    timerWheel_.setTimeout(seconds);
}
