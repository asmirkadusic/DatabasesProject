cmake_minimum_required(VERSION 3.0.0)

project(ClientSide)

set(CLANG_COMPILE_FLAGS "-lcaf_core -lcaf_io -lcaf_net -lcaf_openssl -lhiredis -lredis++ -std=c++17")

set(CMAKE_CXX_FLAGS ${CLANG_COMPILE_FLAGS})

# set(CAF_BUILD_STATIC_ONLY)
#include_directories(${CMAKE_SOURCE_DIR}/include)
set(HEADER_FILES ../client-side/include)

include_directories("../client-side/include/")

add_executable(${PROJECT_NAME} ../client-side/src/ClientMain.cpp)

#add_subdirectory(subprojects/actor-framework)

#add_subdirectory(subprojects/redis-plus-plus)

add_subdirectory(src)

target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>../client-side/include)

target_link_libraries(${PROJECT_NAME} ClientSideLib -lcaf_core -lcaf_io -lredis++ -lhiredis -lcaf_net -lcaf_openssl)
