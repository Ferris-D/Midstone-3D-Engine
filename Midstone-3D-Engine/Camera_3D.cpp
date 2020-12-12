#include "Camera_3D.h"
#include "raylib.h"
#include <iostream>

Camera_3D::Camera_3D()
{
    CameraSetup(
        { 4.0f, 2.0f, 4.0f },
        { 0.0f, 0.0f, 0.0f },
        { 0.0f, 0.0f, 0.0f }
        );
}

void Camera_3D::CameraSetup(Vector3 pos, Vector3 target, Vector3 up)
{ 
    cam.position = pos;
    cam.target = target;
    cam.up = up;
    cam.fovy = 60.0f;
    cam.type = CAMERA_PERSPECTIVE;
    SetCameraMode(cam, CAMERA_FIRST_PERSON); // Set a first person camera mode

    std::cout << "Camera Setup Complete." << std::endl;
}

void Camera_3D::CurrentPos(Camera name)
{
    // Prints cameras current position to console
    std::cout << "Camera pos-> x: " << name.position.x << " y: " << name.position.y << " z: " << name.position.z << std::endl;
}

Camera_3D::~Camera_3D() {}