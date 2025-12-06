cmake_minimum_required(VERSION 3.16)
project(advent-of-code)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(01-secret-entrance)
add_subdirectory(02-gift-shop)
add_subdirectory(03-lobby)
add_subdirectory(04-printing-department)
add_subdirectory(05-cafeteria)
add_subdirectory(06-trash-compactor)

add_executable(advent-of-code main.cpp)

target_link_libraries(advent-of-code PRIVATE secret-entrance gift-shop lobby printing-department cafeteria trash-compactor)