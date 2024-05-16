#pragma once
#include <raylib.h>

void InitCamera(Camera3D *camera);
void UpdateFPSCamera(Camera3D *camera, Vector2 mouse_position_delta, float dt);