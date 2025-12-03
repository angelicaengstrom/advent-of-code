add_library(secret-entrance SecretEntrance.cpp)

file(GLOB RESOURCE_FILES "${CMAKE_SOURCE_DIR}/01-secret-entrance/resources/*")
file(COPY ${RESOURCE_FILES} DESTINATION ${CMAKE_BINARY_DIR})

target_include_directories(secret-entrance PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})