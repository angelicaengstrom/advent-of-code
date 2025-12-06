add_library(lobby Lobby.cpp)

file(GLOB RESOURCE_FILES "${CMAKE_SOURCE_DIR}/03-lobby/resources/*")
file(COPY ${RESOURCE_FILES} DESTINATION ${CMAKE_BINARY_DIR})

target_include_directories(lobby PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})