# Minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Project name
project(LearningOpenCV)

# Set the output directories for binary and library files
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/obj)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/obj)

# Add include directories
include_directories(include)

# Add source files
file(GLOB_RECURSE SOURCES src/*.cpp)

# Add an executable
add_executable(OPENCV ${SOURCES})

# Find Package
set( OpenCV_DIR "C:/Program Files/opencv/build" )
option( OpenCV_STATIC OFF )
find_package( OpenCV REQUIRED )

# Set Static Link Runtime Library
if( OpenCV_STATIC )
	foreach( flag_var
		CMAKE_C_FLAGS CMAKE_C_FLAGS_DEBUG CMAKE_C_FLAGS_RELEASE
		CMAKE_C_FLAGS_MINSIZEREL CMAKE_C_FLAGS_RELWITHDEBINFO
		CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
		CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO )
		if( ${flag_var} MATCHES "/MD" )
			string( REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}" )
		endif()
	endforeach()
endif()

if( OpenCV_FOUND )
	# Additional Include Directories
	include_directories( ${OpenCV_INCLUDE_DIRS} )

	# Additional Library Directories
	link_directories( ${OpenCV_LIB_DIR} )

	# Additional Dependencies
	target_link_libraries( OPENCV ${OpenCV_LIBS} )
endif()