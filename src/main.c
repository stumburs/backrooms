#include <raylib.h>
#include <raymath.h>
#include <stdio.h>
#include "player.h"

int main()
{
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(1280, 720, "Backrooms");
    SetTargetFPS(60);

    DisableCursor();

    Player player;
    InitPlayer(&player);

    // Image im_map = LoadImage("resources/textures/cubicmap.png"); // Load cubicmap image (RAM)
    // Texture2D cubicmap = LoadTextureFromImage(im_map);           // Convert image to texture to display (VRAM)
    // Mesh mesh = GenMeshCubicmap(im_map, (Vector3){1.0f, 1.0f, 1.0f});
    // Model model = LoadModelFromMesh(mesh);

    // Color *mapPixels = LoadImageColors(im_map);
    // UnloadImage(im_map); // Unload image from RAM

    Mesh cube_mesh = GenMeshCube(2, 2, 2);
    Model cube_model = LoadModelFromMesh(cube_mesh);
    Vector3 model_position = {0.0f, 1.0f, 4.0f};
    BoundingBox cube_aabb = GetModelBoundingBox(cube_model);
    cube_aabb.min = Vector3Add(cube_aabb.min, model_position);
    cube_aabb.max = Vector3Add(cube_aabb.max, model_position);

    while (!WindowShouldClose())
    {
        // Update
        {
            // Toggle fullscreen
            if (IsKeyPressed(KEY_F))
                ToggleBorderlessWindowed();

            float dt = GetFrameTime();
            Vector2 mouse_position_delta = GetMouseDelta();

            UpdatePlayer(&player, cube_aabb);
        }

        BeginDrawing();
        {
            ClearBackground(BLACK);

            // 3D
            BeginMode3D(player.camera);
            {
                DrawPlane(Vector3Zero(), (Vector2){100.0f, 100.0f}, WHITE);
                DrawGrid(100, 1);
                DrawModel(cube_model, model_position, 1.0f, GRAY);
                DrawBoundingBox(player.aabb, RED);
                DrawBoundingBox(cube_aabb, GREEN);
                // DrawModel(model, (Vector3){0.0f, -0.01f, 0.0f}, 1.0f, GRAY);
            }
            EndMode3D();
            DrawFPS(20, 20);
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}