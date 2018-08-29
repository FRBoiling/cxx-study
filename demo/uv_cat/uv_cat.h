//
// Created by boil on 18-8-28.
//

#ifndef BOIL_STUDY_UVCAT_H
#define BOIL_STUDY_UVCAT_H

#include "uv_define.h"

class uv_cat {
public:

    const char* path;
    void run();

public:
    static void on_open(uv_fs_t *req);
    static void on_close(uv_fs_t *req);

    static void on_read(uv_fs_t *req);
    static void on_write(uv_fs_t *req);
};


#endif //BOIL_STUDY_UVCAT_H
