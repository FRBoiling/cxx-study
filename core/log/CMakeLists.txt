set(CMAKE_CXX_STANDARD 14)

aux_source_directory(. DIR_LOG)

set(DIR_UTIL ../util)
include_directories(${DIR_UTIL})

# 生成链接库
add_library (log ${DIR_LOG})

