cmake_minimum_required(VERSION 3.0.0)

project(ServerSide)

set(CLANG_COMPILE_FLAGS "-lcaf_core -lcaf_io -std=c++17")

set(CMAKE_CXX_FLAGS ${CLANG_COMPILE_FLAGS})

set(HEADER_FILES ../server-side/include)

include_directories("../server-side/include/")

add_executable(${PROJECT_NAME} ../server-side/src/Main.cpp)

#add_subdirectory(subprojects/actor-framework)

#add_subdirectory(subprojects/redis-plus-plus)

add_subdirectory(src)

target_link_libraries(${PROJECT_NAME} ServerSideLib -lcaf_core -lcaf_io)
