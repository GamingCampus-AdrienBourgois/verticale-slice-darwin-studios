#pragma once
#include "RectangleShapeRenderer.h"
#include "Scene.h"
#include "SquareCollider.h"

class SelectCapacityScene final : public Scene
{
public:
	SelectCapacityScene() : Scene("SelectCapacityScene")
	{
		GameObject* button = CreateDummyGameObject(ButtonName, 200.f, sf::Color::Blue);
		GameObject* button2 = CreateDummyGameObject(ButtonName, 500.f, sf::Color::Red);

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
};