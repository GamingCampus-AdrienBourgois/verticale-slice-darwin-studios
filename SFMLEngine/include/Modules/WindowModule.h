#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <unordered_map>
#include <SFML/Window/Event.hpp>

#include "Module.h"

class WindowModule final : public Module
{
public:
	sf::RenderWindow* GetWindow() const { return window; }
	std::unordered_map<sf::Keyboard::Key, bool>* GetPressed() { return &pressed; }

	void Init() override;
	void Start() override;
	void Update() override;
	void PreRender() override;
	void Render() override;
	void PostRender() override;
	void Release() override;

private:
	sf::RenderWindow* window = nullptr;
	std::unordered_map<sf::Keyboard::Key, bool> pressed;
};
