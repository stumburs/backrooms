#include "player.h"
#include <raymath.h>
#include <rcamera.h>
#include <stdio.h>

void InitPlayer(Player *player)
{
    player->desired_movement = Vector3Zero();
    player->speed = 30.0f;
    player->position = (Vector3){0.0f, 2.0f, 0.0f};
    player->collision_radius = 1.5f;

    player->mesh = GenMeshCube(1, 2, 1);
    player->aabb = GetMeshBoundingBox(player->mesh);
    player->aabb.min = Vector3Add(player->aabb.min, player->position);
    player->aabb.max = Vector3Add(player->aabb.max, player->position);
    player->aabb.min.y -= 1;
    player->aabb.max.y -= 1;

    // Init camera
    CameraSettings camera_settings = {
        .fov = 90,
        .mouse_sensitivity = 0.001f,
        .movement_speed = 10.0f,
    };
    InitCamera(&player->camera, camera_settings);
    player->camera.position = player->position;
}

void UpdatePlayer(Player *player, BoundingBox other)
{
    player->aabb = (BoundingBox){
        .min = (Vector3){player->position.x - 0.5f, player->position.y - 2.0f, player->position.z - 0.5f},
        .max = (Vector3){player->position.x + 0.5f, player->position.y, player->position.z + 0.5f},
    };
    if (CheckCollisionBoxes(player->aabb, other))
    {
        printf("COLLIDE!\n");
    }
    CameraSettings camera_settings = {
        .fov = 90,
        .mouse_sensitivity = 0.1f,
        .movement_speed = 10.0f,
    };

    Vector2 mouse_delta = GetMouseDelta();
    Vector3 camera_rotation = {mouse_delta.x * camera_settings.mouse_sensitivity, mouse_delta.y * camera_settings.mouse_sensitivity, 0.0f};

    Vector3 desired_movement = Vector3Zero();
    if (IsKeyDown(KEY_W))
        desired_movement.x += 1;
    if (IsKeyDown(KEY_S))
        desired_movement.x -= 1;
    if (IsKeyDown(KEY_A))
        desired_movement.y -= 1;
    if (IsKeyDown(KEY_D))
        desired_movement.y += 1;
    UpdateCameraPro(&player->camera, Vector3Scale(desired_movement, 10.0f * GetFrameTime()), camera_rotation, 0.0f);
    player->position = player->camera.position;
}
