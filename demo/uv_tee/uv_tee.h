//
// Created by boil on 18-9-11.
//

#ifndef _UV_TEE_H
#define _UV_TEE_H

#include "../demo.h"

class UvTee {
public:
    void Run();

private:
    const char *path;
    uv_loop_t *loop;

private:
    static void alloc_buffer(uv_handle_t *handle, size_t suggested_size, uv_buf_t *buf);

    static void read_stdin(uv_stream_t *stream, ssize_t nread, const uv_buf_t *buf);

    static void free_write_req(uv_write_t *req);

    static void on_stdout_write(uv_write_t *req, int status);

    static void on_file_write(uv_write_t *req, int status);

    static void write_data(uv_stream_t *dest, size_t size, uv_buf_t buf, uv_write_cb cb);
};


#endif //_UV_TEE_H
