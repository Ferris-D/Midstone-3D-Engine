#include "Physics.h"

Physics::Physics()
{
	position = Vector3{ 0.0f, 0.0f, 0.0f };
	forward = Vector3{ 0.0f, 0.0f, 0.0f };
	mass = 0.0f;
}

Physics::~Physics()
{

}

void Physics::characterSetup(Vector3 pos, Vector3 forward, float mass)
{

}

void Physics::gravity(float mass)
{

}
