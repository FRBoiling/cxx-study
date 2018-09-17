set(CMAKE_CXX_STANDARD 14)

aux_source_directory(. DIR_NETWORK)

set(DIR_UTIL ../util)
include_directories(${DIR_UTIL})

set(DIR_LOG ../log)
include_directories(${DIR_LOG})

set(DIR_FRAME ../serviceframe)
include_directories(${DIR_FRAME})

#SET(LIBUV_INCLUDE_DIR /usr/local/include)
#SET(LIBUV_LIB /usr/local/lib)
#INCLUDE_DIRECTORIES(${LIBUV_INCLUDE_DIR})
#LINK_DIRECTORIES(${LIBUV_LIB})

# 生成链接库
add_library(network ${DIR_NETWORK})

target_link_libraries(network util)
target_link_libraries(network log)
target_link_libraries(network serviceframe)
#TARGET_LINK_LIBRARIES(network uv)
