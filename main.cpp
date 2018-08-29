#include <iostream>
#include <stdio.h>
#include "demo/hello_world/hello_world.h"
#include "demo/idle_basic/idle_basic.h"
#include "demo/uv_cat/uv_cat.h"

int main() {
// hello_world
//    HelloWorld *hello = new HelloWorld();
//    hello->run();
//    delete(hello);

// idle_basic
//    IdleBasic *idleBasic =new IdleBasic();
//    idleBasic->run();
//    delete(idleBasic);

//uvcat
    uv_cat *uvCat =new uv_cat();
    uvCat->run();
    delete(uvCat);


    return 0;
}