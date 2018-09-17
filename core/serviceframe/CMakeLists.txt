set(CMAKE_CXX_STANDARD 14)

aux_source_directory(. DIR_FRAME)

set(DIR_UTIL ../util)
include_directories(${DIR_UTIL})

# 生成链接库
add_library (serviceframe ${DIR_FRAME})