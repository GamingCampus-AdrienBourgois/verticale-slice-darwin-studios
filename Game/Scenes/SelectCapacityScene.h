#pragma once

#include "Scene.h"
#include <SFML/Audio.hpp>




//class MainMenuScene;

class SelectCapacityScene final : public Scene
{
public:
	SelectCapacityScene();

private:
	void callbackPlayButton();

	sf::Music music;

};