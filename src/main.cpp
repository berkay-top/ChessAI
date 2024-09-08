#include <iostream>

#include "Board.hpp"

int main()
{
    Board myBoard = Board();

    myBoard.PrintBoard();
    myBoard.MakeMove(Move((1 << 8), (1 << 24)));
    myBoard.PrintBoard();
}
