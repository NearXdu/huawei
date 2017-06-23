cmake_minimum_required(VERSION 2.6)

PROJECT (HUAWEI)

find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "-O0 -ggdb -std=c++11")
set(CMAKE_CXX_COMPILER "g++")


set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

SET(SRC_DIR ../src)
add_executable(1 ${SRC_DIR}/1.cpp)

SET(SRC_DIR ../src)
add_executable(2 ${SRC_DIR}/2.cpp)

SET(SRC_DIR ../src)
add_executable(3 ${SRC_DIR}/3.cpp)

SET(SRC_DIR ../src)
add_executable(4 ${SRC_DIR}/4.cpp)

SET(SRC_DIR ../src)
add_executable(5 ${SRC_DIR}/5.cpp)
target_link_libraries(5 boost_regex)


