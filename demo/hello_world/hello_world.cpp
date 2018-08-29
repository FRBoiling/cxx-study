//
// Created by boil on 18-8-27.
//

#include "hello_world.h"

HelloWorld::HelloWorld() {

}

HelloWorld::~HelloWorld() {

}

void HelloWorld::run() {
    uv_loop_t *loop = (uv_loop_t *) malloc(sizeof(uv_loop_t));
    uv_loop_init(loop);

    printf("Now quitting.\n");
    uv_run(loop, UV_RUN_DEFAULT);

    uv_loop_close(loop);
    free(loop);
}


