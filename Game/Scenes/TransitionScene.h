#pragma once
#include "Scene.h"
#include "Engine.h"
#include "WindowModule.h"

class TransitionScene : public Scene {
private:
	std::vector<Capacity> capacities;

	void CallBack();
	

public:
	TransitionScene(std::vector<Capacity> params);
};