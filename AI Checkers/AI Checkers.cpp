#include "raylib.h"
#include <vector>

const int SCREEN_SIZE = 800;
const int BOARD_SIZE = 8;
const int CELL_SIZE = SCREEN_SIZE / BOARD_SIZE;

int main() {
    InitWindow(SCREEN_SIZE, SCREEN_SIZE, "Raylib Checkers - Array Logic");

    // Initialize the board: 1 = Red, 2 = Black, 0 = Empty
    int board[BOARD_SIZE][BOARD_SIZE] = { 0 };

    // Simple setup: Red on top, Black on bottom
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < BOARD_SIZE; x++) {
            if ((x + y) % 2 != 0) board[y][x] = 1;
        }
    }
    for (int y = 5; y < BOARD_SIZE; y++) {
        for (int x = 0; x < BOARD_SIZE; x++) {
            if ((x + y) % 2 != 0) board[y][x] = 2;
        }
    }

    int selectedX = -1, selectedY = -1; // -1 means nothing selected
    bool pieceSelected = false;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        // --- Input Handling ---
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            Vector2 mousePos = GetMousePosition();

            // Convert pixel coordinates to array indices
            int gridX = mousePos.x / CELL_SIZE;
            int gridY = mousePos.y / CELL_SIZE;

            if (gridX >= 0 && gridX < BOARD_SIZE && gridY >= 0 && gridY < BOARD_SIZE) {
                if (!pieceSelected) {
                    // Selecting a piece
                    if (board[gridY][gridX] != 0) {
                        selectedX = gridX;
                        selectedY = gridY;
                        pieceSelected = true;
                    }
                }
                else {
                    // Moving the piece
                    // Logic: Move if destination is empty and it's a dark square
                    if (board[gridY][gridX] == 0 && (gridX + gridY) % 2 != 0) {
                        board[gridY][gridX] = board[selectedY][selectedX];
                        board[selectedY][selectedX] = 0;
                    }
                    pieceSelected = false;
                }
            }
        }

        // --- Drawing ---
        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (int y = 0; y < BOARD_SIZE; y++) {
            for (int x = 0; x < BOARD_SIZE; x++) {
                // Draw Grid
                Color cellColor = ((x + y) % 2 == 0) ? BEIGE : BROWN;
                DrawRectangle(x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE, cellColor);

                // Highlight Selection
                if (pieceSelected && x == selectedX && y == selectedY) {
                    DrawRectangle(x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE, YELLOW);
                }

                // Draw Pieces
                if (board[y][x] == 1) {
                    DrawCircle(x * CELL_SIZE + CELL_SIZE / 2, y * CELL_SIZE + CELL_SIZE / 2, CELL_SIZE * 0.4f, RED);
                }
                else if (board[y][x] == 2) {
                    DrawCircle(x * CELL_SIZE + CELL_SIZE / 2, y * CELL_SIZE + CELL_SIZE / 2, CELL_SIZE * 0.4f, BLACK);
                }
            }
        }

        DrawText("Click piece to select, then click empty square to move", 10, 10, 20, WHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}