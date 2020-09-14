cmake_minimum_required(VERSION 3.17)
project(Transformations)

set(CMAKE_CXX_STANDARD 20)

add_executable(Transformations main.cpp Math.cpp Math.h Obj.cpp Obj.h Texture.cpp Texture.h Render.cpp Render.h Shaders.cpp Shaders.h)