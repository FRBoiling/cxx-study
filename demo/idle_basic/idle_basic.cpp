//
// Created by boil on 18-8-28.
//

#include "idle_basic.h"

IdleBasic::IdleBasic() {
}

IdleBasic::~IdleBasic() {
    IdleBasic::counter = 0;
}

int64_t IdleBasic::counter = 0;

void IdleBasic::wait_for_a_while(uv_idle_t *handle) {
    IdleBasic:: counter ++;
    if (IdleBasic::counter  >= 10e6)
        uv_idle_stop(handle);
}

void IdleBasic::run() {
    uv_idle_t idler;

    uv_idle_init(uv_default_loop(), &idler);
    uv_idle_start(&idler, wait_for_a_while);

    printf("Idling...\n");
    uv_run(uv_default_loop(), UV_RUN_DEFAULT);

    uv_loop_close(uv_default_loop());
}


