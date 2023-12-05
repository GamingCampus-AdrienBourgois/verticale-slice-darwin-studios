#pragma once
#include "Scene.h"

class SpawnWall {
public:
    static void CreateWallObject(Scene* scene, const std::string& _name, const float _x, const float _y);
};