# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/darisishe/Рабочий стол/contest"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/darisishe/Рабочий стол/contest/build/Debug"

# Include any dependencies generated for this target.
include tests/benchmark/test/CMakeFiles/benchmark_name_gtest.dir/depend.make

# Include the progress variables for this target.
include tests/benchmark/test/CMakeFiles/benchmark_name_gtest.dir/progress.make

# Include the compile flags for this target's objects.
include tests/benchmark/test/CMakeFiles/benchmark_name_gtest.dir/flags.make

tests/benchmark/test/CMakeFiles/benchmark_name_gtest.dir/benchmark_name_gtest.cc.o: tests/benchmark/test/CMakeFiles/benchmark_name_gtest.dir/flags.make
tests/benchmark/test/CMakeFiles/benchmark_name_gtest.dir/benchmark_name_gtest.cc.o: ../../tests/benchmark/test/benchmark_name_gtest.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/darisishe/Рабочий стол/contest/build/Debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/benchmark/test/CMakeFiles/benchmark_name_gtest.dir/benchmark_name_gtest.cc.o"
	cd "/home/darisishe/Рабочий стол/contest/build/Debug/tests/benchmark/test" && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/benchmark_name_gtest.dir/benchmark_name_gtest.cc.o -c "/home/darisishe/Рабочий стол/contest/tests/benchmark/test/benchmark_name_gtest.cc"

tests/benchmark/test/CMakeFiles/benchmark_name_gtest.dir/benchmark_name_gtest.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/benchmark_name_gtest.dir/benchmark_name_gtest.cc.i"
	cd "/home/darisishe/Рабочий стол/contest/build/Debug/tests/benchmark/test" && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/darisishe/Рабочий стол/contest/tests/benchmark/test/benchmark_name_gtest.cc" > CMakeFiles/benchmark_name_gtest.dir/benchmark_name_gtest.cc.i

tests/benchmark/test/CMakeFiles/benchmark_name_gtest.dir/benchmark_name_gtest.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/benchmark_name_gtest.dir/benchmark_name_gtest.cc.s"
	cd "/home/darisishe/Рабочий стол/contest/build/Debug/tests/benchmark/test" && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/darisishe/Рабочий стол/contest/tests/benchmark/test/benchmark_name_gtest.cc" -o CMakeFiles/benchmark_name_gtest.dir/benchmark_name_gtest.cc.s

# Object files for target benchmark_name_gtest
benchmark_name_gtest_OBJECTS = \
"CMakeFiles/benchmark_name_gtest.dir/benchmark_name_gtest.cc.o"

# External object files for target benchmark_name_gtest
benchmark_name_gtest_EXTERNAL_OBJECTS =

tests/benchmark/test/benchmark_name_gtest: tests/benchmark/test/CMakeFiles/benchmark_name_gtest.dir/benchmark_name_gtest.cc.o
tests/benchmark/test/benchmark_name_gtest: tests/benchmark/test/CMakeFiles/benchmark_name_gtest.dir/build.make
tests/benchmark/test/benchmark_name_gtest: tests/benchmark/src/libbenchmark.a
tests/benchmark/test/benchmark_name_gtest: lib/libgmock_main.a
tests/benchmark/test/benchmark_name_gtest: lib/libgmock.a
tests/benchmark/test/benchmark_name_gtest: lib/libgtest.a
tests/benchmark/test/benchmark_name_gtest: tests/benchmark/test/CMakeFiles/benchmark_name_gtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/darisishe/Рабочий стол/contest/build/Debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable benchmark_name_gtest"
	cd "/home/darisishe/Рабочий стол/contest/build/Debug/tests/benchmark/test" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/benchmark_name_gtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/benchmark/test/CMakeFiles/benchmark_name_gtest.dir/build: tests/benchmark/test/benchmark_name_gtest

.PHONY : tests/benchmark/test/CMakeFiles/benchmark_name_gtest.dir/build

tests/benchmark/test/CMakeFiles/benchmark_name_gtest.dir/clean:
	cd "/home/darisishe/Рабочий стол/contest/build/Debug/tests/benchmark/test" && $(CMAKE_COMMAND) -P CMakeFiles/benchmark_name_gtest.dir/cmake_clean.cmake
.PHONY : tests/benchmark/test/CMakeFiles/benchmark_name_gtest.dir/clean

tests/benchmark/test/CMakeFiles/benchmark_name_gtest.dir/depend:
	cd "/home/darisishe/Рабочий стол/contest/build/Debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/darisishe/Рабочий стол/contest" "/home/darisishe/Рабочий стол/contest/tests/benchmark/test" "/home/darisishe/Рабочий стол/contest/build/Debug" "/home/darisishe/Рабочий стол/contest/build/Debug/tests/benchmark/test" "/home/darisishe/Рабочий стол/contest/build/Debug/tests/benchmark/test/CMakeFiles/benchmark_name_gtest.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : tests/benchmark/test/CMakeFiles/benchmark_name_gtest.dir/depend

