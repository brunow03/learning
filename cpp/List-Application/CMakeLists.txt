cmake_minimum_required(VERSION 3.10)

# Project name and version
project(To-Do-List-Application VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Setting wxWidgets
set(wxWidgets_CONFIGURATION mswu)
set(wxWidgets_USE_LIBS)
find_package(wxWidgets COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})

# Add an executable
add_executable(Application
    ${CMAKE_SOURCE_DIR}/src/Task.cpp
    ${CMAKE_SOURCE_DIR}/src/MainFrame.cpp
    ${CMAKE_SOURCE_DIR}/src/App.cpp
)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Link libraries to the target
target_link_libraries(Application PRIVATE ${wxWidgets_LIBRARIES})

# Add subdirectory (if you need to include additional CMakeLists.txt)
add_subdirectory(./src)
