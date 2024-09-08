cmake_minimum_required(VERSION 3.29)
project(ChessAI)

set(CMAKE_CXX_STANDARD 17)

add_executable(ChessAI main.cpp
        Board.cpp
        Board.hpp
        types.hpp
        NegaMax.cpp
        MoveGen.cpp)