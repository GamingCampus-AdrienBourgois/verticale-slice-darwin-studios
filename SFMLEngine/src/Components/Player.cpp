#include "Components/Player.h"
#include <iostream>
#include "Components/ObjectName.h"

#include "Components/RectangleShapeRenderer.h"
#include "Components/SquareCollider.h"

void Player::Move(const float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input){
	for (const auto& input : *pressed_input) {
		if (input.first == 3 && input.second == true) {
			GetOwner()->SetPosition(Maths::Vector2f(GetOwner()->GetPosition().GetX() + (speed * _delta_time), GetOwner()->GetPosition().GetY()));
		}else if (input.first == 16 && input.second == true) {
			GetOwner()->SetPosition(Maths::Vector2f(GetOwner()->GetPosition().GetX() - (speed * _delta_time), GetOwner()->GetPosition().GetY()));
		}
	}
}

void Player::Jump(const float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input) {
	if (can_jump && !is_jumping) {
		for (const auto& input : *pressed_input) {
			if (input.first == 57 && input.second == true) {
				is_jumping = true;
				jumping_time.restart();

				can_switch = false;
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
	if (GetOwner()->GetPosition().GetY() +100 <= sizeWindow.y && !is_jumping) {
		GetOwner()->SetPosition(Maths::Vector2f(GetOwner()->GetPosition().GetX(), GetOwner()->GetPosition().GetY() + (200 * _delta_time)));
	}

}

GameObject* Player::CreateDollOff(const ObjectName& _name, Maths::Vector2f _position, const sf::Color _color) {
	Scene* scene = sceneModule->GetScene("DefaultScene");

	GameObject* game_object = scene->CreateGameObject(_name);
	game_object->SetPosition(_position);

	SquareCollider* square_collider = game_object->CreateComponent<SquareCollider>();
	square_collider->SetWidth(20.f);
	square_collider->SetHeight(20.f);

	RectangleShapeRenderer* shape_renderer = game_object->CreateComponent<RectangleShapeRenderer>();
	shape_renderer->SetColor(_color);
	shape_renderer->SetSize(Maths::Vector2f(200.f, 200.f));

	DollOff* dollOff = game_object->CreateComponent<DollOff>();
	dollOff->setColor(_color);
	dollOff->setPosition(_position);

	return game_object;
}

void Player::SwitchDoll(std::unordered_map<sf::Keyboard::Key, bool>* pressed_input) {
	if (can_switch && !is_switching)
	{
		for (const auto& input : *pressed_input) {
			if (input.first == 0 && input.second == true) {
				is_switching = true;
			}
		}
	}

	if (is_switching)
	{
		can_switch = false;
		can_jump = false;

		Maths::Vector2f position = GetOwner()->GetPosition();
		sf::Color actuall_color = GetOwner()->GetComponent<RectangleShapeRenderer>()->GetColor();

		if (actuall_doll_int == 0)
		{
			big_dollOff = CreateDollOff(DollOffName, position, actuall_color);

			GetOwner()->SetPosition(Maths::Vector2f(position.GetX(), position.GetY() - 200));
			GetOwner()->GetComponent<RectangleShapeRenderer>()->SetColor(sf::Color::Blue);
			actuall_doll_int++;
		}
		else if (actuall_doll_int == 1)
		{
			big_dollOff = nullptr;
			mid_dollOff = CreateDollOff(DollOffName, position, actuall_color);

			GetOwner()->SetPosition(Maths::Vector2f(position.GetX(), position.GetY() - 200));
			GetOwner()->GetComponent<RectangleShapeRenderer>()->SetColor(sf::Color::Green);
			actuall_doll_int++;
		}
		is_switching = false;
		std::cout << actuall_doll_int;
	}
}


void Player::Update(const float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input) {
	Move(_delta_time, pressed_input);
	Jump(_delta_time, pressed_input);
	SwitchDoll(pressed_input);
	if (GetOwner()->GetPosition().GetY() + 200 <= sizeWindow.y) {
		GetOwner()->SetPosition(Maths::Vector2f(GetOwner()->GetPosition().GetX(), GetOwner()->GetPosition().GetY() + (gravity * _delta_time)));
	}
	else {
		can_jump = true;
		if (actuall_doll_int != 2)
		{
			can_switch = true;
		}
	}
}