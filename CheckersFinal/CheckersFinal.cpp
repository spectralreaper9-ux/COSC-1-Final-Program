// CheckersFinal.cpp
//Using raylib to display and add gui to game

#include <iostream>

#include "raylib.h"
#include "functions.h"

//global
enum PieceType { Empty = 0, Red, Black, RedKing, BlackKing };

struct Board
{
    int data[8][8]; // 0 for empty, 1 for Red, 2 for Black, etc.
};

int main()
{
    int width{ 800 }, height{ 800 };
    InitWindow(width, height, "Checkers");
    SetTargetFPS(60);

    Board checkers;

    initializeBoard(checkers);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        //Draws board (add pieces next)
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
            }
        }
        

        EndDrawing();
    };

    
}
