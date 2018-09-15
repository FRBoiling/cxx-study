#include <iostream>
#include <stdio.h>
#include "demo/hello_world/hello_world.h"
#include "demo/idle_basic/idle_basic.h"
#include "demo/uv_cat/uv_cat.h"
#include "demo/uv_tee/uv_tee.h"
#include "demo/tcp_echo_server/tcp_echo_server.h"


int main() {
// hello_world
//    HelloWorld *hello = new HelloWorld();
//    hello->Run();
//    delete(hello);

// idle_basic
//    IdleBasic *idleBasic =new IdleBasic();UvTee
//    idleBasic->Run();
//    delete(idleBasic);

//uvcat
//    UvCat *uvCat =new UvCat();
//    uvCat->Run();
//    delete(uvCat);

//uvtee
//    UvTee *uvTee = new UvTee();
//    uvTee->Run();
//    delete (uvTee);

//tcp_echo_server
    TcpEchoServer *tcpEchoServer = new TcpEchoServer();
    tcpEchoServer->Run();


    return 0;
}