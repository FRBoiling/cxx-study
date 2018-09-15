//
// Created by boil on 18-8-28.
//
#include <assert.h>
#include <stdlib.h>
#include "uv_cat.h"


static uv_buf_t iov;
static char buffer[1024];
static uv_fs_t open_req;
static uv_fs_t read_req;
static uv_fs_t write_req;

void UvCat::Run() {

    char dir[1024] = {0};
    path = "../data/test";
    realpath(path, dir);
    fprintf(stdout, "real path: %s\n", dir);
    uv_fs_open(uv_default_loop(), &open_req, dir, O_RDONLY, 0, on_open);
    uv_run(uv_default_loop(), UV_RUN_DEFAULT);

    uv_fs_req_cleanup(&open_req);
    uv_fs_req_cleanup(&read_req);
    uv_fs_req_cleanup(&write_req);
}

void UvCat::on_read(uv_fs_t *req) {
    if (req->result < 0) {
        fprintf(stderr, "Read error: %s\n", uv_strerror(req->result));
    } else if (req->result == 0) {
        uv_fs_t close_req;
        // synchronous
        uv_fs_close(uv_default_loop(), &close_req, open_req.result, on_close);
    } else if (req->result > 0) {
        iov.len = req->result;
        uv_fs_write(uv_default_loop(), &write_req, 1, &iov, 1, -1, on_write);
    }
}

void UvCat::on_write(uv_fs_t *req) {
    if (req->result < 0) {
        fprintf(stderr, "Write error: %s\n", uv_strerror((int) req->result));
    } else {
        uv_fs_read(uv_default_loop(), &read_req, open_req.result, &iov, 1, -1, on_read);
    }
}

void UvCat::on_open(uv_fs_t *req) {
    // The request passed to the callback is the same as the one the call setup
    // function was passed.
    assert(req == &open_req);
    if (req->result >= 0) {
        iov = uv_buf_init(buffer, sizeof(buffer));
        uv_fs_read(uv_default_loop(), &read_req, req->result,
                   &iov, 1, -1, on_read);
    } else {
        fprintf(stderr, "error opening file %s: %s\n", req->path, uv_strerror((int) req->result));
    }
}

void UvCat::on_close(uv_fs_t *req) {
    if (req->result >= 0) {
        fprintf(stdout, "close file %s: %s\n", req->path, uv_strerror((int) req->result));

    } else {
        fprintf(stderr, "error closing file %s: %s\n", req->path, uv_strerror((int) req->result));
    }
}

