#pragma once

#include "Scene.h"
#include <SFML/Audio.hpp>




//class MainMenuScene;

class SelectCapacityScene final : public Scene
{
public:
	SelectCapacityScene();
	SelectCapacityScene(int num_poupee, std::vector<Capacity> _capacitys);

private:
	void callbackPlayButton();

	sf::Music music;

};