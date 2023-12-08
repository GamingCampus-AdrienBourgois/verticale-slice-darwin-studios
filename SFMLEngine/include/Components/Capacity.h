#pragma once
#include <string>
#include <vector>
#include "GameObject.h"

class Capacity : public Component
{
public:
	Capacity() = default;
	~Capacity() = default;
	std::string GetName() { return name; }
	std::string GetDescription() { return description; }
	float GetEffect() { return effect; }
	void SetName(std::string new_name);
	void SetDescription(std::string new_description);
	void SetEffect(float new_effect);

private:
	std::string name;
	std::string description;
	float effect;
};

