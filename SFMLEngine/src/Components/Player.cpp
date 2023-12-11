#include "Components/Player.h"
#include <iostream>
#include "Components/RectangleShapeRenderer.h"
#include <Components/SquareCollider.h>
#include <Scene.h>
#include <Modules/SceneModule.h>
#include "Components/ObjectType.h"
#include <Capacity/Force.h>

void Player::Move(const float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input, std::vector<GameObject*>* gameObjects){
	for (const auto& input : *pressed_input) {
		if (input.first == 3 && input.second == true && GetOwner()->GetComponent<SquareCollider>()->GetCanMoving()["right"]) {
			GetOwner()->SetPosition(Maths::Vector2f(GetOwner()->GetPosition().GetX() + (speed * _delta_time), GetOwner()->GetPosition().GetY()));
		}else if (input.first == 16 && input.second == true && GetOwner()->GetComponent<SquareCollider>()->GetCanMoving()["left"]) {
			GetOwner()->SetPosition(Maths::Vector2f(GetOwner()->GetPosition().GetX() - (speed * _delta_time), GetOwner()->GetPosition().GetY()));
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

	if (!GetOwner()->GetComponent<SquareCollider>()->GetCanMoving()["up"]) {
		is_jumping = false;
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
  int taille_perso = sizeWindow.y / 22;
	if (GetOwner()->GetPosition().GetY() + 200 <= sizeWindow.y && !is_jumping && GetOwner()->GetComponent<SquareCollider>()->GetCanMoving()["down"]) {
		GetOwner()->SetPosition(Maths::Vector2f(GetOwner()->GetPosition().GetX(), GetOwner()->GetPosition().GetY() + (200 * _delta_time)));
	}

}

GameObject* Player::CreateDollOff(const ObjectType& _type, std::string _name, Maths::Vector2f _position, const sf::Color _color) {
	Scene* scene = sceneModule->GetScene("DefaultScene");

	GameObject* game_object = scene->CreateGameObject(_type, _name);
	game_object->SetPosition(_position);

	int taille_persoX = sizeWindow.x / 33;
	int taille_persoY = sizeWindow.y / 22;

	SquareCollider* square_collider = game_object->CreateComponent<SquareCollider>();
	square_collider->SetWidth(taille_persoX);
	square_collider->SetHeight(taille_persoY);

	RectangleShapeRenderer* shape_renderer = game_object->CreateComponent<RectangleShapeRenderer>();
	shape_renderer->SetColor(_color);
	shape_renderer->SetSize(Maths::Vector2f(taille_persoX, taille_persoY));

	DollOff* dollOff = game_object->CreateComponent<DollOff>();
	dollOff->setColor(_color);
	dollOff->setPosition(_position);

	return game_object;
}

void Player::SwitchDoll(std::unordered_map<sf::Keyboard::Key, bool>* pressed_input) {
	if (can_switch && !is_switching)
	{
		auto it = pressed_input->begin();

		while (it != pressed_input->end()) {
			const auto& input = *it;

			if (input.first == 0 && input.second == true) {
				is_switching = true;
				// Effacer l'élément du vecteur
				it = pressed_input->erase(it);
			}
			else {
				++it;
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
			big_dollOff = CreateDollOff(DollOffType,"big_doll_off", position, actuall_color);

			GetOwner()->SetPosition(Maths::Vector2f(position.GetX(), position.GetY() - 200));
			GetOwner()->GetComponent<RectangleShapeRenderer>()->SetColor(sf::Color::Blue);
			actuall_doll_int++;
		}
		else if (actuall_doll_int == 1)
		{
			mid_dollOff = CreateDollOff(DollOffType,"mid_doll_off", position, actuall_color);

			GetOwner()->SetPosition(Maths::Vector2f(position.GetX(), position.GetY() - 200));
			GetOwner()->GetComponent<RectangleShapeRenderer>()->SetColor(sf::Color::Green);
			actuall_doll_int++;
		}
		is_switching = false;


		std::cout << actuall_doll_int;
	}
}


void Player::Update(const float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input) {
	Scene* scene = Engine::GetInstance()->GetModuleManager()->GetModule<SceneModule>()->GetMainScene();

	GetOwner()->GetCapacity<Force>()->Update(_delta_time, pressed_input);

	GetOwner()->GetComponent<SquareCollider>()->SetCanMoving("up", true);
	GetOwner()->GetComponent<SquareCollider>()->SetCanMoving("down", true);
	GetOwner()->GetComponent<SquareCollider>()->SetCanMoving("left", true);
	GetOwner()->GetComponent<SquareCollider>()->SetCanMoving("right", true);
	for (GameObject* const& gameObject : *scene->GetGameObjects())
	{
		if (gameObject->GetType() != ObjectType::PlayerType) {
			GetOwner()->GetComponent<SquareCollider>()->IsColliding(*GetOwner()->GetComponent<SquareCollider>(), *gameObject->GetComponent<SquareCollider>());
		}
	}
	Move(_delta_time, pressed_input, scene->GetGameObjects());
	Jump(_delta_time, pressed_input, scene->GetGameObjects());
	SwitchDoll(pressed_input);

	int taille_perso = sizeWindow.y / 22;
  
	if (GetOwner()->GetPosition().GetY() + taille_perso <= sizeWindow.y && GetOwner()->GetComponent<SquareCollider>()->GetCanMoving()["down"]) {
		GetOwner()->SetPosition(Maths::Vector2f(GetOwner()->GetPosition().GetX(), GetOwner()->GetPosition().GetY() + (gravity * _delta_time)));
		can_jump = false;
		can_switch = false;	
	}
	else {
		can_jump = true;
		if (actuall_doll_int != 2)
		{
			can_switch = true;
		}
	}
}