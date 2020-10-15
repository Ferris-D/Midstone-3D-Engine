#ifndef CAMERA_3D_H
#define CAMERA_3D_H
#include "raylib.h"

class Camera_3D
{
public:
	Camera_3D();
	Camera_3D(Camera name);
	~Camera_3D();
	void CameraSetup(Camera name, Vector3 pos, Vector3 target, Vector3 up);
};

#endif