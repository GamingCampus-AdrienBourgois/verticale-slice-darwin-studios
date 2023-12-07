#pragma once
#include "RectangleShapeRenderer.h"
#include "Scene.h"
#include "SquareCollider.h"
#include "SpawnWall.h"
#include "Player.h"
#include "WindowModule.h"


class DefaultScene final : public Scene
{
public:

	sf::Vector2u window_size = Engine::GetInstance()->GetModuleManager()->GetModule<WindowModule>()->GetWindowSize();

	DefaultScene() : Scene("DefaultScene")
	{
		
		CreateWalls();

		GameObject* player = CreatePlayer(PlayerName, 200.f, sf::Color::Red);

	}

	GameObject* CreateDummyGameObject(const ObjectName& _name, const float _position, const sf::Color _color)
	{
		GameObject* game_object = CreateGameObject(_name);
		game_object->SetPosition(Maths::Vector2f(_position, _position));

		SquareCollider* square_collider = game_object->CreateComponent<SquareCollider>();
		square_collider->SetWidth(20.f);
		square_collider->SetHeight(20.f);

		RectangleShapeRenderer* shape_renderer = game_object->CreateComponent<RectangleShapeRenderer>();
		shape_renderer->SetColor(_color);
		shape_renderer->SetSize(Maths::Vector2f(200.f, 200.f));
		return game_object;
	}


private:
	void CreateWalls();
	

	GameObject* CreatePlayer(const ObjectName& _name, const float _position, const sf::Color _color) {
		GameObject* game_object = CreateGameObject(_name);
		game_object->SetPosition(Maths::Vector2f(_position, _position));

		SquareCollider* square_collider = game_object->CreateComponent<SquareCollider>();
		square_collider->SetWidth(20.f);
		square_collider->SetHeight(20.f);


		int taille_persoX = window_size.x / 33;
		int taille_persoY = window_size.y / 22;
		RectangleShapeRenderer* shape_renderer = game_object->CreateComponent<RectangleShapeRenderer>();
		shape_renderer->SetColor(_color);
		shape_renderer->SetSize(Maths::Vector2f(taille_persoX, taille_persoY));

		Player* player = game_object->CreateComponent<Player>();


		return game_object;
	}
};
