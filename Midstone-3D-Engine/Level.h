#ifndef LEVEL_H
#define LEVEL_H
#include "raylib.h"

class Level
{
public:
	Level();
	Level(int lvlNum,int objNum);
	~Level();

	// The levels number
	int lvlNumber;
	// Amount of objects in the level
	int objectCount;

	// Arrays for level generation
	float heights{};
	Vector3 positions{};
	Color colors{};

	void CreateLevel(Level lvl);
};

#endif