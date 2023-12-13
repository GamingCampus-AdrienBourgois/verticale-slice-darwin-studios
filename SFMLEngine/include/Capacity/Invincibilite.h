#pragma once
#include "Capacity.h"
#include <SFML/System/Clock.hpp>

class Invincibilite : public Capacity
{
public:
	void Immortel(GameObject* player);
	void Update(const float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input);

private:
	sf::Clock StartClockInvincibilite;
};

