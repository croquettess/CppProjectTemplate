cmake_minimum_required(VERSION 3.11.0)
project(project VERSION 0.1.0 LANGUAGES C CXX)

################################################################################
# 开启编译器最高特性
################################################################################
option(COMPILER_FEATURE "Enable compiler features." ON)
include(cmake/std.cmake)

################################################################################
# 拉取子模块
################################################################################
# execute_process(COMMAND git submodule)

add_compile_options( -Wall)
add_compile_options( -g)
add_compile_options( -Wextra)
add_compile_options( -std=c++20)
add_compile_options( -nostdinc++)
add_compile_options( -I/opt/clang+llvm-17.0.1-aarch64-linux-gnu/include/c++/v1)
add_compile_options( -I/opt/clang+llvm-17.0.1-aarch64-linux-gnu/include/aarch64-unknown-linux-gnu/c++/v1)

################################################################################
# libc++
################################################################################
set(libc++
    -L/opt/clang+llvm-17.0.1-aarch64-linux-gnu/lib/aarch64-unknown-linux-gnu
    -stdlib=libc++
)

add_subdirectory(src)

add_subdirectory(tools)

################################################################################
# install
################################################################################
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/app"
        CACHE PATH "${CMAKE_SOURCE_DIR}/app" FORCE)
endif()
message(STATUS "install: ${CMAKE_INSTALL_PREFIX}")
