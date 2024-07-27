cmake_minimum_required(VERSION 3.10)

# Project name and version
project(Graphs VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add an executable
add_executable(GRAPHS
        ${CMAKE_SOURCE_DIR}/src/main.c
        ${CMAKE_SOURCE_DIR}/src/graphs.c
)


add_subdirectory(./src)

include_directories(Graphs PRIVATE
         ${CMAKE_SOURCE_DIR}/include
)
