#include "fps_camera.h"

void InitCamera(Camera3D *camera)
{
    camera->position = (Vector3){0.0f, 2.0f, 0.0f};
    camera->target = (Vector3){1.0f, 2.0f, 0.0f};
    camera->projection = CAMERA_PERSPECTIVE;
    camera->up = (Vector3){0.0f, 1.0f, 0.0f};
    camera->fovy = 90.0f;
}
