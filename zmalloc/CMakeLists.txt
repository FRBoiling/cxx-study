set(CMAKE_C_STANDARD 99)

aux_source_directory(. DIR_ZMALLOC)

configure_file(
        "${PROJECT_SOURCE_DIR}/zmalloc/zmalloc_config.h.in"
        "${PROJECT_BINARY_DIR}/zmalloc/zmalloc_config.h"
)

option(USE_JEMALLOC "use jemalloc" ON)
option(USE_TCMALLOC "use tcmalloc" OFF)

if (USE_TCMALLOC)
    #        SET(TCMALLOC_INCLUDE_DIR /usr/local/include/)
    #        SET(TCMALLOC_LIB /usr/lib/x86_64-linux-gnu)
    #        INCLUDE_DIRECTORIES(${TCMALLOC_INCLUDE_DIR})
    #        LINK_DIRECTORIES(${TCMALLOC_LIB})
elseif (USE_JEMALLOC)
    SET(JEMALLOC_INCLUDE_DIR /usr/local/include/)
    SET(JEMALLOC_LIB /usr/local/lib)
    INCLUDE_DIRECTORIES(${JEMALLOC_INCLUDE_DIR})
    LINK_DIRECTORIES(${JEMALLOC_LIB})
endif ()

# 生成链接库
add_library (zmalloc ${DIR_ZMALLOC})

if (USE_TCMALLOC)
    #    TARGET_LINK_LIBRARIES(boil tcmalloc_minimal.so.4)
elseif (USE_JEMALLOC)
    TARGET_LINK_LIBRARIES(zmalloc jemalloc)
endif ()