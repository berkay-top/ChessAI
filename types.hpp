//
// Created by berkay on 02.09.2024.
//

#ifndef TYPES_HPP
#define TYPES_HPP
#include <cstdint>
#include <utility>

constexpr int INF = 1024;

struct Move {
    uint64_t from, to;

    Move(const uint64_t f, const uint64_t t) : from(f), to(t) {}
};

enum struct Player {Computer = 1, Human = -1};
enum struct Color {White, Black};
enum struct PieceType {
    Pawn,
    Knight,
    Bishop,
    Rook,
    Queen,
    King,

    Empty
};
enum struct Piece {
    WPawn,
    WKnight,
    WBishop,
    WRook,
    WQueen,
    WKing,

    BPawn,
    BKnight,
    BBishop,
    BRook,
    BQueen,
    BKing,

    Empty
};

#endif //TYPES_HPP
