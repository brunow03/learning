cmake_minimum_required(VERSION 3.10)

# Project name and version
project(Graphics-learning VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Setting up OpenGL
find_package(OpenGL REQUIRED)
find_package(glfw3 3.3 REQUIRED)
find_package(GLEW REQUIRED)

include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

add_executable(RUN
    ${CMAKE_SOURCE_DIR}/src/main.cpp
    ${CMAKE_SOURCE_DIR}/src/learning.cpp
)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Link libraries to the target
target_link_libraries(RUN OpenGL::GL glfw GLEW::GLEW)

# Add subdirectory (if you need to include additional CMakeLists.txt)
add_subdirectory(./src)
