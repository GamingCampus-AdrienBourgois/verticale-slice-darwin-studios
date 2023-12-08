#pragma once

#include <SFML/Graphics.hpp>

#include "ARendererComponent.h"

class RectangleShapeRenderer : public ARendererComponent
{
public:
	RectangleShapeRenderer();
	~RectangleShapeRenderer() override;

	void SetColor(const sf::Color& _color) { color = _color; }
	sf::RectangleShape* GetShape() { return shape; }

	void Render(sf::RenderWindow* _window) override;

private:
	sf::Color color = sf::Color::White;

	sf::RectangleShape* shape = nullptr;
};
