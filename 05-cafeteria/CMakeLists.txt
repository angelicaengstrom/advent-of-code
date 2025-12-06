add_library(cafeteria Cafeteria.cpp)

file(GLOB RESOURCE_FILES "${CMAKE_SOURCE_DIR}/05-cafeteria/resources/*")
file(COPY ${RESOURCE_FILES} DESTINATION ${CMAKE_BINARY_DIR})

target_include_directories(cafeteria PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})