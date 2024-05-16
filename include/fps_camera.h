#pragma once
#include <raylib.h>

typedef struct
{
    float mouse_sensitivity;
    float movement_speed;
    float fov;
} CameraSettings;

void InitCamera(Camera3D *camera, CameraSettings camera_settings);
void UpdateFPSCamera(Camera3D *camera, CameraSettings camera_settings, Vector2 mouse_position_delta, float dt);