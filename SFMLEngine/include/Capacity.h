#pragma once
#include <string>
#include <vector>
#include "GameObject.h"

class GameObject;

class Capacity
{
public:
	Capacity() = default;
	virtual ~Capacity() = default;
	std::string GetName() { return name; }
	std::string GetDescription() { return description; }
	float GetEffect() { return effect; }
	void SetName(std::string new_name);
	void SetDescription(std::string new_description);
	void SetEffect(float new_effect);
	explicit Capacity(GameObject* _owner);
	GameObject* GetOwner() const { return owner; }
	void SetOwner(GameObject* _owner) { owner = _owner; }

private:
	std::string name;
	std::string description;
	float effect;
	GameObject* owner = nullptr;
};

