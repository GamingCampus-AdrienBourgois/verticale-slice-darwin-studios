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




		sf::Vector2u window_size = Engine::GetInstance()->GetModuleManager()->GetModule<WindowModule>()->GetWindow()->getSize();

		GameObject* doll_button1 = CreateButton(ButtonType, "doll_button1", Maths::Vector2f(window_size.x / 6, (window_size.y / 2)), sf::Color::Blue, sf::Color::Black, sf::Color::Yellow, sf::Color::Magenta, Maths::Vector2u(window_size.x / 6, window_size.y / 3), [] {}, nullptr);
		doll_button1->GetComponent<Button>()->SetCallback(std::bind(&Button::DollSelectCapacity, doll_button1->GetComponent<Button>()));
		GameObject* doll_button2 = CreateButton(ButtonType, "doll_button2", Maths::Vector2f((window_size.x / 2) - (window_size.x / 6 / 2), (window_size.y / 2) ), sf::Color::Blue, sf::Color::Black, sf::Color::Yellow, sf::Color::Magenta, Maths::Vector2u(window_size.x/6,window_size.y/3), [] {}, nullptr);
		doll_button2->GetComponent<Button>()->SetCallback(std::bind(&Button::DollSelectCapacity, doll_button2->GetComponent<Button>()));
		GameObject* doll_button3 = CreateButton(ButtonType, "doll_button3", Maths::Vector2f((window_size.x / 2) + (window_size.x / 6 ), (window_size.y / 2)), sf::Color::Blue, sf::Color::Black, sf::Color::Yellow, sf::Color::Magenta, Maths::Vector2u(window_size.x / 6, window_size.y / 3), [] {}, nullptr);
		doll_button3->GetComponent<Button>()->SetCallback(std::bind(&Button::DollSelectCapacity, doll_button3->GetComponent<Button>()));
		
		GameObject* launch_game_button = CreateSpriteButton_forMainMenu(ButtonType, "launch_game_button", Maths::Vector2f((window_size.x / 2) - (window_size.x / 15), (window_size.y - window_size.y / 100 * 15)), Maths::Vector2f(window_size.x / 15 * 2,((((window_size.x / 15 * 2) * 168 ) / 448 ))), [this] {LauchGame(); }, nullptr, "texture_launch_capacity_button", Maths::Vector2f(448,168), Maths::Vector2f(0,24));
		launch_game_button->GetComponent<RectangleShapeRenderer>()->SetColor(launch_game_button->GetComponent<RectangleShapeRenderer>()->GetDisabledColor());
		launch_game_button->GetComponent<Button>()->is_disabled = true;
		if (launch_game_button->GetComponent<SpriteRenderer>() != nullptr) {
			launch_game_button->GetComponent<SpriteRenderer>()->SetNextSpriteRect(3);
		}
		std::cout << launch_game_button->GetComponent<Button>()->is_disabled << std::endl;
	}

	void LauchGame() {
		Scene* scene = Engine::GetInstance()->GetModuleManager()->GetModule<SceneModule>()->GetMainScene();
		std::vector<Capacity>* params = new std::vector<Capacity>;
		params->push_back(*scene->FindGameObject("doll_button1")->GetComponent<Button>()->has_select->GetComponent<Button>()->GetObject());
		params->push_back(*scene->FindGameObject("doll_button2")->GetComponent<Button>()->has_select->GetComponent<Button>()->GetObject());
		params->push_back(*scene->FindGameObject("doll_button3")->GetComponent<Button>()->has_select->GetComponent<Button>()->GetObject());
		Engine::GetInstance()->GetModuleManager()->GetModule<SceneModule>()->SetSceneWithParams<DefaultScene>(true, params);
	}
};