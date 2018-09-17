#include <iostream>
#include <stdio.h>
#include "demo/hello_world/hello_world.h"
#include "demo/idle_basic/idle_basic.h"
#include "demo/uv_cat/uv_cat.h"
#include "demo/uv_tee/uv_tee.h"
//#include "demo/tcp_echo_server/tcp_echo_server.h"

#include "core/example/EchoServer.h"
#include "core/example/Logger.h"
#include "core/log/Log.h"

using namespace boil;
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
//    TcpEchoServer *tcpEchoServer = new TcpEchoServer();
//    tcpEchoServer->Run();

//定义事件分发器类
    EventLoop *loop = new EventLoop();
    //or
//    EventLoop* loop = EventLoop::DefaultLoop();

#if    TEST_SIGNAL
    //接管SIGPIPE信号。
    Signal signal(loop, 13, [](int sig) {
        //SIGPIPE
    });

#endif


    //server对象
#if   TEST_SERVER
#if    TEST_IPV6
    SocketAddr addr1("0:0:0:0:0:0:0:0", 10002, SocketAddr::Ipv6);
#else
    SocketAddr addr("0.0.0.0", 10002, SocketAddr::Ipv4);
#endif
    EchoServer server(loop, addr);
    //心跳超时
    server.setTimeout(40);
    server.start();
#endif


    //client对象
#if  TEST_CLIENT
#if    TEST_IPV6
    SocketAddr addr2("0:0:0:0:0:0:0:1", 10002, SocketAddr::Ipv6);
#else
    SocketAddr addr2("127.0.0.1", 10002, SocketAddr::Ipv4);
#endif
    Client client(loop);
    client.connectToServer(addr2);
#endif


    //loop线程中异步执行函数
#if  TEST_ASYNC
    Async<int> *handle = new Async<int>(loop,
                                        [](Async<int> *ptr, int data) {
                                            std::cout << data << std::endl;
                                            delete ptr;
                                        },
                                        1024);
    handle->runInLoop();
#endif


    //定时器测试
#if  TEST_TIMER
    Timer<void *> timer(loop, 1000, 1000,
                        [&client](Timer<void *> *, void *) {
                            std::cout << "timer callback with null arg" << std::endl;
                        }, nullptr);
    timer.start();

    //定时器只运行一次及释放,可用于tcp重连,单次消息超时等。
    Timer<int> *pTimer = new Timer<int>(loop, 1000, 0,
                                        [](Timer<int> *handle, int data) {
                                            std::cout << "timer callback run onice with arg:" << data << std::endl;
                                            handle->close([](Timer<int> *ptr) {
                                                std::cout << "release timer handle." << std::endl;
                                                //释放定时器对象。
                                                delete ptr;
                                            });
                                        }, 1024);
    pTimer->start();
#endif

    //log接口绑定
#if  TEST_LOG
    auto log = boil::Log::Instance();
    log->registerInterface(new Logger);

    log->debug("debug message");
    log->warn("warn message");
    log->error("error message");
    log->info("info message");
#endif
    loop->run();
    return 0;
}