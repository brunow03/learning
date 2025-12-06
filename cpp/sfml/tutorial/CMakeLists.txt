cmake_minimum_required(VERSION 3.28)

project(SFML_TUTORIAL LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
    sfml-system
    sfml-window
    sfml-graphics
)