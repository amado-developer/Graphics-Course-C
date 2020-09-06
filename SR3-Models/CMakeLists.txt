cmake_minimum_required(VERSION 3.17)
project(SR3_Models)

set(CMAKE_CXX_STANDARD 20)

add_executable(SR3_Models main.cpp Render.cpp Render.h Obj.cpp Obj.h)