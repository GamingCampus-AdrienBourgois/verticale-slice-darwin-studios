#pragma once
#include "RectangleShapeRenderer.h"
#include "Scene.h"
#include "SquareCollider.h"
#include "Player.h"
#include "WindowModule.h"
#include <InversionGravite.h>
#include "Invincibilite.h"
#include "Force.h"
#include "Dash.h"


class DefaultScene final : public Scene
{
public:

	sf::Vector2u window_size = Engine::GetInstance()->GetModuleManager()->GetModule<WindowModule>()->GetWindowSize();

	DefaultScene(std::vector<Capacity> params) : Scene("DefaultScene")
	{
		capacity_for_big_doll = params[0];
		capacity_for_mid_doll = params[1];
		capacity_for_small_doll = params[2];
		SpawnObjectLevel3();
		GameObject* player = CreatePlayer(PlayerType, "Player", Maths::Vector2f(100, 40), sf::Color::Red);
	}

	GameObject* CreateColliderObject(Scene* scene, const ObjectType& _type, std::string _name, Maths::Vector2f _position, Maths::Vector2f _size) {
		GameObject* game_object = scene->CreateGameObject(_type, _name);
		game_object->SetPosition(_position);

		sf::Vector2u window_size = Engine::GetInstance()->GetModuleManager()->GetModule<WindowModule>()->GetWindowSize();

		SquareCollider* squareCollider = game_object->CreateComponent<SquareCollider>();
		squareCollider->SetWidth(_size.x);
		squareCollider->SetHeight(_size.y);

		RectangleShapeRenderer* shapeRenderer = game_object->CreateComponent<RectangleShapeRenderer>();
		shapeRenderer->SetColor(sf::Color{ 255,255,255,50 }); // Couleur du mur
		shapeRenderer->SetSize(Maths::Vector2f(_size.x, _size.y)); // Taille du mur

		return game_object;
	}

	GameObject* CreateSwitch(Scene* scene, const ObjectType& _type, std::string _name, const float _x, const float _y) {
		GameObject* game_object = scene->CreateGameObject(_type, _name);
		game_object->SetPosition(Maths::Vector2f(_x, _y));

		sf::Vector2u window_size = Engine::GetInstance()->GetModuleManager()->GetModule<WindowModule>()->GetWindowSize();

		SquareCollider* squareCollider = game_object->CreateComponent<SquareCollider>();
		squareCollider->SetWidth(window_size.x / 33);
		squareCollider->SetHeight(window_size.y / 22);

		RectangleShapeRenderer* shapeRenderer = game_object->CreateComponent<RectangleShapeRenderer>();
		shapeRenderer->SetColor(sf::Color{255,0,0,50}); 
		shapeRenderer->SetSize(Maths::Vector2f(window_size.x / 33, window_size.y / 22)); 

		return game_object;
	}

private:
	Capacity capacity_for_big_doll;
	Capacity capacity_for_mid_doll;
	Capacity capacity_for_small_doll;

	void SpawnObjectLevel3();

	GameObject* CreatePlayer(const ObjectType& _type, std::string _name, Maths::Vector2f _position, const sf::Color _color) {
		GameObject* game_object = CreateGameObject(_type, _name);
		game_object->SetPosition(_position);

		int taille_persoX = window_size.x / 33;
		int taille_persoY = window_size.y / 22;

		SquareCollider* square_collider = game_object->CreateComponent<SquareCollider>();
		square_collider->SetWidth(taille_persoX);
		square_collider->SetHeight(taille_persoY);

		RectangleShapeRenderer* shape_renderer = game_object->CreateComponent<RectangleShapeRenderer>();
		shape_renderer->SetColor(_color);
		shape_renderer->SetSize(Maths::Vector2f(taille_persoX, taille_persoY));

		Player* player = game_object->CreateComponent<Player>();


		//Capacity* capacity = game_object->CreateCapacity<InversionGravite>();

		DoubleJump* capacity = game_object->CreateCapacity<DoubleJump>();
		capacity->SetName("DoubleJump");
		capacity->SetDoubleJump(true);

		/*Capacity* capacity = game_object->CreateCapacity<Invincibilite>();*/

		//Capacity* capacity = game_object->CreateCapacity<Force>();

		//Capacity* capacity = game_object->CreateCapacity<Dash>();



		return game_object;
	}


};
