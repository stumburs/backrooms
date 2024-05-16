#include <raylib.h>
#include <raymath.h>
#include "fps_camera.h"
#include <stdio.h>

int main()
{
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(1280, 720, "Backrooms");
    SetTargetFPS(60);

    FPSCamera camera;
    InitCamera(&camera, 0.001f, 10.0f);
    DisableCursor();

    while (!WindowShouldClose())
    {
        // Update
        {
            float dt = GetFrameTime();
            Vector2 mouse_position_delta = GetMouseDelta();
            UpdateFPSCamera(&camera, mouse_position_delta, dt);
        }

        BeginDrawing();
        {
            ClearBackground(BLACK);

            // 3D
            BeginMode3D(camera.camera);
            {
                DrawPlane(Vector3Zero(), (Vector2){100.0f, 100.0f}, WHITE);
                DrawGrid(100, 1);
            }
            EndMode3D();
            DrawFPS(20, 20);
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}