cmake_minimum_required(VERSION 3.17.5)
project(laba3)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(googletest)
add_executable(laba3 main.cpp BinaryTree.h func.cpp func.h Complex.h Heap.h Tests.cpp menu.cpp menu.h)
include_directories(googletest/googletest/include)
target_link_libraries(laba3 gtest gtest_main)