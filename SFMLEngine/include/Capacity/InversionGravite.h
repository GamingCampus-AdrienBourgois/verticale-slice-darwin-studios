#pragma once
#include "Capacity.h"

class InversionGravite : public Capacity
{
public:
	void GraviteInversion();
	void Update(const float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input);

private:
	bool inversion = false;
};
