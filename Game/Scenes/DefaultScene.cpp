#include "DefaultScene.h"

void DefaultScene::CreateWalls() {
    float sizeWall = 50.f;
    SpawnWall::CreateWallObject(this, WallName, 4 * sizeWall, 20 * sizeWall); 
    SpawnWall::CreateWallObject(this, WallName, 5 * sizeWall, 2 * sizeWall);
    SpawnWall::CreateWallObject(this, WallName, 6 * sizeWall, 3 * sizeWall);
}