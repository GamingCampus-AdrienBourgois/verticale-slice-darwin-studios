#pragma once
#include "RectangleShapeRenderer.h"
#include "Scene.h"
#include "SquareCollider.h"
#include "Player.h"
#include "WindowModule.h"
#include <Force.h>
#include <Invincibilite.h>


class DefaultScene final : public Scene
{
public:

	sf::Vector2u window_size = Engine::GetInstance()->GetModuleManager()->GetModule<WindowModule>()->GetWindowSize();

	DefaultScene() : Scene("DefaultScene")
	{
		SpawnObjectLevel3();
		GameObject* player = CreatePlayer(PlayerType, "Player", Maths::Vector2f(100, 240), sf::Color::Red);

	}

	GameObject* CreateDummyGameObject(const ObjectType& _type, std::string _name, const float _position, const sf::Color _color)
	{
		GameObject* game_object = CreateGameObject(_type, _name);
		game_object->SetPosition(Maths::Vector2f(_position, _position));

		SquareCollider* square_collider = game_object->CreateComponent<SquareCollider>();
		square_collider->SetWidth(20.f);
		square_collider->SetHeight(20.f);

		RectangleShapeRenderer* shape_renderer = game_object->CreateComponent<RectangleShapeRenderer>();
		shape_renderer->SetColor(_color);
		shape_renderer->SetSize(Maths::Vector2f(200.f, 200.f));
		return game_object;
	}

	GameObject* CreateWallObject(Scene* scene, const ObjectType& _type, std::string _name, const float _x, const float _y) {
		GameObject* game_object = scene->CreateGameObject(_type, _name);
		game_object->SetPosition(Maths::Vector2f(_x, _y));

		sf::Vector2u window_size = Engine::GetInstance()->GetModuleManager()->GetModule<WindowModule>()->GetWindowSize();

		SquareCollider* squareCollider = game_object->CreateComponent<SquareCollider>();
		squareCollider->SetWidth(window_size.x / 33);
		squareCollider->SetHeight(window_size.y / 22);

		RectangleShapeRenderer* shapeRenderer = game_object->CreateComponent<RectangleShapeRenderer>();
		shapeRenderer->SetColor(sf::Color::White); // Couleur du mur
		shapeRenderer->SetSize(Maths::Vector2f(window_size.x / 33, window_size.y / 22)); // Taille du mur

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
		shapeRenderer->SetColor(sf::Color::Red); // Couleur du mur
		shapeRenderer->SetSize(Maths::Vector2f(window_size.x / 33, window_size.y / 22)); // Taille du mur

		return game_object;
	}

private:
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

		Capacity* capacity = game_object->CreateCapacity<Invincibilite>();


		return game_object;
	}
};
