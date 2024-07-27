cmake_minimum_required(VERSION 3.0)
project(Algorithms)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Specify source files
file(GLOB SOURCES "src/*.c")

# Specify include directories
include_directories(include)

# Add executable target
add_executable(RUN ${SOURCES})
