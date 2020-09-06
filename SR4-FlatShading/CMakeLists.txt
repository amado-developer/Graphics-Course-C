cmake_minimum_required(VERSION 3.17)
project(SR4_FlatShading)

set(CMAKE_CXX_STANDARD 20)

add_executable(SR4_FlatShading main.cpp Render.cpp Render.h Obj.cpp Obj.h Math.cpp Math.h)