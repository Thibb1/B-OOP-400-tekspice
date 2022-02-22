# -----------------------------------------------------------------------------
# CMake project wrapper Makefile
# -----------------------------------------------------------------------------

# set the minimum required version of CMake
cmake_minimum_required(VERSION 3.17)

# project name
set(PROJECT_NAME nanotekspice)

# set the project name
project(${PROJECT_NAME})

# standard c++ compiler
set(CMAKE_CXX_STANDARD 20)

# flags for the c++ compiler
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

# debug flags
set(CMAKE_CXX_FLAGS_DEBUG_INIT "${CMAKE_CXX_FLAGS_DEBUG_INIT} -g")

# source files
set(SRC_FILES   TekSpice.cpp
                src/Compute.cpp
                src/utils/RegUtils.cpp
                src/parser/Parser.cpp
                src/components/Factory.cpp
                src/components/AComponent.cpp
                src/components/chipsets/CInput.cpp
                src/components/chipsets/COutput.cpp
                src/components/chipsets/CClock.cpp
                src/components/chipsets/CFalse.cpp
                src/components/chipsets/CTrue.cpp
                )

# include directories
include_directories(src
    src/components
    src/components/chipsets
    src/parser
    src/utils)

# create the executable
add_executable(${PROJECT_NAME} ${SRC_FILES})
