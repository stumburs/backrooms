#include <raylib.h>
#include <raymath.h>
#include "fps_camera.h"
#include <stdio.h>

int main()
{
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(1280, 720, "Backrooms");
    SetTargetFPS(60);

    CameraSettings camera_settings = {
        .fov = 90,
        .mouse_sensitivity = 0.001f,
        .movement_speed = 10.0f,
    };

    Camera3D camera;
    InitCamera(&camera, camera_settings);
    DisableCursor();

    Image im_map = LoadImage("resources/textures/cubicmap.png"); // Load cubicmap image (RAM)
    Texture2D cubicmap = LoadTextureFromImage(im_map);           // Convert image to texture to display (VRAM)
    Mesh mesh = GenMeshCubicmap(im_map, (Vector3){1.0f, 1.0f, 1.0f});
    Model model = LoadModelFromMesh(mesh);

    Color *mapPixels = LoadImageColors(im_map);
    UnloadImage(im_map); // Unload image from RAM

    while (!WindowShouldClose())
    {
        // Update
        {
            float dt = GetFrameTime();
            Vector2 mouse_position_delta = GetMouseDelta();
            UpdateFPSCamera(&camera, camera_settings, mouse_position_delta, dt);
        }

        BeginDrawing();
        {
            ClearBackground(BLACK);

            // 3D
            BeginMode3D(camera);
            {
                DrawPlane(Vector3Zero(), (Vector2){100.0f, 100.0f}, WHITE);
                DrawGrid(100, 1);
                DrawModel(model, (Vector3){0.0f, -0.01f, 0.0f}, 1.0f, GRAY);
            }
            EndMode3D();
            DrawFPS(20, 20);
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}