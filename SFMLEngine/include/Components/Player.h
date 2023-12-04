#pragma once
#include "GameObject.h"
#include "Doll.h"


class Player : public Component
{
public:


	void Move(const float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input);
	void Jump(const float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input);

	void Update(const float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input) override;

private:
	bool can_jump = true;
	bool is_jumping = false;
	sf::Clock jumping_time;


	Doll* small_doll = nullptr;
	Doll* medium_doll = nullptr;
	Doll* big_doll = nullptr;

	Doll* actual_doll = small_doll;
};
