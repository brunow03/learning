cmake_minimum_required(VERSION 3.10)

# Project name and version
project(NEURONS VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add an executable
add_executable(RUN_NEURONS
        ${CMAKE_SOURCE_DIR}/src/main.c
)


add_subdirectory(./src)

include_directories(NEURONS PRIVATE
         ${CMAKE_SOURCE_DIR}/include
)
