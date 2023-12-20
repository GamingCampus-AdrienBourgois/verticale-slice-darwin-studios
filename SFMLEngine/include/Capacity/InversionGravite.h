#pragma once
#include "Capacity.h"
#include <Scene.h>

class InversionGravite : public Capacity
{
public:
	void GraviteInversion(GameObject* player, const float _delta_time, Scene* scene);
	void Update(const float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input) override;

private:
	bool inversion = false;
	int count = 0;
	sf::Clock inversionClock;
	int timeInversion = 10;
};
