#pragma once
#include "Maths/Vector2.h"
#include "Component.h"

class Checkpoint : public Component {
public:
	void setPosition(Maths::Vector2f new_position) { position = new_position; }
	Maths::Vector2f GetPosition() { return position; }

	void SetName(std::string _name) { name = _name; }
	std::string GetName() { return name; }

private:
	Maths::Vector2f position; 
	std::string name;
};