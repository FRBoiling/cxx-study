//
// Created by boil on 18-8-24.
//

#ifndef _SIMPLESERVER_H
#define _SIMPLESERVER_H


#include <AcceptorService.h>
#include "../serviceframe/IService.h"

class SimpleServer : implements IService {
public:
    SimpleServer();

    SimpleServer(AcceptorService *_service);

public:
    void init() override;

    void start() override;

    void stop() override;

    void update(long dt) override;

private:
    AcceptorService *_service;
};


#endif //_SIMPLESERVER_H
