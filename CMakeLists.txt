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

################################################################################
# compile_options
################################################################################
add_compile_options( -Wall)
add_compile_options( -g)
add_compile_options( -Wextra)
add_compile_options( -std=c++20)

################################################################################
# build dir
################################################################################
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
