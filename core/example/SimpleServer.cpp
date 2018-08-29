//
// Created by boil on 18-8-24.
//

#include "SimpleServer.h"

void SimpleServer::init() {
    _service->init();
}

void SimpleServer::start() {
    _service->start();
}

void SimpleServer::stop() {
    _service->stop();
}

void SimpleServer::update(long dt) {
    _service->update(dt);
}

SimpleServer::SimpleServer(AcceptorService *_service) : _service(_service) {}
