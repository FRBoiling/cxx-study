//
// Created by boil on 18-8-23.
//

#ifndef _CONNECTOR_SERVICE_H
#define _CONNECTOR_SERVICE_H

#include "../serviceframe/IService.h"
#include "ISocketConnector.h"

class ConnectorService : implements ISocketConnector, implements IService {

public:
    void connect(const char* host, const int port) const override;

    void shutdownGracefully() const override;

public:
    void init() override;

    void start() override;

    void stop() override;

    void update(long dt) override;

};


#endif //_CONNECTOR_SERVICE_H
