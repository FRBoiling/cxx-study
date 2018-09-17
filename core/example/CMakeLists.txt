set(CMAKE_CXX_STANDARD 14)

aux_source_directory(. DIR_EXAMPLE)

set(DIR_UTIL ../util)
include_directories(${DIR_UTIL})

set(DIR_LOG ../log)
include_directories(${DIR_LOG})

set(DIR_NETWORK ../network)
include_directories(${DIR_NETWORK})

# 生成链接库
add_library (example ${DIR_EXAMPLE})

# 添加链接库
target_link_libraries(example util)
target_link_libraries(example log)
target_link_libraries(example network)

