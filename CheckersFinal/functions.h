#pragma once

#include <iostream>

void initializeBoard(struct Board &myBoard)
{
    
    for (int row = 0; row < 8; ++row)
    {
        for (int col = 0; col < 8; ++col)
        {
            myBoard.data[row][col] = Empty;

            if ((row + col) % 2 == 0)
            {
                if (row < 3)
                {
                    myBoard.data[row][col] = Black;
                }
                else if (row > 4)
                {
                    myBoard.data[row][col] = Red;
                }
            }
        }
    }

}