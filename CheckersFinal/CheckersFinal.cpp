// CheckersFinal.cpp
// Using raylib to display and add GUI to game

#include <iostream>
#include <vector2.hpp>

#include "raylib.h"
#include "functions.h"


int main()
{
    Board checkersGame;
    initializeBoard(checkersGame);

    int width{ 800 }, height{ 800 };
    InitWindow(width, height, "Checkers");
    SetTargetFPS(60);

    int gridX = GetMouseX() / 100;
    int gridY = GetMouseY() / 100;

    Vector2 mouseCursorPos = { 100.0f, 100.0f };

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        drawBoardStart(checkersGame);

        // Locates mouse location and stores in Vector2
        mouseCursorPos = GetMousePosition();

        // PROBABLY NEED TO RECONFIGURE HOW I DRAW THE CIRCLES TO MAKE THEM POSITION BASED
        // USE AI EXAMPLE TO FIGURE OUT HOW TO CHANGE IT

        // USE MOUSE POSITION PLUS BOOL TO FIGURE OUT WHICH TURN AND
        // IF A PIECE IS SELECTED, THEN ALLOW AN EMPTY SPACE TO BE SELECTED AND 
        // MOVE THE PIECE, USE gridX AND gridY TO DIVIDE AND CHOOSE WHERE CIRCLE DRAWN
        // TO REMOVE PIECE YOU MUST UPDATE THE BOARD DATA AND THAT WILL REMOVE OLD
        // NEED A LOOP TO CHECK AND UPDATE PIECE POSITIONSs
        // CLICK PIECE, FEED POS INTO BOARD, CHANGE BOARD DATA, DRAW NEW CIRCLE
        

        EndDrawing();
    };

    return 0;
}
