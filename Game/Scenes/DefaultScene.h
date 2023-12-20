#pragma once
#include "RectangleShapeRenderer.h"
#include "Scene.h"
#include "SquareCollider.h"
#include "Player.h"
#include "WindowModule.h"
#include "Capacity.h"


#include "PauseScene.h"
#include "DeathScene.h"
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

		SpawnObjectLevel3(params);
		SetTexture("texture_return_button", "Assets/button/return_button.png");
		GameObject * return_button = CreateSpriteButton_forMainMenu(ButtonType, "button_pause", Maths::Vector2f(window_size.x - window_size.x / 50 - 161, window_size.y / 50), Maths::Vector2f(window_size.x / 20, ((((window_size.x / 20) * 161) / 144))), [this] {LaunchPause(); }, nullptr, "texture_return_button", Maths::Vector2f(144, 161), Maths::Vector2f(0, 15));

		GameObject* player = CreatePlayer(PlayerType, "Player", Maths::Vector2f(300,400/*window_size.x * 0.1, window_size.y * 0.68*/), Maths::Vector2f((window_size.x/25), (((window_size.x /25)*654)/420)), "texture_zarya", Maths::Vector2f(420, 654), Maths::Vector2f(0, 1));
		player->GetComponent<Player>()->SetPauseEscape([this] {LaunchPause(); });
		player->GetComponent<Player>()->SetDeathCallback([this] { LaunchDeath(); });
	}

	GameObject* CreateColliderObject(Scene* scene, const ObjectType& _type, std::string _name, Maths::Vector2f _position, Maths::Vector2f _size) {
		GameObject* game_object = scene->CreateGameObject(_type, _name);
		game_object->SetPosition(_position);

		sf::Vector2f window_size = Engine::GetInstance()->GetModuleManager()->GetModule<WindowModule>()->GetWindowSize();

		SquareCollider* squareCollider = game_object->CreateComponent<SquareCollider>();
		squareCollider->SetWidth(_size.x);
		squareCollider->SetHeight(_size.y);

		RectangleShapeRenderer* shapeRenderer = game_object->CreateComponent<RectangleShapeRenderer>();
		shapeRenderer->SetColor(sf::Color{ 255,0,0,50 }); // Couleur du mur
		shapeRenderer->SetSize(Maths::Vector2f(_size.x, _size.y)); // Taille du mur

		return game_object;
	}

private:

	void SpawnObjectLevel3(std::vector<Capacity> params);

	void LaunchPause() {
		SceneModule* scene_module = Engine::GetInstance()->GetModuleManager()->GetModule<SceneModule>();
		scene_module->SetNextScene([scene_module] {scene_module->SetScene<PauseScene>(false); });
	}

	void LaunchDeath() {
		SceneModule* scene_module = Engine::GetInstance()->GetModuleManager()->GetModule<SceneModule>();
		scene_module->SetNextScene([scene_module] {scene_module->SetScene<DeathScene>(false); });
	}
};
