//
// Created by boil on 18-8-28.
//

#ifndef _UVCAT_H
#define _UVCAT_H

#include "uv_define.h"

class UvCat {
public:
    const char* path;
    void Run();

private:
    static void on_open(uv_fs_t *req);
    static void on_close(uv_fs_t *req);

    static void on_read(uv_fs_t *req);
    static void on_write(uv_fs_t *req);
};


#endif //_UVCAT_H
