cmake_minimum_required(VERSION 3.16)
project(advent-of-code)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(01-secret-entrance)

add_executable(advent-of-code main.cpp)

target_link_libraries(advent-of-code PRIVATE secret-entrance)