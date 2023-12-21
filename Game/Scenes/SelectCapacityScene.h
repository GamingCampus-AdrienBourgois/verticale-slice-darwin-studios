#pragma once

#include "Scene.h"
#include <SFML/Audio.hpp>

class MainMenuScene;

class SelectCapacityScene final : public Scene
{
public:
	SelectCapacityScene();
	sf::Music music;
};