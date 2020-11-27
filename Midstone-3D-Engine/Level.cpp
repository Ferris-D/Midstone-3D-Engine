#include "Level.h"
#include "raylib.h"

Level::Level()
{
    lvlNumber = 0;
    objectCount = 20;
    for (int i = 0; i < sizeof(heights); i++)
    {
        heights[i] = { 0 };
        positions[i] = { 0 };
        colors[i] = { 0 };
    }
}

Level::Level(int lvlNum, int objNum)
{
    lvlNumber = lvlNum;
    objectCount = objNum;

    // Create arrays for height, position, and color
    //heights = {objNum};
    //positions = Vector3{objNum};
    //colors = Color{objNum};
}

Level::~Level()
{
}

void Level::CreateLevel(Level lvl)
{

    // Populate the arrays with random values
    for (int i = 0; i< lvl.objectCount; i++)
    {
        //
        lvl.heights[i] = (float)GetRandomValue(1, 12);
        //heights[i] = (float)GetRandomValue(1, 12);
        lvl.positions[i] = Vector3{ positions[i].x = (GetRandomValue(-15, 15), positions[i].y = heights[i] / 2, positions[i].z = (GetRandomValue(-15, 15))) };
        lvl.colors[i] = Color{ colors[i].r = GetRandomValue(20, 255), colors[i].g = GetRandomValue(10, 55), 30, 255 };
           // Color{ GetRandomValue(20, 255), GetRandomValue(10, 55), 30, 255 };
    }

    // Delete the arrays as to not cause a memory leak
    delete[] heights;
    delete[] positions;
    delete[] colors;
}
