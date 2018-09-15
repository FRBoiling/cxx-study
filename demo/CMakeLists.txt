set(CMAKE_CXX_STANDARD 14)

aux_source_directory(. DIR_DEMO)

configure_file(
        "${PROJECT_SOURCE_DIR}/demo/demo_config.h.in"
        "${PROJECT_BINARY_DIR}/demo/demo.h"
)

include_directories("${PROJECT_BINARY_DIR}/demo")

add_subdirectory(hello_world)
add_subdirectory(idle_basic)
add_subdirectory(uv_cat)
add_subdirectory(uv_tee)
add_subdirectory(tcp_echo_server)

# 生成链接库
add_library (demo ${DIR_DEMO})

# 添加链接库
target_link_libraries(demo helloworld)
target_link_libraries(demo idlebasic)
target_link_libraries(demo uvcat)
target_link_libraries(demo uvtee)
target_link_libraries(demo tcpechoserver)
