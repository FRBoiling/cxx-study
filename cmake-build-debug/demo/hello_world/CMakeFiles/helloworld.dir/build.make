# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/boil/Application/clion/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/boil/Application/clion/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/boil/CLionProjects/boil

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/boil/CLionProjects/boil/cmake-build-debug

# Include any dependencies generated for this target.
include demo/hello_world/CMakeFiles/helloworld.dir/depend.make

# Include the progress variables for this target.
include demo/hello_world/CMakeFiles/helloworld.dir/progress.make

# Include the compile flags for this target's objects.
include demo/hello_world/CMakeFiles/helloworld.dir/flags.make

demo/hello_world/CMakeFiles/helloworld.dir/hello_world.cpp.o: demo/hello_world/CMakeFiles/helloworld.dir/flags.make
demo/hello_world/CMakeFiles/helloworld.dir/hello_world.cpp.o: ../demo/hello_world/hello_world.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/boil/CLionProjects/boil/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object demo/hello_world/CMakeFiles/helloworld.dir/hello_world.cpp.o"
	cd /home/boil/CLionProjects/boil/cmake-build-debug/demo/hello_world && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/helloworld.dir/hello_world.cpp.o -c /home/boil/CLionProjects/boil/demo/hello_world/hello_world.cpp

demo/hello_world/CMakeFiles/helloworld.dir/hello_world.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/helloworld.dir/hello_world.cpp.i"
	cd /home/boil/CLionProjects/boil/cmake-build-debug/demo/hello_world && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/boil/CLionProjects/boil/demo/hello_world/hello_world.cpp > CMakeFiles/helloworld.dir/hello_world.cpp.i

demo/hello_world/CMakeFiles/helloworld.dir/hello_world.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/helloworld.dir/hello_world.cpp.s"
	cd /home/boil/CLionProjects/boil/cmake-build-debug/demo/hello_world && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/boil/CLionProjects/boil/demo/hello_world/hello_world.cpp -o CMakeFiles/helloworld.dir/hello_world.cpp.s

# Object files for target helloworld
helloworld_OBJECTS = \
"CMakeFiles/helloworld.dir/hello_world.cpp.o"

# External object files for target helloworld
helloworld_EXTERNAL_OBJECTS =

demo/hello_world/libhelloworld.a: demo/hello_world/CMakeFiles/helloworld.dir/hello_world.cpp.o
demo/hello_world/libhelloworld.a: demo/hello_world/CMakeFiles/helloworld.dir/build.make
demo/hello_world/libhelloworld.a: demo/hello_world/CMakeFiles/helloworld.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/boil/CLionProjects/boil/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libhelloworld.a"
	cd /home/boil/CLionProjects/boil/cmake-build-debug/demo/hello_world && $(CMAKE_COMMAND) -P CMakeFiles/helloworld.dir/cmake_clean_target.cmake
	cd /home/boil/CLionProjects/boil/cmake-build-debug/demo/hello_world && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/helloworld.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
demo/hello_world/CMakeFiles/helloworld.dir/build: demo/hello_world/libhelloworld.a

.PHONY : demo/hello_world/CMakeFiles/helloworld.dir/build

demo/hello_world/CMakeFiles/helloworld.dir/clean:
	cd /home/boil/CLionProjects/boil/cmake-build-debug/demo/hello_world && $(CMAKE_COMMAND) -P CMakeFiles/helloworld.dir/cmake_clean.cmake
.PHONY : demo/hello_world/CMakeFiles/helloworld.dir/clean

demo/hello_world/CMakeFiles/helloworld.dir/depend:
	cd /home/boil/CLionProjects/boil/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/boil/CLionProjects/boil /home/boil/CLionProjects/boil/demo/hello_world /home/boil/CLionProjects/boil/cmake-build-debug /home/boil/CLionProjects/boil/cmake-build-debug/demo/hello_world /home/boil/CLionProjects/boil/cmake-build-debug/demo/hello_world/CMakeFiles/helloworld.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : demo/hello_world/CMakeFiles/helloworld.dir/depend

