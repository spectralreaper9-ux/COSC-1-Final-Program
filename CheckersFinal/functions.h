#pragma once

#include <iostream>

#ifndef CHECKERS_H  // Header guards prevent double-loading
#define CHECKERS_H

// Sets values to define piece types
enum PieceType { Empty = 0, Red, Black, RedKing, BlackKing };

// Defines Board for program
struct Board 
{
    int data[8][8];
};

// Signature
void initializeBoard(Board& b);

#endif

void initializeBoard(Board& b)
{
    for (int row = 0; row < 8; ++row)
    {
        for (int col = 0; col < 8; ++col)
        {
            b.data[row][col] = 0;

            if (col < 3 && (row + col) % 2 != 0)
            {
                b.data[row][col] = 2;
            }
            else if (col > 4 && (row + col) % 2 != 0)
            {
                b.data[row][col] = 1;
            }
        }
    }
}

void drawBoardStart(Board& b)
{
    // Draws board with for loop
    for (int row = 0; row < 8; ++row)
    {
        for (int col = 0; col < 8; ++col)
        {
            if ((row + col) % 2 == 0)
            {
                DrawRectangle((row * 100), (col * 100), 100, 100, GRAY);
            }
            else
            {
                DrawRectangle((row * 100), (col * 100), 100, 100, BLUE);
            }

            // Adds pieces to board using math and data
            if ((row + col) % 2 != 0 && b.data[row][col] == Black)
            {
                DrawCircle((row * 100 + 50), (col * 100 + 50), 45, BLACK);
            }
            else if ((row + col) % 2 != 0 && b.data[row][col] == Red)
            {
                DrawCircle((row * 100 + 50), (col * 100 + 50), 45, RED);
            }

        }
    }
}

