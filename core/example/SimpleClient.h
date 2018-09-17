//
// Created by boil on 18-8-24.
//

#ifndef _SIMPLECLIENT_H
#define _SIMPLECLIENT_H


#include "../serviceframe/IService.h"

class SimpleClient : implements IService{
public:
    SimpleClient();
    virtual ~SimpleClient();
public:

    void init() override;

    void start() override;

    void stop() override;

    void update(long dt) override;


};


#endif //_SIMPLECLIENT_H
