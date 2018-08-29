//
// Created by boil on 18-8-23.
//

#ifndef _I_SOCKET_CONNECTOR_H
#define _I_SOCKET_CONNECTOR_H

#include "../util/interface.h"

interface ISocketConnector {
public:

    virtual void connect(const char* host, const int port) const = 0;

    virtual void shutdownGracefully() const = 0;
};

#endif //_I_SOCKET_CONNECTOR_H
