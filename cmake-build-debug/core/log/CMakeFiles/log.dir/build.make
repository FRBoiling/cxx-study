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
include core/log/CMakeFiles/log.dir/depend.make

# Include the progress variables for this target.
include core/log/CMakeFiles/log.dir/progress.make

# Include the compile flags for this target's objects.
include core/log/CMakeFiles/log.dir/flags.make

core/log/CMakeFiles/log.dir/Log.cc.o: core/log/CMakeFiles/log.dir/flags.make
core/log/CMakeFiles/log.dir/Log.cc.o: ../core/log/Log.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/boil/CLionProjects/boil/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object core/log/CMakeFiles/log.dir/Log.cc.o"
	cd /home/boil/CLionProjects/boil/cmake-build-debug/core/log && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/log.dir/Log.cc.o -c /home/boil/CLionProjects/boil/core/log/Log.cc

core/log/CMakeFiles/log.dir/Log.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/log.dir/Log.cc.i"
	cd /home/boil/CLionProjects/boil/cmake-build-debug/core/log && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/boil/CLionProjects/boil/core/log/Log.cc > CMakeFiles/log.dir/Log.cc.i

core/log/CMakeFiles/log.dir/Log.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/log.dir/Log.cc.s"
	cd /home/boil/CLionProjects/boil/cmake-build-debug/core/log && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/boil/CLionProjects/boil/core/log/Log.cc -o CMakeFiles/log.dir/Log.cc.s

# Object files for target log
log_OBJECTS = \
"CMakeFiles/log.dir/Log.cc.o"

# External object files for target log
log_EXTERNAL_OBJECTS =

core/log/liblog.a: core/log/CMakeFiles/log.dir/Log.cc.o
core/log/liblog.a: core/log/CMakeFiles/log.dir/build.make
core/log/liblog.a: core/log/CMakeFiles/log.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/boil/CLionProjects/boil/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library liblog.a"
	cd /home/boil/CLionProjects/boil/cmake-build-debug/core/log && $(CMAKE_COMMAND) -P CMakeFiles/log.dir/cmake_clean_target.cmake
	cd /home/boil/CLionProjects/boil/cmake-build-debug/core/log && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/log.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
core/log/CMakeFiles/log.dir/build: core/log/liblog.a

.PHONY : core/log/CMakeFiles/log.dir/build

core/log/CMakeFiles/log.dir/clean:
	cd /home/boil/CLionProjects/boil/cmake-build-debug/core/log && $(CMAKE_COMMAND) -P CMakeFiles/log.dir/cmake_clean.cmake
.PHONY : core/log/CMakeFiles/log.dir/clean

core/log/CMakeFiles/log.dir/depend:
	cd /home/boil/CLionProjects/boil/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/boil/CLionProjects/boil /home/boil/CLionProjects/boil/core/log /home/boil/CLionProjects/boil/cmake-build-debug /home/boil/CLionProjects/boil/cmake-build-debug/core/log /home/boil/CLionProjects/boil/cmake-build-debug/core/log/CMakeFiles/log.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : core/log/CMakeFiles/log.dir/depend
