cmake_minimum_required(VERSION 3.23)
project(String_malloc)

set(CMAKE_CXX_STANDARD 11)

add_executable(String_malloc main.cpp String.cpp String.h)
