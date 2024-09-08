//
// Created by berkay on 02.09.2024.
//

#ifndef BOARD_HPP
#define BOARD_HPP

#include <array>
#include <cstdint>
#include <vector>

#include "types.hpp"

constexpr int PIECE_TYPE_COUNT = 12;

class Board {
    std::array<uint64_t, PIECE_TYPE_COUNT> board;
    uint64_t WhitePieces, BlackPieces;

    inline uint64_t GenPawnMoves();
    inline uint64_t GenKnightMoves();
    inline uint64_t GenBishopMoves();
    inline uint64_t GenRookMoves();
    inline uint64_t GenQueenMoves();
    inline uint64_t GenKingMoves();

public:
    Board() {
        board[static_cast<int>(Piece::WPawn)] = 0x000000000000FF00;
        board[static_cast<int>(Piece::WKnight)] = 0x0000000000000042;
        board[static_cast<int>(Piece::WBishop)] = 0x0000000000000024;
        board[static_cast<int>(Piece::WRook)] = 0x0000000000000081;
        board[static_cast<int>(Piece::WQueen)] = 0x0000000000000008;
        board[static_cast<int>(Piece::WKing)] = 0x0000000000000010;

        board[static_cast<int>(Piece::BPawn)] = 0x00FF000000000000;
        board[static_cast<int>(Piece::BKnight)] = 0x4200000000000000;
        board[static_cast<int>(Piece::BBishop)] = 0x2400000000000000;
        board[static_cast<int>(Piece::BRook)] = 0x8100000000000000;
        board[static_cast<int>(Piece::BQueen)] = 0x0800000000000000;
        board[static_cast<int>(Piece::BKing)] = 0x1000000000000000;

        WhitePieces = (
            GetBitboard(Piece::WPawn) |
            GetBitboard(Piece::WKnight) |
            GetBitboard(Piece::WBishop) |
            GetBitboard(Piece::WRook) |
            GetBitboard(Piece::WQueen) |
            GetBitboard(Piece::WKing)
        );

        BlackPieces = (
            GetBitboard(Piece::BPawn) |
            GetBitboard(Piece::BKnight) |
            GetBitboard(Piece::BBishop) |
            GetBitboard(Piece::BRook) |
            GetBitboard(Piece::BQueen) |
            GetBitboard(Piece::BKing)
        );
    }

    void PrintBoard() const;

    [[nodiscard]] uint64_t GetBitboard(Piece piece) const {
        return board[static_cast<int>(piece)];
    }

    [[nodiscard]] uint64_t GetWhitePieces() const {
        return WhitePieces;
    }

    [[nodiscard]] uint64_t GetBlackPieces() const {
        return BlackPieces;
    }

    void MakeMove(const Move move) {
        for (int i = 0; i < PIECE_TYPE_COUNT; i++)
            if (board[i] & move.from)
                board[i] ^= move.from | move.to;
    }

    void UnmakeMove(const Move move) {
        for (int i = 0; i < PIECE_TYPE_COUNT; i++)
            if (board[i] & move.to)
                board[i] ^= move.from | move.to;
    }

    std::vector<Move> Moves() {
    }
};



#endif //BOARD_HPP
