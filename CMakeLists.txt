cmake_minimum_required(VERSION 3.8)
project(main)
 
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(./src)

# main program: 
set(MAIN_SOURCE_FILES main.cpp
                      src/distance/levenshtein.cpp
                      src/file/file.cpp
                      src/directories_comparator.cpp
                      src/similarity_entry/entry.cpp)
add_executable(main ${MAIN_SOURCE_FILES})


#unit testing:
#add_subdirectory(tests/googletest)

#set(UNITS_SOURCE_FILES src/graph/graph.cpp tests/graph/unit.cpp)
#add_executable(unit_tests_run ${UNITS_SOURCE_FILES})
#target_link_libraries(unit_tests_run gtest gtest_main)


#benchmarking:
#add_subdirectory(tests/benchmark)

#set(BENCHMARK_SOURCES src/graph/graph.cpp tests/graph/benchmark.cpp)
#add_executable(benchmark_run ${BENCHMARK_SOURCES})
#target_link_libraries(benchmark_run benchmark::benchmark benchmark::benchmark_main)


