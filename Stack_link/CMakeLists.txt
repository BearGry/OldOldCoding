cmake_minimum_required(VERSION 3.23)
project(Stack_link)

set(CMAKE_CXX_STANDARD 11)

add_executable(Stack_link main.cpp Stack.cpp Stack.h link.cpp)
