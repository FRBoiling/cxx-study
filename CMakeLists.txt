cmake_minimum_required(VERSION 3.12)
project(boil_study)

set(CMAKE_CXX_STANDARD 14)

# The version number.
set(VERSION_MAJOR 1)
set(VERSION_MINOR 0)

# configure a header file to pass some of the CMake settings to the source code
configure_file(
        "${PROJECT_SOURCE_DIR}/main_config.h.in"
        "${PROJECT_BINARY_DIR}/main_config.h"
)

# add the binary tree to the search path for include files so that we will find config.h
include_directories("${PROJECT_BINARY_DIR}")

#option(USE_JEMALLOC "use jemalloc" ON)
#option(USE_TCMALLOC "use tcmalloc" OFF)
#
#if (USE_TCMALLOC)
#    #        SET(TCMALLOC_INCLUDE_DIR /usr/local/include/)
#    #        SET(TCMALLOC_LIB /usr/lib/x86_64-linux-gnu)
#    #        INCLUDE_DIRECTORIES(${TCMALLOC_INCLUDE_DIR})
#    #        LINK_DIRECTORIES(${TCMALLOC_LIB})
#elseif (USE_JEMALLOC)
#    SET(JEMALLOC_INCLUDE_DIR /usr/local/include/)
#    SET(JEMALLOC_LIB /usr/local/lib)
#    INCLUDE_DIRECTORIES(${JEMALLOC_INCLUDE_DIR})
#    LINK_DIRECTORIES(${JEMALLOC_LIB})
#endif ()

#SET(LIBUV_INCLUDE_DIR /usr/local/include)
#SET(LIBUV_LIB /usr/local/lib)
#INCLUDE_DIRECTORIES(${LIBUV_INCLUDE_DIR})
#LINK_DIRECTORIES(${LIBUV_LIB})

SET(DIR_DEFINE define)
include_directories(${DIR_DEFINE})


SET(DIR_ZMALLOC zmalloc)
include_directories(${DIR_ZMALLOC})
add_subdirectory(${DIR_ZMALLOC})

SET(DIR_CORE core)
add_subdirectory(${DIR_CORE})

SET(DIR_DEMO demo)
add_subdirectory(${DIR_DEMO})

add_executable(boil_study main.cpp)

TARGET_LINK_LIBRARIES(boil_study zmalloc)
TARGET_LINK_LIBRARIES(boil_study core)
TARGET_LINK_LIBRARIES(boil_study demo)
#TARGET_LINK_LIBRARIES(boil uv)

#if (USE_TCMALLOC)
#    #    TARGET_LINK_LIBRARIES(boil tcmalloc_minimal.so.4)
#elseif (USE_JEMALLOC)
#    TARGET_LINK_LIBRARIES(boil jemalloc)
#endif ()
