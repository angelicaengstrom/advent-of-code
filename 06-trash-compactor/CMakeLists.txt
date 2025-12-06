add_library(trash-compactor TrashCompactor.cpp)

file(GLOB RESOURCE_FILES "${CMAKE_SOURCE_DIR}/06-trash-compactor/resources/*")
file(COPY ${RESOURCE_FILES} DESTINATION ${CMAKE_BINARY_DIR})

target_include_directories(trash-compactor PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})