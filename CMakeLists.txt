cmake_minimum_required(VERSION 3.26)
project(P1)

set(CMAKE_CXX_STANDARD 17)

add_executable(P1 chess.cpp
        pieces.cpp
        pieces.h
        Rook.cpp
        Rook.h
        Pawn.cpp
        Pawn.h
        King.cpp
        King.h)
