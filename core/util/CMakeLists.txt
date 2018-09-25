set(DIR_LOG ../log)
include_directories(${DIR_LOG})

aux_source_directory(. DIR_UTIL)

# 生成链接库
add_library (util ${DIR_UTIL})

target_link_libraries(util log)
