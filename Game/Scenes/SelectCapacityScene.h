#pragma once

#include "Scene.h"




//class MainMenuScene;

class SelectCapacityScene final : public Scene
{
public:
	SelectCapacityScene();
	SelectCapacityScene(int num_poupee, std::vector<Capacity> _capacitys);
};