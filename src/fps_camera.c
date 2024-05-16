#include "fps_camera.h"
#include <rcamera.h>

void InitCamera(Camera3D *camera)
{
    camera->position = (Vector3){0.0f, 2.0f, 0.0f};
    camera->target = (Vector3){1.0f, 2.0f, 0.0f};
    camera->projection = CAMERA_PERSPECTIVE;
    camera->up = (Vector3){0.0f, 1.0f, 0.0f};
    camera->fovy = 90.0f;
}

void UpdateFPSCamera(Camera3D *camera, Vector2 mouse_position_delta, float dt)
{
    CameraYaw(camera, -mouse_position_delta.x * 0.001f, false);
    CameraPitch(camera, -mouse_position_delta.y * 0.001f, true, false, false);

    // Keyboard support
    if (IsKeyDown(KEY_W))
        CameraMoveForward(camera, 10.0f * dt, true);
    if (IsKeyDown(KEY_A))
        CameraMoveRight(camera, -10.0f * dt, true);
    if (IsKeyDown(KEY_S))
        CameraMoveForward(camera, -10.0f * dt, true);
    if (IsKeyDown(KEY_D))
        CameraMoveRight(camera, 10.0f * dt, true);
}
