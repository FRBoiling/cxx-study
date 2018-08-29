//
// Created by boil on 18-8-23.
//

#ifndef _I_SOCKET_ACCEPTOR_H
#define _I_SOCKET_ACCEPTOR_H

#include "../util/interface.h"

interface ISocketAcceptor {
public:

    virtual void bind(const int port) const = 0;

    virtual void shutdownGracefully() const = 0;
};


#endif //_I_SOCKET_ACCEPTOR_H
