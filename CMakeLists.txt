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

SET(SRC_DIR ../src)
add_executable(6 ${SRC_DIR}/6.cpp)

SET(SRC_DIR ../src)
add_executable(7 ${SRC_DIR}/7.cpp)

SET(SRC_DIR ../src)
add_executable(8 ${SRC_DIR}/8.cpp)

SET(SRC_DIR ../src)
add_executable(9 ${SRC_DIR}/9.cpp)

SET(SRC_DIR ../src)
add_executable(10 ${SRC_DIR}/10.cpp)

SET(SRC_DIR ../src)
add_executable(11 ${SRC_DIR}/11.cpp)

SET(SRC_DIR ../src)
add_executable(12 ${SRC_DIR}/12.cpp)

SET(SRC_DIR ../src)
add_executable(13 ${SRC_DIR}/13.cpp)

SET(SRC_DIR ../src)
add_executable(14 ${SRC_DIR}/14.cpp)

SET(SRC_DIR ../src)
add_executable(15 ${SRC_DIR}/15.cpp)

SET(SRC_DIR ../src)
add_executable(16 ${SRC_DIR}/16.cpp)

SET(SRC_DIR ../src)
add_executable(17 ${SRC_DIR}/17.cpp)

SET(SRC_DIR ../src)
add_executable(18 ${SRC_DIR}/18.cpp)

SET(SRC_DIR ../src)
add_executable(19 ${SRC_DIR}/19.cpp)

SET(SRC_DIR ../src)
add_executable(20 ${SRC_DIR}/20.cpp)

SET(SRC_DIR ../src)
add_executable(21 ${SRC_DIR}/21.cpp)

SET(SRC_DIR ../src)
add_executable(22 ${SRC_DIR}/22.cpp)

SET(SRC_DIR ../src)
add_executable(23 ${SRC_DIR}/23.cpp)


SET(SRC_DIR ../src)
add_executable(24 ${SRC_DIR}/24.cpp)

SET(SRC_DIR ../src)
add_executable(25 ${SRC_DIR}/25.cpp)

SET(SRC_DIR ../src)
add_executable(26 ${SRC_DIR}/26.cpp)

SET(SRC_DIR ../src)
add_executable(27 ${SRC_DIR}/27.cpp)

SET(SRC_DIR ../src)
add_executable(28 ${SRC_DIR}/28.cpp)

SET(SRC_DIR ../src)
add_executable(29 ${SRC_DIR}/29.cpp)

SET(SRC_DIR ../src)
add_executable(30 ${SRC_DIR}/30.cpp)






