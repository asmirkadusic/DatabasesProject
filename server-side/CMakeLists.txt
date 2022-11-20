cmake_minimum_required(VERSION 3.0.0)

project(ServerSide)

set(CLANG_COMPILE_FLAGS "-lcaf_core -lcaf_io -std=c++17 -lredis++")

set(CMAKE_CXX_FLAGS ${CLANG_COMPILE_FLAGS})

#include_directories(${CMAKE_SOURCE_DIR}/include)

#add_subdirectory(subprojects/redis-plus-plus)
#add_subdirectory(include)

add_subdirectory(src)
add_executable(${PROJECT_NAME} ./src/Main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>../server-side/include)

target_link_libraries(${PROJECT_NAME} ServerSideLib -lcaf_core -lcaf_io -lredis++)
