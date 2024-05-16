#include "fps_camera.h"
#include <rcamera.h>

void InitCamera(FPSCamera *camera, float mouse_sensitivity, float movement_speed)
{
    camera->camera.position = (Vector3){0.0f, 2.0f, 0.0f};
    camera->camera.target = (Vector3){1.0f, 2.0f, 0.0f};
    camera->camera.projection = CAMERA_PERSPECTIVE;
    camera->camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    camera->camera.fovy = 90.0f;
    camera->mouse_sensitivity = mouse_sensitivity;
    camera->movement_speed = movement_speed;
}

void UpdateFPSCamera(FPSCamera *camera, Vector2 mouse_position_delta, float dt)
{
    CameraYaw(&camera->camera, -mouse_position_delta.x * camera->mouse_sensitivity, false);
    CameraPitch(&camera->camera, -mouse_position_delta.y * camera->mouse_sensitivity, true, false, false);

    // Keyboard support
    if (IsKeyDown(KEY_W))
        CameraMoveForward(&camera->camera, camera->movement_speed * dt, true);
    if (IsKeyDown(KEY_A))
        CameraMoveRight(&camera->camera, -camera->movement_speed * dt, true);
    if (IsKeyDown(KEY_S))
        CameraMoveForward(&camera->camera, -camera->movement_speed * dt, true);
    if (IsKeyDown(KEY_D))
        CameraMoveRight(&camera->camera, camera->movement_speed * dt, true);
}
