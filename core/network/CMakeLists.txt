
aux_source_directory(. DIR_NETWORK)

set(DIR_UTIL ../util)
include_directories(${DIR_UTIL})

set(DIR_FRAME ../frame)
include_directories(${DIR_FRAME})

# 生成链接库
add_library (network ${DIR_NETWORK})

