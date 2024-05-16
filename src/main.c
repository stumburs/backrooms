#include <raylib.h>

int main()
{
    InitWindow(1280, 720, "Backrooms");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // Update
        {
        }

        BeginDrawing();
        {
            ClearBackground(BLACK);
            DrawFPS(20, 20);
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}