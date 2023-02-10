cmake_minimum_required(VERSION 3.21)
project(P5)

set(CMAKE_CXX_STANDARD 14)

add_executable(P5 main.cpp IPainter.h Canvas.cpp Canvas.h Cerc.cpp Cerc.h Rect.cpp Rect.h)
