cmake_minimum_required(VERSION 3.9)
project(ex3)

set(CMAKE_CXX_STANDARD 17)

add_executable(ex3 main.cpp Member.cpp Member.h MySingeltonVector.h MySingeltonVector.cpp)