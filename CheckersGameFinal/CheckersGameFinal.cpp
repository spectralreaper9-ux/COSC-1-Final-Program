/* CheckersGameFinal.cpp using a header and raylib GUI */

#include <cmath>
#include <iostream>
#include <vector>

#include "raylib.h"

int main()
{
    // Window size of game and name
    InitWindow(800, 800, "Raylib Checkers");

    // Array of ints that is used for logic calculations
    int checkers[8][8] = { 0 };

    /* 0 = Empty, 1 = Red, 2 = Black, 3 = Red King, 4 = Black King */

    // Only 1 and 2 are assigned here, 0 is default for every other space
    for (int y = 0; y < 3; y++)
    {
        for (int x = 0; x < 8; x++)
        {
            if ((x + y) % 2 != 0) checkers[y][x] = 1;
        }
    }

    for (int y = 5; y < 8; y++)
    {
        for (int x = 0; x < 8; x++)
        {
            if ((x + y) % 2 != 0) checkers[y][x] = 2;
        }
    }

    // -1 means nothing selected and stores selected piece
    int selectedX = -1, selectedY = -1; 
    bool pieceSelected = false;
    bool redTurn = true;

    SetTargetFPS(60);

    /* Main game loop */
    while (!WindowShouldClose())
    {
        int redPoints = 0;
        int blackPoints = 0;
        // Input / logic handling -> Checks left click
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            Vector2 mousePos = GetMousePosition();

            // Window size (800) / Grid size (8) = Cell size (100)
            // Grid mouse x and y are new click location (for moves)
            int gridMouseX = mousePos.x / 100;
            int gridMouseY = mousePos.y / 100;
            int absoluteX = abs(gridMouseX - selectedX);
            int absoluteY = abs(gridMouseY - selectedY);
            int midPieceX = (selectedX + gridMouseX) / 2;
            int midPieceY = (selectedY + gridMouseY) / 2;

            // Checks if piece is within bounds of grid
            if (gridMouseX >= 0 && gridMouseX < 8 && gridMouseY >= 0 && gridMouseY < 8)
            {
                /* SELECTION LOGIC */
                // Checks if piece not currently selected
                if (!pieceSelected)
                {
                    if (checkers[gridMouseY][gridMouseX] == 1 && redTurn == true
                        || checkers[gridMouseY][gridMouseX] == 3 && redTurn == true)
                    {
                        selectedX = gridMouseX;
                        selectedY = gridMouseY;
                        pieceSelected = true;
                    }
                    else if (checkers[gridMouseY][gridMouseX] == 2 && redTurn == false
                        || checkers[gridMouseY][gridMouseX] == 4 && redTurn == false)
                    {
                        selectedX = gridMouseX;
                        selectedY = gridMouseY;
                        pieceSelected = true;
                    }
                }
                else
                {
                    /* MOVE LOGIC */
                    // Absolute math needed because of negative values
                    if (checkers[gridMouseY][gridMouseX] == 0 && redTurn)
                    {
                        // Red move logic
                        if (checkers[selectedY][selectedX] == 1)
                        {
                            if (absoluteX == 1 && absoluteY == 1 && gridMouseY > selectedY)
                            {
                                checkers[gridMouseY][gridMouseX] = checkers[selectedY][selectedX];
                                checkers[selectedY][selectedX] = 0;
                                redTurn = !redTurn;
                            }
                            else if (absoluteX == 2 && absoluteY == 2 && gridMouseY > selectedY
                                && checkers[midPieceY][midPieceX] == 2)
                            {
                                checkers[gridMouseY][gridMouseX] = checkers[selectedY][selectedX];
                                checkers[selectedY][selectedX] = 0;
                                checkers[midPieceY][midPieceX] = 0;
                            }
                            else if (absoluteX == 2 && absoluteY == 2 && gridMouseY > selectedY
                                && checkers[midPieceY][midPieceX] == 4)
                            {
                                checkers[gridMouseY][gridMouseX] = checkers[selectedY][selectedX];
                                checkers[selectedY][selectedX] = 0;
                                checkers[midPieceY][midPieceX] = 0;
                            }
                        }
                        // Red "King" move logic
                        else if (checkers[selectedY][selectedX] == 3)
                        {
                            if (absoluteX == 1 && absoluteY == 1)
                            {
                                checkers[gridMouseY][gridMouseX] = checkers[selectedY][selectedX];
                                checkers[selectedY][selectedX] = 0;
                                redTurn = !redTurn;
                            }
                            else if (absoluteX == 2 && absoluteY == 2 && checkers[midPieceY][midPieceX] == 2)
                            {
                                checkers[gridMouseY][gridMouseX] = checkers[selectedY][selectedX];
                                checkers[selectedY][selectedX] = 0;
                                checkers[midPieceY][midPieceX] = 0;
                            }
                            else if (absoluteX == 2 && absoluteY == 2 && checkers[midPieceY][midPieceX] == 4)
                            {
                                checkers[gridMouseY][gridMouseX] = checkers[selectedY][selectedX];
                                checkers[selectedY][selectedX] = 0;
                                checkers[midPieceY][midPieceX] = 0;
                            }
                        }
                    }
                    else if (checkers[gridMouseY][gridMouseX] == 0 && !redTurn)
                    {
                        // Black move logic
                        if (checkers[selectedY][selectedX] == 2)
                        {
                            if (absoluteX == 1 && absoluteY == 1 && gridMouseY < selectedY)
                            {
                                checkers[gridMouseY][gridMouseX] = checkers[selectedY][selectedX];
                                checkers[selectedY][selectedX] = 0;
                                redTurn = !redTurn;
                            }
                            else if (absoluteX == 2 && absoluteY == 2 && gridMouseY < selectedY
                                && checkers[midPieceY][midPieceX] == 1)
                            {
                                checkers[gridMouseY][gridMouseX] = checkers[selectedY][selectedX];
                                checkers[selectedY][selectedX] = 0;
                                checkers[midPieceY][midPieceX] = 0;
                            }
                            else if (absoluteX == 2 && absoluteY == 2 && gridMouseY < selectedY
                                && checkers[midPieceY][midPieceX] == 3)
                            {
                                checkers[gridMouseY][gridMouseX] = checkers[selectedY][selectedX];
                                checkers[selectedY][selectedX] = 0;
                                checkers[midPieceY][midPieceX] = 0;
                            }
                        }
                        // Black "King" move logic
                        else if (checkers[selectedY][selectedX] == 4)
                        {
                            if (absoluteX == 1 && absoluteY == 1)
                            {
                                checkers[gridMouseY][gridMouseX] = checkers[selectedY][selectedX];
                                checkers[selectedY][selectedX] = 0;
                                redTurn = !redTurn;
                            }
                            else if (absoluteX == 2 && absoluteY == 2 && checkers[midPieceY][midPieceX] == 1)
                            {
                                checkers[gridMouseY][gridMouseX] = checkers[selectedY][selectedX];
                                checkers[selectedY][selectedX] = 0;
                                checkers[midPieceY][midPieceX] = 0;
                            }
                            else if (absoluteX == 2 && absoluteY == 2 && checkers[midPieceY][midPieceX] == 3)
                            {
                                checkers[gridMouseY][gridMouseX] = checkers[selectedY][selectedX];
                                checkers[selectedY][selectedX] = 0;
                                checkers[midPieceY][midPieceX] = 0;
                            }
                        }
                    }

                    pieceSelected = false;
                }
            }
        }
        // End of logic

        /* DRAWING SECTION */
        BeginDrawing();
        ClearBackground(WHITE);

        for (int y = 0; y < 8; y++)
        {
            for (int x = 0; x < 8; x++)
            {
                // cellColor defines color and DrawRectangle draws grid
                // First color is "light", second is "dark"
                Color cellColor = ((x + y) % 2 == 0) ? PURPLE : DARKPURPLE;
                DrawRectangle(x * 100, y * 100, 100, 100, cellColor);

                // Highlighted selection graphics logic
                if (pieceSelected && x == selectedX && y == selectedY)
                {
                    DrawRectangle(x * 100, y * 100, 100, 100, YELLOW);
                }

                // Logic to make "King" pieces
                if (checkers[y][x] == 1 && y == 7)
                {
                    checkers[y][x] = 3;
                }
                else if (checkers[y][x] == 2 && y == 0)
                {
                    checkers[y][x] = 4;
                }

                if (checkers[y][x] == 1)
                {
                    DrawCircle(x * 100 + 50, y * 100 + 50, 40, RED);
                    redPoints++;
                }
                else if (checkers[y][x] == 2)
                {
                    DrawCircle(x * 100 + 50, y * 100 + 50, 40, BLACK);
                    blackPoints++;
                }
                else if (checkers[y][x] == 3)
                {
                    DrawCircle(x * 100 + 50, y * 100 + 50, 40, RED);
                    DrawCircle(x * 100 + 50, y * 100 + 50, 20, MAROON);
                    redPoints = redPoints + 2;
                }
                else if (checkers[y][x] == 4)
                {
                    DrawCircle(x * 100 + 50, y * 100 + 50, 40, BLACK);
                    DrawCircle(x * 100 + 50, y * 100 + 50, 20, GRAY);
                    blackPoints = blackPoints + 2;
                }
            }
        }
        EndDrawing();

        if (redPoints == 0)
        {
            BeginDrawing();
            DrawRectangle(0, 0, 800, 800, RAYWHITE);
            DrawText("RED   WINS!", 75, 200, 100, RED);
            EndDrawing();
            WaitTime(7.5);
            CloseWindow();
        }

        if (blackPoints == 0)
        {
            BeginDrawing();
            DrawRectangle(0, 0, 800, 800, RAYWHITE);
            DrawText("BLACK WINS!", 75, 200, 100, BLACK);
            EndDrawing();
            WaitTime(7.5);
            CloseWindow();
        }
    }
    // End of while loop

    return 0;
}