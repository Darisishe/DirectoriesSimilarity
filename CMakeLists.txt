cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(DirectorySimilarity LANGUAGES CXX CUDA)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(CUDAToolkit REQUIRED)

find_package(TBB REQUIRED)
include_directories(${TBB_INCLUDE_DIRS})

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Define source files for CLI code
set(SRC_FILES
    main.cpp)

# Add the main executable
add_executable(${PROJECT_NAME} ${SRC_FILES})

# Define source files for unit tests
set(TEST_FILES
    tests/directories_comparator/unit.cpp
    tests/metric/unit.cpp)

# Add unit tests
add_executable(UnitTests ${TEST_FILES})

# Add subdirectory for src
add_subdirectory(src)


# Link libraries to the main executable
target_link_libraries(${PROJECT_NAME} PRIVATE 
    ${CUDA_LIBRARIES}
    TBB::tbb
)

# Link libraries to the test executable
target_link_libraries(UnitTests PRIVATE 
    ${CUDA_LIBRARIES}
    ${GTEST_LIBRARIES} 
    TBB::tbb
    gtest_main 
)

# Include necessary directories
include_directories(${CUDA_INCLUDE_DIRS})
include_directories(include)


###########################################################
