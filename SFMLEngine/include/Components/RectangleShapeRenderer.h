#pragma once

#include <SFML/Graphics.hpp>

#include "ARendererComponent.h"

class RectangleShapeRenderer : public ARendererComponent
{
public:
	RectangleShapeRenderer();
	~RectangleShapeRenderer() override;

	void SetColor(const sf::Color& _color) { color = _color; }
	void SetDefaultColor(const sf::Color& _default_color) { defaultColor = _default_color; }
	void SetOutlineColor(const sf::Color& _outline_color) { outlineColor = _outline_color; }
	void SetHoverColor(const sf::Color& _hover_color) { HoverColor = _hover_color; }
	void SetClickColor(const sf::Color& _click_color) { ClickColor = _click_color; }

	sf::Color GetColor() { return color; }
	sf::Color GetDefaultColor() { return defaultColor; }
	sf::Color GetOutlineColor() { return outlineColor; }
	sf::Color GetHoverColor() { return HoverColor; }
	sf::Color GetClickColor() { return ClickColor; }

	sf::RectangleShape* GetShape() { return shape; }

	void Render(sf::RenderWindow* _window) override;



private:
	sf::Color color = sf::Color::White;
	sf::Color defaultColor = sf::Color::White;
	sf::Color outlineColor = sf::Color::Black;
	sf::Color HoverColor = sf::Color::Red;
	sf::Color ClickColor = sf::Color::Black;

	sf::RectangleShape* shape = nullptr;
};
