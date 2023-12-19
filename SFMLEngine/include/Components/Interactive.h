#pragma once
#include "GameObject.h"
#include "Scene.h"

class Interactive : public Component
{
public:
	bool GetOn() { return is_activated; }
	bool GetCanBeActivated() { return can_be_activated; }

	void SetOn(bool value) { is_activated = value; }
	void SetCanBeActivated(bool _can_be_activated) { can_be_activated = _can_be_activated; }

	void Update(const float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input) override;
private:
	bool is_activated = false;
	bool can_be_activated = false;
};