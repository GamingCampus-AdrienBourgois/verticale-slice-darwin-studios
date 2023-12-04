#include "Components/Player.h"
#include <iostream>
#include "Components/ObjectName.h"


void Player::Move(const float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input){
	for (const auto& input : *pressed_input) {
		if (input.first == 3 && input.second == true) {
			GetOwner()->SetPosition(Maths::Vector2f(GetOwner()->GetPosition().GetX() + (100 * _delta_time), GetOwner()->GetPosition().GetY()));
		}else if (input.first == 16 && input.second == true) {
			GetOwner()->SetPosition(Maths::Vector2f(GetOwner()->GetPosition().GetX() - (100 * _delta_time), GetOwner()->GetPosition().GetY()));
		}
	}
}

void Player::Jump(const float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input) {
	if (can_jump && !is_jumping) {
		for (const auto& input : *pressed_input) {
			if (input.first == 57 && input.second == true) {
				is_jumping = true;
				jumping_time.restart();
			}
		}
	}
	if (is_jumping) {
		if (jumping_time.getElapsedTime().asSeconds() <= 0.4) {
			GetOwner()->SetPosition(Maths::Vector2f(GetOwner()->GetPosition().GetX(), GetOwner()->GetPosition().GetY() - (500 * _delta_time)));
		}
		else if (jumping_time.getElapsedTime().asSeconds() <= 0.45) {
			GetOwner()->SetPosition(Maths::Vector2f(GetOwner()->GetPosition().GetX(), GetOwner()->GetPosition().GetY() - (400 * _delta_time)));
		}
		else if (jumping_time.getElapsedTime().asSeconds() <= 0.5) {
			GetOwner()->SetPosition(Maths::Vector2f(GetOwner()->GetPosition().GetX(), GetOwner()->GetPosition().GetY() - (300 * _delta_time)));
		}
		else if (jumping_time.getElapsedTime().asSeconds() <= 0.55) {
			GetOwner()->SetPosition(Maths::Vector2f(GetOwner()->GetPosition().GetX(), GetOwner()->GetPosition().GetY() - (150 * _delta_time)));
		}
		else if (jumping_time.getElapsedTime().asSeconds() <= 0.575) {
			GetOwner()->SetPosition(Maths::Vector2f(GetOwner()->GetPosition().GetX(), GetOwner()->GetPosition().GetY() - (75 * _delta_time)));
		}
		else if (jumping_time.getElapsedTime().asSeconds() <= 0.585) {
			GetOwner()->SetPosition(Maths::Vector2f(GetOwner()->GetPosition().GetX(), GetOwner()->GetPosition().GetY() - (35 * _delta_time)));
		}
		else if (jumping_time.getElapsedTime().asSeconds() <= 0.595) {
			GetOwner()->SetPosition(Maths::Vector2f(GetOwner()->GetPosition().GetX(), GetOwner()->GetPosition().GetY() - (0 * _delta_time)));
		}
		else{
			is_jumping = false;
			can_jump = false;
		}
	}
	if (GetOwner()->GetPosition().GetY() + 200 <= 600 && !is_jumping) {
		GetOwner()->SetPosition(Maths::Vector2f(GetOwner()->GetPosition().GetX(), GetOwner()->GetPosition().GetY() + (200 * _delta_time)));
	}
	
}


void Player::Update(const float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input) {
	Move(_delta_time, pressed_input);
	Jump(_delta_time, pressed_input);
	if (GetOwner()->GetPosition().GetY() + 200 <= 600) {
		GetOwner()->SetPosition(Maths::Vector2f(GetOwner()->GetPosition().GetX(), GetOwner()->GetPosition().GetY() + (100 * _delta_time)));
	}
	else {
		can_jump = true;
	}
}