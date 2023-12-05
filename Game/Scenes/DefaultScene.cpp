#include "DefaultScene.h"

void DefaultScene::CreateWalls() {
    float sizeWall = 50.f;
    SpawnWall::CreateWallObject(this, "Wall1", 4 * sizeWall, 1 * sizeWall); 
    SpawnWall::CreateWallObject(this, "Wall2", 5 * sizeWall, 2 * sizeWall);
    SpawnWall::CreateWallObject(this, "Wall3", 6 * sizeWall, 3 * sizeWall);
}