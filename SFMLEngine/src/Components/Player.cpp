#include "Components/Player.h"
#include <iostream>
#include "Components/ObjectName.h"

#include "Components/RectangleShapeRenderer.h"
#include <Components/SquareCollider.h>
#include <Scene.h>
#include <Modules/SceneModule.h>




Player::Player() {
	big_doll = new Doll;

	actual_doll = big_doll;
}

Player::~Player() {
	actual_doll = nullptr;

	if (actuall_doll_int == 0)
	{
		delete big_doll;
		big_doll = nullptr;
	}
	else if (actuall_doll_int == 1)
	{
		delete medium_doll;
		medium_doll = nullptr;
	}
	else if (actuall_doll_int == 2)
	{
		delete small_doll;
		small_doll = nullptr;
	}
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

		if (actuall_doll_int == 0)
		{
			medium_doll = new Doll;
			actual_doll = medium_doll;

			delete big_doll;
			big_doll = nullptr;

			GetOwner()->SetPosition(Maths::Vector2f(GetOwner()->GetPosition().GetX(), GetOwner()->GetPosition().GetY() - 200));
			GetOwner()->GetComponent<RectangleShapeRenderer>()->SetColor(sf::Color::Blue);
			actuall_doll_int++;
		}
		else if (actuall_doll_int == 1)
		{
			small_doll = new Doll;
			actual_doll = small_doll;

			delete medium_doll;
			medium_doll = nullptr;

			GetOwner()->SetPosition(Maths::Vector2f(GetOwner()->GetPosition().GetX(), GetOwner()->GetPosition().GetY() - 200));
			GetOwner()->GetComponent<RectangleShapeRenderer>()->SetColor(sf::Color::Green);
			actuall_doll_int++;
		}
		is_switching = false;
		std::cout << actuall_doll_int;
	}
}


void Player::Move(const float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input, std::vector<GameObject*>* gameObjects){
	for (const auto& input : *pressed_input) {
		if (input.first == 3 && input.second == true && GetOwner()->GetComponent<SquareCollider>()->GetCanMoving()["right"]) {
			GetOwner()->SetPosition(Maths::Vector2f(GetOwner()->GetPosition().GetX() + (actual_doll->GetSpeed() * _delta_time), GetOwner()->GetPosition().GetY()));
		}else if (input.first == 16 && input.second == true && GetOwner()->GetComponent<SquareCollider>()->GetCanMoving()["left"]) {
			GetOwner()->SetPosition(Maths::Vector2f(GetOwner()->GetPosition().GetX() - (actual_doll->GetSpeed() * _delta_time), GetOwner()->GetPosition().GetY()));
		}
	}
}

void Player::Jump(const float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input, std::vector<GameObject*>* gameObjects) {
	if (can_jump && !is_jumping) {
		for (const auto& input : *pressed_input) {
			if (input.first == 57 && input.second == true) {
				is_jumping = true;
				jumping_time.restart();

				can_switch = false;
			}
		}
	}
	if (is_jumping && GetOwner()->GetComponent<SquareCollider>()->GetCanMoving()["up"]) {
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
	if (GetOwner()->GetPosition().GetY() + 200 <= sizeWindow.y && !is_jumping && GetOwner()->GetComponent<SquareCollider>()->GetCanMoving()["down"]) {
		GetOwner()->SetPosition(Maths::Vector2f(GetOwner()->GetPosition().GetX(), GetOwner()->GetPosition().GetY() + (200 * _delta_time)));
	}

}


void Player::Update(const float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input) {
	Scene* scene = Engine::GetInstance()->GetModuleManager()->GetModule<SceneModule>()->GetMainScene();
	GetOwner()->GetComponent<SquareCollider>()->SetCanMoving("up", true);
	GetOwner()->GetComponent<SquareCollider>()->SetCanMoving("down", true);
	GetOwner()->GetComponent<SquareCollider>()->SetCanMoving("left", true);
	GetOwner()->GetComponent<SquareCollider>()->SetCanMoving("right", true);
	for (GameObject* const& gameObject : *scene->GetGameObjects())
	{
		if (gameObject->GetName() != ObjectName::PlayerName) {
			GetOwner()->GetComponent<SquareCollider>()->IsColliding(*GetOwner()->GetComponent<SquareCollider>(), *gameObject->GetComponent<SquareCollider>());
		}
	}
	Move(_delta_time, pressed_input, scene->GetGameObjects());
	Jump(_delta_time, pressed_input, scene->GetGameObjects());
	SwitchDoll(pressed_input);
	if (GetOwner()->GetPosition().GetY() + 200 <= sizeWindow.y && GetOwner()->GetComponent<SquareCollider>()->GetCanMoving()["down"]) {
		GetOwner()->SetPosition(Maths::Vector2f(GetOwner()->GetPosition().GetX(), GetOwner()->GetPosition().GetY() + (actual_doll->GetGravity() * _delta_time)));
	}
	else {
		can_jump = true;
		if (actuall_doll_int != 2)
		{
			can_switch = true;
		}
	}
}