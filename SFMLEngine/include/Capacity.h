#pragma once
#include <string>
#include <vector>
#include "GameObject.h"


class Capacity
{
public:
	Capacity() = default;

	std::string GetName() { return name; }
	std::string GetDescription() { return description; }

	void SetName(std::string new_name);
	void SetDescription(std::string new_description);

	GameObject* GetOwner() const { return owner; }
	void SetOwner(GameObject* _owner) { owner = _owner; }

	virtual void Update(const float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input){}

private:
	std::string name;
	std::string description;
	GameObject* owner = nullptr;
};

