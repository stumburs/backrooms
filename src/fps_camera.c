#include "fps_camera.h"
#include <rcamera.h>

void InitCamera(Camera3D *camera, CameraSettings camera_settings)
{
    camera->position = (Vector3){0.0f, 2.0f, 0.0f};
    camera->target = (Vector3){1.0f, 2.0f, 0.0f};
    camera->projection = CAMERA_PERSPECTIVE;
    camera->up = (Vector3){0.0f, 1.0f, 0.0f};
    camera->fovy = camera_settings.fov;
}

void UpdateFPSCamera(Camera3D *camera, CameraSettings camera_settings, Vector2 mouse_position_delta, float dt)
{
    CameraYaw(camera, -mouse_position_delta.x * camera_settings.mouse_sensitivity, false);
    CameraPitch(camera, -mouse_position_delta.y * camera_settings.mouse_sensitivity, true, false, false);

    // Keyboard support
    if (IsKeyDown(KEY_W))
        CameraMoveForward(camera, camera_settings.movement_speed * dt, true);
    if (IsKeyDown(KEY_A))
        CameraMoveRight(camera, -camera_settings.movement_speed * dt, true);
    if (IsKeyDown(KEY_S))
        CameraMoveForward(camera, -camera_settings.movement_speed * dt, true);
    if (IsKeyDown(KEY_D))
        CameraMoveRight(camera, camera_settings.movement_speed * dt, true);
}
