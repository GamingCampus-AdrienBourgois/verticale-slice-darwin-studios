#pragma once

#include "Scene.h"




//class MainMenuScene;

class SelectCapacityScene final : public Scene
{
public:
	SelectCapacityScene();

private:
	void callbackPlayButton();
};