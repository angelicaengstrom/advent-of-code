add_library(printing-department PrintingDepartment.cpp)

file(GLOB RESOURCE_FILES "${CMAKE_SOURCE_DIR}/04-printing-department/resources/*")
file(COPY ${RESOURCE_FILES} DESTINATION ${CMAKE_BINARY_DIR})

target_include_directories(printing-department PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})