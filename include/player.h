#pragma once
#include <raylib.h>
#include "fps_camera.h"

typedef struct
{
    Mesh mesh;
    BoundingBox aabb;
    Vector3 position;
    Vector3 desired_movement;
    float speed;
    float collision_radius;
    Camera3D camera;
    bool hit_last_frame;
} Player;

void InitPlayer(Player *player);
void UpdatePlayer(Player *player, BoundingBox other);