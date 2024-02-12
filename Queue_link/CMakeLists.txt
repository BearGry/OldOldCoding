cmake_minimum_required(VERSION 3.23)
project(Queue_link)

set(CMAKE_CXX_STANDARD 11)

add_executable(Queue_link main.cpp Queue.cpp Queue.h link.cpp)
