#include "Components/Player.h"
#include <iostream>
#include "Components/RectangleShapeRenderer.h"
#include <Components/SquareCollider.h>
#include <Scene.h>
#include <Modules/SceneModule.h>
#include "Components/ObjectType.h"
#include "Modules/WindowModule.h"

#include <Capacity/Force.h>
#include "Components/Switch.h"
#include <Capacity/Invincibilite.h>
#include <Capacity/InversionGravite.h>

#include "Capacity/Dash.h"


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
	if (!GetOwner()->GetComponent<SquareCollider>()->GetCanMoving()["down"] && is_jumping) {
		is_jumping = false;
		is_double_jumping = false;
	}
	if (is_jumping && can_double_jump && !is_double_jumping) {
		for (const auto& input : *pressed_input) {
			if (input.first == 57 && input.second == true) {
				is_jumping = true;
				is_double_jumping = true;
				jumping_time.restart();

				can_switch = false;
			}
		}
	}
	if (can_jump && !is_jumping) {
		for (auto& input : *pressed_input) {
			if (input.first == 57 && input.second == true) {
				is_jumping = true;
				jumping_time.restart();

				can_switch = false;

				input.second = false;
			}
		}
	}

	if (!GetOwner()->GetComponent<SquareCollider>()->GetCanMoving()["up"]) {
		is_jumping = false;
	}

	if (is_jumping && GetOwner()->GetComponent<SquareCollider>()->GetCanMoving()["up"]) {
		if (jumping_time.getElapsedTime().asSeconds() <= 0.4) {
		GetOwner()->SetPosition(Maths::Vector2f(GetOwner()->GetPosition().GetX(), GetOwner()->GetPosition().GetY() - (window_size.y * 0.3 * _delta_time)));
		}
		else if (jumping_time.getElapsedTime().asSeconds() <= 0.5) {
		GetOwner()->SetPosition(Maths::Vector2f(GetOwner()->GetPosition().GetX(), GetOwner()->GetPosition().GetY() - (window_size.y * 0 * _delta_time)));
		}
		else{
		GetOwner()->SetPosition(Maths::Vector2f(GetOwner()->GetPosition().GetX(), GetOwner()->GetPosition().GetY() + (window_size.y * 0.3 * _delta_time)));
		can_jump = false;
		}
	}

