#include "Physics.h"
#include <iostream>

Physics::Physics()
{
	position = { 0,0,0 };
	forward = { 0,0,0 };
	acceleration = { 0,0,0 };
	velocity = { 0,0,0 };
	mass = 0.0f;
	totalTime = 0.0f;
}

Physics::~Physics()
{
	
}

void Physics::characterSetup(Vector3 posS, Vector3 forwardS, float massS)
{
	position = posS;
	forward = forwardS;
	mass = massS;
	acceleration = { 0,0,0 };
	velocity = { 0,0,0 };
	totalTime = 0.0f;
}
// calculates acceleration from force applied
void Physics::ApplyForce(Vector3 force)
{
	acceleration.x = force.x / mass;
	acceleration.y = force.y / mass;
	acceleration.z = force.z / mass;
}
// Handles the actual updating of physics per deltatime
void Physics::gravity(float deltaTime)
{
	totalTime += deltaTime;

	position.y += velocity.y * deltaTime + 0.5f * acceleration.y * deltaTime * deltaTime;
	velocity.y += acceleration.y * deltaTime;
}

void Physics::CurrentPos(Physics name)
{
	// Prints character current position to console
	std::cout << "Character pos-> x: " << name.position.x << " y: " << name.position.y << " z: " << name.position.z << std::endl;
}