#pragma once

#include <SFML/Graphics.hpp>

#include "ARendererComponent.h"

class TextRenderer : public ARendererComponent
{
public:
	TextRenderer();
	~TextRenderer() override;

	void SetColor(const sf::Color& _color) { color = _color; }
	void SetString(std::string _string) { string = _string; }
	void SetCaracterSize(int _caractere_size) { caractere_size = _caractere_size; }

	sf::Text* GetText() { return text; }

	void Render(sf::RenderWindow* _window) override;

private:
	sf::Color color = sf::Color::White;
	int caractere_size = 20;

	sf::Text* text = nullptr;
	std::string string = "";
};