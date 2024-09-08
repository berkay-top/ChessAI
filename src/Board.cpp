//
// Created by berkay on 02.09.2024.
//

#include "Board.hpp"

#include <iostream>

void Board::PrintBoard() const {
    std::array<PieceType, 64> res;
    res.fill(PieceType::Empty);
    for (int i = 0; i < PIECE_TYPE_COUNT; i++)
        for (int j = 0; j < 64; j++)
            if (board[i] & (1ll << j))
                res[j] = static_cast<PieceType>(i % 6);

    for (int i = 7; i >=0; i--) {
        for (int j = 0; j < 8; j++)
            switch (res[i * 8 + j]) {
                case PieceType::Pawn:
                    std::cout << " ";
                break;
                case PieceType::Knight:
                    std::cout << " ";
                break;
                case PieceType::Bishop:
                    std::cout << " ";
                break;
                case PieceType::Rook:
                    std::cout << " ";
                break;
                case PieceType::Queen:
                    std::cout << " ";
                break;
                case PieceType::King:
                    std::cout << " ";
                break;
                default:
                    std::cout << ". ";
            }
        std::cout << '\n';
    }

}
