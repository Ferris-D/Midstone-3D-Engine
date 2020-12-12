#ifndef PHYSICS_H
#define PHYSICS_H
#include "raylib.h"

class Physics
{
	Vector3 position;
	Vector3 forward;
	float mass;

	Physics();
	~Physics();
	void characterSetup(Vector3 pos, Vector3 forward, float mass);
	void gravity(float mass);
};

#endif