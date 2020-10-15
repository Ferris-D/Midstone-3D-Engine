#include "Camera_3D.h"
#include "raylib.h"
#include <iostream>

Camera_3D::Camera_3D()
{

}

Camera_3D::Camera_3D(Camera name)
{
    CameraSetup(
        name,
        { 0.0f, 0.0f, 0.0f },
        { 0.0f, 0.0f, 0.0f },
        { 0.0f, 0.0f, 0.0f }
        );
}

void Camera_3D::CameraSetup(Camera name,Vector3 pos, Vector3 target, Vector3 up)
{
    name.position = pos;
    name.target = target;
    name.up = up;
    name.fovy = 60.0f;
    name.type = CAMERA_PERSPECTIVE;
    SetCameraMode(name, CAMERA_FIRST_PERSON);

    std::cout << "Camera Setup Complete." << std::endl;
}

Camera_3D::~Camera_3D() {}