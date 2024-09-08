//
// Created by berkay on 02.09.2024.
//

#include "types.hpp"
#include "Board.hpp"

int evaluate(Board board) {
    return 0;
}

int Minimax(Board& board, int depth, int alpha, int beta, bool isMaximizing) {
    if (depth == 0) return evaluate(board);

    int bestScore;
    if (isMaximizing) {
        bestScore = -INF;
        for (auto move : board.Moves()) {
            board.MakeMove(move);
            int currScore = Minimax(board, depth - 1, alpha, beta, !isMaximizing);
            board.UnmakeMove(move);

            bestScore = std::max(bestScore, currScore);
            alpha = std::max(alpha, bestScore);

            if (beta <= alpha) break;
        }

    }
    else {
        bestScore = INF;
        for (auto move : board.Moves()) {
            board.MakeMove(move);
            int currScore = Minimax(board, depth - 1, alpha, beta, !isMaximizing);
            board.UnmakeMove(move);

            bestScore = std::min(bestScore, currScore);
            beta = std::min(beta, bestScore);

            if (beta <= alpha) break;
        }
    }

    return bestScore;
}