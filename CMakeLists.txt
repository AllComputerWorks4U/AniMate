cmake_minimum_required(VERSION 3.10)

project(AniMate LANGUAGES CXX )

add_library(Animation SHARED ./src/animation.cpp)
add_executable(Main ./src/main.cpp)

target_include_directories(Animation PUBLIC ./src/include/animate.h)

target_link_libraries(Main PRIVATE Animation)

target_compile_definitions(Animation PRIVATE DLL_EXPORTING)