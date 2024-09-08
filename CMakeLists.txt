cmake_minimum_required(VERSION 3.29)
project(ChessAI)

set(CMAKE_CXX_STANDARD 17)

add_executable(ChessAI src/main.cpp
        src/Board.cpp
        src/Board.hpp
        src/types.hpp
        src/NegaMax.cpp
        src/MoveGen.cpp)