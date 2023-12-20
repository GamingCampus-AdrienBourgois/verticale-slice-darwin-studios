#pragma once
#include "RectangleShapeRenderer.h"
#include "Scene.h"
#include "SquareCollider.h"
#include "Player.h"
#include "WindowModule.h"
#include "Capacity.h"



class Capacity;

class DefaultScene final : public Scene
{
public:

	sf::Vector2f window_size = Engine::GetInstance()->GetModuleManager()->GetModule<WindowModule>()->GetWindowSize();

	DefaultScene(std::vector<Capacity> params) : Scene("DefaultScene")
	{
		SetTexture("texture_zarya", "Assets/Dolls/Zarya-sheet.png");
		SetTexture("texture_zvezda", "Assets/Dolls/Zvezda-sheet.png");
		SetTexture("texture_zwezda", "Assets/Dolls/Zwezda-sheet.png");
		GetBigCapacity()->SetName(params[0].GetName());
		GetMidCapacity()->SetName(params[1].GetName());
		GetSmallCapacity()->SetName(params[2].GetName());
		SpawnObjectLevel3();
		GameObject* player = CreatePlayer(PlayerType, "Player", Maths::Vector2f(300,400/*window_size.x * 0.1, window_size.y * 0.68*/), Maths::Vector2f((window_size.x/25), (((window_size.x /25)*654)/420)), "texture_zarya", Maths::Vector2f(420, 654), Maths::Vector2f(0, 1));
	}

	GameObject* CreateColliderObject(Scene* scene, const ObjectType& _type, std::string _name, Maths::Vector2f _position, Maths::Vector2f _size) {
		GameObject* game_object = scene->CreateGameObject(_type, _name);
		game_object->SetPosition(_position);

		sf::Vector2f window_size = Engine::GetInstance()->GetModuleManager()->GetModule<WindowModule>()->GetWindowSize();

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

		sf::Vector2f window_size = Engine::GetInstance()->GetModuleManager()->GetModule<WindowModule>()->GetWindowSize();

		SquareCollider* squareCollider = game_object->CreateComponent<SquareCollider>();
		squareCollider->SetWidth(window_size.x / 33);
		squareCollider->SetHeight(window_size.y / 22);

		RectangleShapeRenderer* shapeRenderer = game_object->CreateComponent<RectangleShapeRenderer>();
		shapeRenderer->SetColor(sf::Color{255,0,0,50}); 
		shapeRenderer->SetSize(Maths::Vector2f(window_size.x / 33, window_size.y / 22)); 

		return game_object;
	}

private:

	void SpawnObjectLevel3();
};
