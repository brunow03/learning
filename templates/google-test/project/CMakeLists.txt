cmake_minimum_required(VERSION 3.10)
project(MyTests)

enable_testing()

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(runTests tests/test_example.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
add_test(NAME MyTests COMMAND runTests)
