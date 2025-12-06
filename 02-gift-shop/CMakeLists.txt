add_library(gift-shop GiftShop.cpp)

file(GLOB RESOURCE_FILES "${CMAKE_SOURCE_DIR}/02-gift-shop/resources/*")
file(COPY ${RESOURCE_FILES} DESTINATION ${CMAKE_BINARY_DIR})

target_include_directories(gift-shop PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})