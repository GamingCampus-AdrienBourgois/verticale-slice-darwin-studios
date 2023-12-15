#pragma once
#include "Capacity.h"

class Force : public Capacity
{
public:
	void Update(const float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input);
	void DeplaceObject(const float _delta_time, GameObject* player, GameObject* gameObjects);
};