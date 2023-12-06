#include "Components/Button.h"
#include <iostream>


void Button::Execute() {
	if (name == "launch_game_button") {
	}
}


void Button::Update(const float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input) {
	Execute();
}