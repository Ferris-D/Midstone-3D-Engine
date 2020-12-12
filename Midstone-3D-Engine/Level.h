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
	float* heights = new float[1];
	Vector3* positions = new Vector3[1];
	Color* colors = new Color[1];

	Level();
	Level(int lvlNum, int objNum);
	~Level();
	void CreateLevel(Level lvl);
};

#endif