# cmake_minimum_required(VERSION <specify CMake version here>)
project(interpolation)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(interpolation
        glut.h
        interpolation.cpp
        shapes.cpp
        shapes.h
        stdafx.cpp
        stdafx.h
        targetver.h
        point.h storage.cpp storage.h)
