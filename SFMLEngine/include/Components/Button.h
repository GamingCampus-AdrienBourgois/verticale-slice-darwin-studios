#pragma once
#include "GameObject.h"
#include "Scene.h"


class Button : public Component
{
public:
	Button() = default;
	~Button() = default;

	void SetText(std::string new_text) { text = new_text; }
	void SetObject(Capacity* _object) { object = _object; }

	std::string GetText() { return text; }
	Capacity* GetObject() { return object; }

	void Execute();
	void Update(const float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input);

	bool is_clicked = false;

private:
	std::string text = "";

	Capacity* object = nullptr;
};
