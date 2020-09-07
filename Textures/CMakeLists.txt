cmake_minimum_required(VERSION 3.17)
project(Textures)

set(CMAKE_CXX_STANDARD 20)

add_executable(Textures main.cpp Render.cpp Render.h Math.cpp Math.h Obj.cpp Obj.h Texture.cpp Texture.h)