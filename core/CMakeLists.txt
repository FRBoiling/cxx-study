cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 14)

aux_source_directory(. DIR_CORE)

configure_file(
        "${PROJECT_SOURCE_DIR}/core/core_config.h.in"
        "${PROJECT_BINARY_DIR}/core/core_config.h"
)

include_directories("${PROJECT_BINARY_DIR}/core")

add_subdirectory(network)
add_subdirectory(log)
add_subdirectory(util)
add_subdirectory(example)
add_subdirectory(serviceframe)
#set(DIR_UTIL util)
#include_directories(${DIR_UTIL})

# 生成链接库
add_library (core ${DIR_CORE})

# 添加链接库
target_link_libraries(core network)
target_link_libraries(core log)
target_link_libraries(core util)
target_link_libraries(core example)
target_link_libraries(core serviceframe)
