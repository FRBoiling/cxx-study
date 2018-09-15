//
// Created by boil on 18-9-12.
//

#ifndef _TCP_ECHO_SERVER_H
#define _TCP_ECHO_SERVER_H

#include "../demo.h"

#define DEFAULT_PORT 7000
#define DEFAULT_BACKLOG 128


class TcpEchoServer {

public:
    void Run();
    void Stop();

    int Bind(int port);
    void ShutdownGracefully();

private:
    struct sockaddr_in addr;
    static uv_loop_t *loop;

private:
    static void on_new_connection(uv_stream_t *server, int status);

    static void alloc_buffer(uv_handle_t *handle, size_t suggested_size, uv_buf_t *buf);

    static void echo_read(uv_stream_t *client, ssize_t nread, const uv_buf_t *buf);

    static void echo_write(uv_write_t *req, int status);

    static void free_write_req(uv_write_t *req);
};


#endif //_TCP_ECHO_SERVER_H
