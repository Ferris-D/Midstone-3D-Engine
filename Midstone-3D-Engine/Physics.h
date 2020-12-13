#ifndef PHYSICS_H
#define PHYSICS_H
#include "raylib.h"

class Physics
{
public:
	Vector3 position;
	Vector3 forward;
	Vector3 acceleration;
	Vector3 velocity;
	float mass;
	float totalTime;

	Physics();
	~Physics();
	void characterSetup(Vector3 posS, Vector3 forwardS, float massS);
	void ApplyForce(Vector3 force);
	void gravity(float deltaTime);
	void CurrentPos(Physics name);
};

#endif