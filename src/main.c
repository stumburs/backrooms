#include <raylib.h>
#include "fps_camera.h"

int main()
{
    InitWindow(1280, 720, "Backrooms");
    SetTargetFPS(60);

    Camera3D camera;
    InitCamera(&camera);

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