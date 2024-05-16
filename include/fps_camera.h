#pragma once
#include <raylib.h>

typedef struct
{
    Camera3D camera;
    float mouse_sensitivity;
    float movement_speed;
} FPSCamera;

void InitCamera(FPSCamera *camera, float mouse_sensitivity, float movement_speed);
void UpdateFPSCamera(FPSCamera *camera, Vector2 mouse_position_delta, float dt);