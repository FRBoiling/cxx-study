aux_source_directory(. DIR_IDLEBASIC)

SET(LIBUV_INCLUDE_DIR /usr/local/include)
SET(LIBUV_LIB /usr/local/lib)
INCLUDE_DIRECTORIES(${LIBUV_INCLUDE_DIR})
LINK_DIRECTORIES(${LIBUV_LIB})

# 生成链接库
add_library (idlebasic ${DIR_IDLEBASIC})

target_link_libraries(idlebasic uv)
