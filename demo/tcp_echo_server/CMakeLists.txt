aux_source_directory(. DIR_TCP_ECHO_SERVER)

SET(LIBUV_INCLUDE_DIR /usr/local/include)
SET(LIBUV_LIB /usr/local/lib)
INCLUDE_DIRECTORIES(${LIBUV_INCLUDE_DIR})
LINK_DIRECTORIES(${LIBUV_LIB})

# 生成链接库
add_library (tcpechoserver ${DIR_TCP_ECHO_SERVER})

target_link_libraries(tcpechoserver uv)