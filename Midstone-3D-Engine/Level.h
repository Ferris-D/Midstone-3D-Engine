#ifndef LEVEL_H
#define LEVEL_H
#include "raylib.h"

class Level
{
public:
	// The levels number
	int lvlNumber;
	// Amount of objects in the level
	int objectCount;
	// Arrays for level generation
	float heights[50] = {};
	Vector3 positions[50] = {};
	Color colors[50] = {};

	Level();
	Level(int lvlNum, int objNum);
	~Level();
	void CreateLevel(Level lvl);
};

#endif