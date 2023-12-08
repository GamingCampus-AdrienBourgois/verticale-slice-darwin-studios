#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <unordered_map>
#include <SFML/Window/Event.hpp>

#include "Module.h"
#include "GameObject.h"

class WindowModule final : public Module
{
public:
	
	std::unordered_map<sf::Keyboard::Key, bool>* GetPressed() { return &pressed; }
	void ResetButton(GameObject* button, std::vector<std::string> _name);

	void Init() override;
	void Start() override;
	void Update() override;
	void PreRender() override;
	void Render() override;
	void PostRender() override;
	void Release() override;

	sf::RenderWindow* GetWindow() const { return window; }
	sf::Vector2u GetWindowSize() const { return window->getSize(); };

private:
	sf::RenderWindow* window = nullptr;
	std::unordered_map<sf::Keyboard::Key, bool> pressed;
};
