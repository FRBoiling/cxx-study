//
// Created by boil on 18-8-28.
//

#ifndef _IDLE_BASIC_H
#define _IDLE_BASIC_H

#include "zmalloc_define.h"
#include "uv_define.h"

class IdleBasic {
public:
    IdleBasic();

    ~IdleBasic();

public:
    void Run();

public:
    static int64_t counter;
    static void wait_for_a_while(uv_idle_t *handle);
};


#endif //_IDLE_BASIC_H
