# -----------------------------------------------------------------------------
# CMake project wrapper Makefile
# -----------------------------------------------------------------------------

# set the minimum required version of CMake
cmake_minimum_required(VERSION 3.17)

# set the project name
project(nanotekspice)

# set the standard c++ compiler
set(CMAKE_CXX_STANDARD 20)

# set the flags for the c++ compiler
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")

add_executable(nanotekspice TekSpice.cpp utils/RegUtils.cpp)