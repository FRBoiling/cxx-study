//
// Created by boil on 18-8-23.
//

#ifndef BOIL_STUDY_ACCEPTORSERVICE_H
#define BOIL_STUDY_ACCEPTORSERVICE_H


#include "ISocketAcceptor.h"
#include "../util/interface.h"
#include "../frame/IService.h"

class AcceptorService : implements ISocketAcceptor, implements IService {

public:

    void bind(const int port) const override;

    void shutdownGracefully() const override;

public:

    void init() override;

    void start() override;

    void stop() override;

    void update(long dt) override;

};


#endif //BOIL_STUDY_ACCEPTORSERVICE_H
