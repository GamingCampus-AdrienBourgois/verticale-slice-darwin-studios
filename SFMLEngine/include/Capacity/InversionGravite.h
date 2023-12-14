#pragma once
#include "Capacity.h"

class InversionGravite : public Capacity
{
public:
	void GraviteInversion(GameObject* player, const float _delta_time, std::vector<GameObject*>* gameObjects);
	void Update(const float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input);

private:
	bool inversion = false;
	bool active = false;
	int count = 0;
	int gravite = 0;
	int inversionGravite = 0;
	sf::Clock StartClockDurationInversion;
	int timeInversion = 10;
};
