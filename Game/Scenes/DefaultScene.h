#pragma once
#include "RectangleShapeRenderer.h"
#include "Scene.h"
#include "SquareCollider.h"
#include "Player.h"

class DefaultScene final : public Scene
{
public:
	DefaultScene() : Scene("DefaultScene")
	{
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

	GameObject* CreatePlayer(const ObjectName& _name, const float _position, const sf::Color _color) {
		GameObject* game_object = CreateGameObject(_name);
		game_object->SetPosition(Maths::Vector2f(_position, _position));

		SquareCollider* square_collider = game_object->CreateComponent<SquareCollider>();
		square_collider->SetWidth(20.f);
		square_collider->SetHeight(20.f);

		RectangleShapeRenderer* shape_renderer = game_object->CreateComponent<RectangleShapeRenderer>();
		shape_renderer->SetColor(_color);
		shape_renderer->SetSize(Maths::Vector2f(200.f, 200.f));

		Player* player = game_object->CreateComponent<Player>();


		return game_object;
	}
};
