cmake_minimum_required(VERSION 3.23)
project(matrix)

set(CMAKE_CXX_STANDARD 14)

include_directories(ex00)

add_executable(matrix
        ex00/Matrix.cpp
        ex00/Matrix.hpp
        ex00/Vector.hpp)
