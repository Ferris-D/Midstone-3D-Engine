#include "Level.h"
#include "raylib.h"

Level::Level()
{
    lvlNumber = 0;
    objectCount = 0;
}

Level::~Level()
{
}

void Level::CreateLevel(Level lvl)
{
    for (int i = 0; i< lvl.objectCount; i++)
    {

    }
}
