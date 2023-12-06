#pragma once
#include "GameObject.h"

class Button : public Component
{
public:
	Button() = default;
	~Button() = default;

	void SetName(std::string new_name) { name = new_name; }
	void SetText(std::string new_text) { text = new_text; }

	std::string GetName() { return name; }
	std::string GetText() { return text; }

	void Execute();
	void Update(const float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input);

private:
	std::string name = "Button";
	std::string text = "";
};
