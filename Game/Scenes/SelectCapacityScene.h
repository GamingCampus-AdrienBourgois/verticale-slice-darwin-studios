#pragma once

#include "Scene.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class SelectCapacityScene final : public Scene
{
public:
	SelectCapacityScene() : Scene("SelectCapacityScene")
	{
		SetTexture("background", "Assets/background/capacity_background.png");
		SetBackground("background");
		SetFont("Font/UkrainianPrincess.ttf");
		SetTexture("texture_launch_capacity_button", "Assets/button/capacity_launch_button.png");
		SetTexture("texture_zarya_button", "Assets/button/zarya_button.png");
		SetTexture("texture_zvezda_button", "Assets/button/zvezda_button.png");
		SetTexture("texture_zwezda_button", "Assets/button/zwezda_button.png");
		SetTexture("texture_map_button", "Assets/button/map_button.png");

		sf::Vector2u window_size = Engine::GetInstance()->GetModuleManager()->GetModule<WindowModule>()->GetWindow()->getSize();

		GameObject* doll_button1 = CreateSpriteButton_forMainMenu(ButtonType, "doll_button1", Maths::Vector2f(window_size.x / 2 - (window_size.x / 10 * 2.5), (window_size.y / 2)), Maths::Vector2f(window_size.x / 10, (((window_size.x / 10) * 161) / 82)), [] {}, nullptr, "texture_zarya_button", Maths::Vector2f(82, 161), Maths::Vector2f(0, 15));
		doll_button1->GetComponent<Button>()->SetCallback(std::bind(&Button::DollSelectCapacity, doll_button1->GetComponent<Button>()));
		GameObject* doll_button2 = CreateSpriteButton_forMainMenu(ButtonType, "doll_button2", Maths::Vector2f((window_size.x / 2 - (window_size.x / 10 * 0.5)), (window_size.y / 2) ), Maths::Vector2f(window_size.x / 10, (((window_size.x / 10) * 161) / 82)), [] {}, nullptr, "texture_zvezda_button", Maths::Vector2f(82, 161), Maths::Vector2f(0, 15));
		doll_button2->GetComponent<Button>()->SetCallback(std::bind(&Button::DollSelectCapacity, doll_button2->GetComponent<Button>()));
		GameObject* doll_button3 = CreateSpriteButton_forMainMenu(ButtonType, "doll_button3", Maths::Vector2f((window_size.x / 2  + (window_size.x / 10 * 1.5)), (window_size.y / 2)), Maths::Vector2f(window_size.x / 10, (((window_size.x / 10) * 161) / 82)), [] {}, nullptr, "texture_zwezda_button", Maths::Vector2f(82, 161), Maths::Vector2f(0, 15));
		doll_button3->GetComponent<Button>()->SetCallback(std::bind(&Button::DollSelectCapacity, doll_button3->GetComponent<Button>()));
		
		GameObject* launch_game_button = CreateSpriteButton_forMainMenu(ButtonType, "launch_game_button", Maths::Vector2f((window_size.x / 2) - (window_size.x / 15), (window_size.y - window_size.y / 100 * 15)), Maths::Vector2f(window_size.x / 15 * 2,((((window_size.x / 15 * 2) * 168 ) / 448 ))), [this] {LauchGame(); }, nullptr, "texture_launch_capacity_button", Maths::Vector2f(448,168), Maths::Vector2f(0,24));
		launch_game_button->GetComponent<RectangleShapeRenderer>()->SetColor(launch_game_button->GetComponent<RectangleShapeRenderer>()->GetDisabledColor());
		launch_game_button->GetComponent<Button>()->is_disabled = true;
		if (launch_game_button->GetComponent<SpriteRenderer>() != nullptr) {
			launch_game_button->GetComponent<SpriteRenderer>()->SetNextSpriteRect(3);
		}

		GameObject* map_button = CreateSpriteButton_forMainMenu(ButtonType, "map_button", Maths::Vector2f(window_size.x /50, window_size.y / 50), Maths::Vector2f(window_size.x / 20 , ((((window_size.x / 20) * 161) / 144))), [] {}, nullptr, "texture_map_button", Maths::Vector2f(144, 161), Maths::Vector2f(0, 15));

	}

	void LauchGame() {
		Scene* scene = Engine::GetInstance()->GetModuleManager()->GetModule<SceneModule>()->GetMainScene();
		std::vector<Capacity> params;
		params.push_back(*scene->FindGameObject("doll_button1")->GetComponent<Button>()->has_select->GetComponent<Button>()->GetObject());
		params.push_back(*scene->FindGameObject("doll_button2")->GetComponent<Button>()->has_select->GetComponent<Button>()->GetObject());
		params.push_back(*scene->FindGameObject("doll_button3")->GetComponent<Button>()->has_select->GetComponent<Button>()->GetObject());
		SceneModule* scene_module = Engine::GetInstance()->GetModuleManager()->GetModule<SceneModule>();
		scene_module->SetNextScene([scene_module, params] {scene_module->SetSceneWithParams<DefaultScene>(true, params); });
	}
};