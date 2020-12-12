#include "Level.h"
#include "raylib.h"

Level::Level()
{
    lvlNumber = 0;
    objectCount = 20;
}

Level::Level(int lvlNum, int objNum)
{
    lvlNumber = lvlNum;
    objectCount = objNum;

    // Create arrays for height, position, and color
    float* newheights = new float[objNum]{ 0 };
    heights = newheights;
    Vector3* newpositions = new Vector3[objNum]{ 0 };
    positions = newpositions;
    Color* newcolors = new Color[objNum]{ 0 };
    colors = newcolors;

    // Delete the temporary arrays
    delete[] newheights;
    delete[] newpositions;
    delete[] newcolors;
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
        lvl.positions[i] = Vector3{
            (positions[i].x = (GetRandomValue(-15, 15))),
            (positions[i].y = heights[i] / 2),
            (positions[i].z = (GetRandomValue(-15, 15)))};
        lvl.colors[i] = Color{ colors[i].r = GetRandomValue(20, 255), colors[i].g = GetRandomValue(10, 55), 30, 255 };
    }

}
