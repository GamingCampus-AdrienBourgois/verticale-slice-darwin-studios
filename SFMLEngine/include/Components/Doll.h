#pragma once
#include "GameObject.h"

class DollOff : public Component
{
public:
	Maths::Vector2f getSize() { return size; }
	void setSize(Maths::Vector2f _size) { size = _size; }

	sf::Color getColor() { return color; }
	void setColor(sf::Color _color) { color = _color; }

	Maths::Vector2f getPosition() { return size; }
	void setPosition(Maths::Vector2f _position) { position = _position; }

private:
	Maths::Vector2f size = Maths::Vector2f(200, 200);
	sf::Color color = sf::Color::Transparent;
	Maths::Vector2f position = Maths::Vector2f(0, 0);
};