if (GetOwner()->GetPosition().GetY() + 200 <= sizeWindow.y && !is_jumping && GetOwner()->GetComponent<SquareCollider>()->GetCanMoving()["down"]) {
	GetOwner()->SetPosition(Maths::Vector2f(GetOwner()->GetPosition().GetX(), GetOwner()->GetPosition().GetY() + (window_size.y * 0.1 * _delta_time)));
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

void Player::SwitchDoll(std::unordered_map<sf::Keyboard::Key, bool>* pressed_input, Scene* scene) {
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
		can_check = false;

		Maths::Vector2f position = GetOwner()->GetPosition();
		sf::Color actuall_color = GetOwner()->GetComponent<RectangleShapeRenderer>()->GetColor();

		if (actuall_doll_int == 0)
		{
			big_dollOff = CreateDollOff(DollOffType, "big_doll_off", position, actuall_color);
			GetOwner()->SetPosition(Maths::Vector2f(position.GetX(), position.GetY() - sizePlayer * 1.5));
			GetOwner()->GetComponent<RectangleShapeRenderer>()->SetColor(colorMid);
			Capacity* capacity_for_mid_doll = scene->GetMidCapacity();

			delete capacity;
			capacity = nullptr;

			if (capacity_for_mid_doll->GetName() == "INVERSION DE LA GRaVITE") {
				InversionGravite* new_capacity = SetCapacity<InversionGravite>();
				new_capacity->SetName("InversionGravite");
				new_capacity->SetCapacityOwner(GetOwner());
				capacity = new_capacity;
			}
			else if (capacity_for_mid_doll->GetName() == "INVINCIbILITE") {
				Invincibilite* new_capacity = SetCapacity<Invincibilite>();
				new_capacity->SetName("Invincibilite");
				new_capacity->SetCapacityOwner(GetOwner());
				capacity = new_capacity;
			}
			else if (capacity_for_mid_doll->GetName() == "DOUbLE-SaUT") {
				DoubleJump* new_capacity = SetCapacity<DoubleJump>();
				new_capacity->SetName("DoubleJump");
				new_capacity->SetCapacityOwner(GetOwner());
				new_capacity->SetDoubleJump(true);
				capacity = new_capacity;
			}
			else if (capacity_for_mid_doll->GetName() == "DaSH") {
				Dash* new_capacity = SetCapacity<Dash>();
				new_capacity->SetName("Dash");
				new_capacity->SetCapacityOwner(GetOwner());
				capacity = new_capacity;
			}
			else if (capacity_for_mid_doll->GetName() == "fORCE") {
				Force* new_capacity = SetCapacity<Force>();
				new_capacity->SetName("Force");
				new_capacity->SetCapacityOwner(GetOwner());
				capacity = new_capacity;
			}

			//// Création du Checkpoint
			// Copie des GameObjects
			gameObjectsCheckpoint.clear();

			for (GameObject* const& gameObject : *scene->GetGameObjects())
			{
				GameObject* gameObjectTemp = new GameObject(*gameObject);
				gameObjectsCheckpoint.push_back(gameObjectTemp);
			}

			////




			actuall_doll_int++;
		}
		else if (actuall_doll_int == 1)
		{
			mid_dollOff = CreateDollOff(DollOffType, "mid_doll_off", position, actuall_color);
			GetOwner()->SetPosition(Maths::Vector2f(position.GetX(), position.GetY() - sizePlayer * 1.5));
			GetOwner()->GetComponent<RectangleShapeRenderer>()->SetColor(colorSmall);
			Capacity* capacity_for_small_doll = scene->GetSmallCapacity();

			delete capacity;
			capacity = nullptr;

			if (capacity_for_small_doll->GetName() == "INVERSION DE LA GRaVITE") {
				InversionGravite* new_capacity = SetCapacity<InversionGravite>();
				new_capacity->SetName("InversionGravite");
				new_capacity->SetCapacityOwner(GetOwner());
				capacity = new_capacity;
			}
			else if (capacity_for_small_doll->GetName() == "INVINCIbILITE") {
				Invincibilite* new_capacity = SetCapacity<Invincibilite>();
				new_capacity->SetName("Invincibilite");
				new_capacity->SetCapacityOwner(GetOwner());
				capacity = new_capacity;
			}
			else if (capacity_for_small_doll->GetName() == "DOUbLE-SaUT") {
				DoubleJump* new_capacity = SetCapacity<DoubleJump>();
				new_capacity->SetName("DoubleJump");
				new_capacity->SetCapacityOwner(GetOwner());
				new_capacity->SetDoubleJump(true);
				capacity = new_capacity;
			}
			else if (capacity_for_small_doll->GetName() == "DaSH") {
				Dash* new_capacity = SetCapacity<Dash>();
				new_capacity->SetName("Dash");
				new_capacity->SetCapacityOwner(GetOwner());
				capacity = new_capacity;
			}
			else if (capacity_for_small_doll->GetName() == "fORCE") {
				Force* new_capacity = SetCapacity<Force>();
				new_capacity->SetName("Force");
				new_capacity->SetCapacityOwner(GetOwner());
				capacity = new_capacity;
			}

			//// Création du Checkpoint
			// Copie des GameObjects
			gameObjectsCheckpoint.clear();

			for (GameObject* const& gameObject : *scene->GetGameObjects())
			{
				GameObject* gameObjectTemp = new GameObject(*gameObject);
				gameObjectsCheckpoint.push_back(gameObjectTemp);
			}

			////

			actuall_doll_int++;
		}
		is_switching = false;
	}
}

void Player::ReturnCheckpoint(Scene* scene, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input) {
	if (can_check && !is_check)
	{
		auto it = pressed_input->begin();

		while (it != pressed_input->end()) {
			const auto& input = *it;

			if (input.first == 59 && input.second == true) {
				is_check = true;
				// Effacer l'élément du vecteur
				it = pressed_input->erase(it);
			}
			else {
				++it;
			}
		}
	}

	if (is_check)
	{
		can_switch = false;
		can_jump = false;
		can_check = false;

		Maths::Vector2f position = GetOwner()->GetPosition();
		sf::Color actuall_color = GetOwner()->GetComponent<RectangleShapeRenderer>()->GetColor();

		std::string nameScene = scene->GetName();
			
		std::vector<GameObject*>* gameObjects = scene->GetGameObjects();

		for (int i = 0; i < gameObjects->size(); i++)
		{
			if (i >= gameObjectsCheckpoint.size())
			{
				scene->DestroyGameObject((*gameObjects)[i]);
			}
			else
			{
				*(*gameObjects)[i] = *gameObjectsCheckpoint[i];
			}
		}
		
		is_check = false;
	}
}

