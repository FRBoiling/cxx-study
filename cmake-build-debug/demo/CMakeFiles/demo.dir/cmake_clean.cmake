file(REMOVE_RECURSE
  "libdemo.pdb"
  "libdemo.a"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/demo.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
