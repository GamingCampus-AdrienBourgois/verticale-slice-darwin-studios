#pragma once
#include "Capacity.h"

class Invincibilite : public Capacity
{
public:
	void Immortel(const float _delta_time, GameObject* player);
	void Update(const float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input);
};

