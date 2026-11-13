cmake_minimum_required(VERSION 4.4)
project(chessEngine)

set(CMAKE_CXX_STANDARD 17)

add_executable(chessEngine main.cpp
        board.h
        board.cpp
        moveVali.h
        moveVali.cpp)
