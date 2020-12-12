#ifndef CAMERA_3D_H
#define CAMERA_3D_H
#include "raylib.h"

class Camera_3D
{
public:
	Camera3D cam;

	Camera_3D();
	~Camera_3D();
	void CameraSetup(Vector3 pos, Vector3 target, Vector3 up);
	void CurrentPos(Camera name);
};

#endif