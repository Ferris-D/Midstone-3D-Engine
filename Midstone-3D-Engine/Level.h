#ifndef LEVEL_H
#define LEVEL_H
#include "raylib.h"

class Level
{
public:
	Level();
	~Level();

	// The levels number
	int lvlNumber;
	// Amount of objects in the level
	int objectCount;

	void CreateLevel(Level lvl);
};

#endif