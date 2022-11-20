cmake_minimum_required(VERSION 3.0.0)

project(ServerSide)

set(CLANG_COMPILE_FLAGS "-lcaf_core -lcaf_io -std=c++17")

set(CMAKE_CXX_FLAGS ${CLANG_COMPILE_FLAGS})

<<<<<<< HEAD
#include_directories(${CMAKE_SOURCE_DIR}/include)
=======
set(HEADER_FILES ../server-side/include)

include_directories("../server-side/include/")

add_executable(${PROJECT_NAME} ../server-side/src/Main.cpp)

#add_subdirectory(subprojects/actor-framework)
>>>>>>> parent of 014e640 (2022/11/19, Adding small changes and trying to resolve problem with CMake (not successfully)

#add_subdirectory(subprojects/redis-plus-plus)

add_subdirectory(src)

<<<<<<< HEAD
target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>../server-side/include)

target_link_libraries(${PROJECT_NAME} ServerSideLib -lcaf_core -lcaf_io -lredis++)
=======
target_link_libraries(${PROJECT_NAME} ServerSideLib -lcaf_core -lcaf_io)
>>>>>>> parent of 014e640 (2022/11/19, Adding small changes and trying to resolve problem with CMake (not successfully)
