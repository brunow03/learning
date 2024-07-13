cmake_minimum_required(VERSION 3.10)

# Project name and version
project(Generic-Algorithms VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add an executable
add_executable(Application
	${CMAKE_SOURCE_DIR}/src/main.cpp
	${CMAKE_SOURCE_DIR}/src/genericalgorithms.cpp
	${CMAKE_SOURCE_DIR}/src/test.cpp
)


add_subdirectory(./src)

include_directories(Genreric-Algorithms PRIVATE
	 ${CMAKE_SOURCE_DIR}/include
)
