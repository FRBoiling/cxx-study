//
// Created by boil on 18-8-23.
//

#ifndef _ISERVICE_H
#define _ISERVICE_H

#include "../util/interface.h"
#include "ServiceState.h"

interface IService {
public:

    virtual void init() = 0;

    virtual void start() = 0;

    virtual void stop() = 0;

    virtual void update(long dt) = 0;


default:
    ServiceState *_state=new ServiceState();

    void setState(ServiceState *state) {
        _state = state;
    }

    ServiceState *getState() {
        return _state;
    }

    bool isRunning() {
        return ServiceState::RUNNING == *_state;
    }

    bool isStopped() {
        return ServiceState::STOPPED == *_state;
    }

};


#endif //_ISERVICE_H
