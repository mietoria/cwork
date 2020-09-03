cmake_minimum_required(VERSION 3.16)
project(c_work)

set(CMAKE_CXX_STANDARD 17)

add_executable(c_work
        main.cpp String.cpp String.h Identifier.cpp Identifier.h)