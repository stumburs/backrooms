#include <raylib.h>
#include <raymath.h>
#include "fps_camera.h"

int main()
{
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(1280, 720, "Backrooms");
    SetTargetFPS(60);

    Camera3D camera;
    InitCamera(&camera);
    DisableCursor();

    while (!WindowShouldClose())
    {
        // Update
        {
            UpdateCamera(&camera, CAMERA_FIRST_PERSON);
            // UpdateCameraPro(&camera, Vector3Zero(), Vector3Zero(), 1.0f);
        }

        BeginDrawing();
        {
            ClearBackground(BLACK);

            // 3D
            BeginMode3D(camera);
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