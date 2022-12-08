cmake_minimum_required(VERSION 3.21)
project(WrapperEngine)

set(CMAKE_CXX_STANDARD 14)

add_executable(WrapperEngine main.cpp Wrapper.h Engine.cpp Engine.h)
