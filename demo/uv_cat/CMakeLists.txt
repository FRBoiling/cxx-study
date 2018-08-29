aux_source_directory(. DIR_UVCAT)

SET(LIBUV_INCLUDE_DIR /usr/local/include)
SET(LIBUV_LIB /usr/local/lib)
INCLUDE_DIRECTORIES(${LIBUV_INCLUDE_DIR})
LINK_DIRECTORIES(${LIBUV_LIB})

# 生成链接库
add_library (uvcat ${DIR_UVCAT})

target_link_libraries(uvcat uv)