cmake_minimum_required(VERSION 3.17)
project(Lab2_Shaders)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab2_Shaders main.cpp Math.cpp Obj.cpp Render.cpp Shaders.cpp Texture.cpp)