bool Player::Dead(std::vector<GameObject*>* gameObjects)
{
	if (hp <= 0)
	{
		std::cout << "T'es mort!!" << std::endl;
		GetOwner()->RemoveComponent(GetOwner()->GetComponent<Player>());
		GetOwner()->RemoveComponent(GetOwner()->GetComponent<SpriteRenderer>());
		GetOwner()->RemoveComponent(GetOwner()->GetComponent<SquareCollider>());
		for (auto it = gameObjects->begin(); it != gameObjects->end(); ++it)
		{
			if (*it == GetOwner())
			{
				delete GetOwner();
				gameObjects->erase(it);
				return true;
			}
		}
	}
	else
	{
		return false;
	}
}


void Player::Update(const float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input) {
	Scene* scene = Engine::GetInstance()->GetModuleManager()->GetModule<SceneModule>()->GetMainScene();

	if (!copiedSpawn)
	{
		for (GameObject* const& gameObject : *scene->GetGameObjects())
		{
			GameObject* gameObjectTemp = new GameObject(*gameObject); 
			gameObjectsCheckpoint.push_back(gameObjectTemp); 
		}

		copiedSpawn = true;
	}
	

	GetCapacity()->Update(_delta_time, pressed_input);

	GetOwner()->GetComponent<SquareCollider>()->SetCanMoving("up", true);
	GetOwner()->GetComponent<SquareCollider>()->SetCanMoving("down", true);
	GetOwner()->GetComponent<SquareCollider>()->SetCanMoving("left", true);
	GetOwner()->GetComponent<SquareCollider>()->SetCanMoving("right", true);
	for (GameObject* const& gameObject : *scene->GetGameObjects())
	{
		if (gameObject->GetType() != ObjectType::PlayerType) {
			GetOwner()->GetComponent<SquareCollider>()->IsColliding(*GetOwner()->GetComponent<SquareCollider>(), *gameObject->GetComponent<SquareCollider>() , _delta_time);
		}
	}
	Move(_delta_time, pressed_input, scene->GetGameObjects());
	Jump(_delta_time, pressed_input, scene->GetGameObjects());
	SwitchDoll(pressed_input, scene);
	ReturnCheckpoint(scene, pressed_input);
	Dead(scene->GetGameObjects());

	for (GameObject* const& gameObject : *scene->GetGameObjects())
	{
		if (gameObject->GetType() == ObjectType::SwitchType && SquareCollider::IsColliding(*GetOwner()->GetComponent<SquareCollider>(), *gameObject->GetComponent<SquareCollider>(), _delta_time))
		{
			GameObject* switchObject = GetOwner();
			if (switchObject)
			{
				switchObject->SetSwitchOn(true);
				std::cout << switchObject->GetSwitchOn() << std::endl;
			}
		}
	}


	can_check = true;
	if (GetOwner()->GetPosition().GetX() <= 0) {
		GetOwner()->SetPosition(Maths::Vector2f(0, GetOwner()->GetPosition().GetY()));
	}
	if (GetOwner()->GetPosition().GetX() + sizePlayer >= sizeWindow.x) {
		GetOwner()->SetPosition(Maths::Vector2f(sizeWindow.x - sizePlayer, GetOwner()->GetPosition().GetY()));
	}

	bool temp = GetOwner()->GetComponent<SquareCollider>()->GetCanMoving()["down"];

	if (GetOwner()->GetPosition().GetY() + sizePlayer <= sizeWindow.y && temp) {
		GetOwner()->SetPosition(Maths::Vector2f(GetOwner()->GetPosition().GetX(), GetOwner()->GetPosition().GetY() + (gravity * _delta_time)));
		can_switch = false;	
		can_jump = false;
	}
	else {
		can_jump = true;
		if (actuall_doll_int != 2)
		{
			can_switch = true;
		}
	}
}

template<typename T>
T* Player::SetCapacity()
{
	T* _capacity = new T();
	capacity = _capacity;
	return _capacity;
}
