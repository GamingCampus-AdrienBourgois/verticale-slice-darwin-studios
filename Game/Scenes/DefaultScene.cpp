#include "DefaultScene.h"

void DefaultScene::CreateWalls() {
    float sizeWall = 50.f;
    SpawnWall::CreateWallObject(this, WallName, 4 * sizeWall, 1 * sizeWall); 
    SpawnWall::CreateWallObject(this, WallName, 5 * sizeWall, 2 * sizeWall);
    SpawnWall::CreateWallObject(this, WallName, 6 * sizeWall, 3 * sizeWall);
}

void DefaultScene::CreateSwitch() {
    float sizeSwitch = 50.f;
    Switch::CreateSwitchObject(this, SwitchName, 600, 1000);
}