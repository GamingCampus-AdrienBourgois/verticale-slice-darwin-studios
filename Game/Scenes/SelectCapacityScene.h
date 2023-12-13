#pragma once

#include "Scene.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class SelectCapacityScene final : public Scene
{
public:
	SelectCapacityScene() : Scene("SelectCapacityScene")
	{
		SetTexture("background", "Assets/background.png");
		SetBackground("background");

		sf::Vector2u window_size = Engine::GetInstance()->GetModuleManager()->GetModule<WindowModule>()->GetWindow()->getSize();

		GameObject* doll_button1 = CreateButton(ButtonType, "doll_button1", Maths::Vector2f(window_size.x / 6, (window_size.y / 2)), sf::Color::Blue, sf::Color::Black, sf::Color::Yellow, sf::Color::Magenta, Maths::Vector2u(window_size.x / 6, window_size.y / 3), [] {}, nullptr);
		doll_button1->GetComponent<Button>()->SetCallback(std::bind(&Button::DollSelectCapacity, doll_button1->GetComponent<Button>()));
		GameObject* doll_button2 = CreateButton(ButtonType, "doll_button2", Maths::Vector2f((window_size.x / 2) - (window_size.x / 6 / 2), (window_size.y / 2) ), sf::Color::Blue, sf::Color::Black, sf::Color::Yellow, sf::Color::Magenta, Maths::Vector2u(window_size.x/6,window_size.y/3), [] {}, nullptr);
		doll_button2->GetComponent<Button>()->SetCallback(std::bind(&Button::DollSelectCapacity, doll_button2->GetComponent<Button>()));
		GameObject* doll_button3 = CreateButton(ButtonType, "doll_button3", Maths::Vector2f((window_size.x / 2) + (window_size.x / 6 ), (window_size.y / 2)), sf::Color::Blue, sf::Color::Black, sf::Color::Yellow, sf::Color::Magenta, Maths::Vector2u(window_size.x / 6, window_size.y / 3), [] {}, nullptr);
		doll_button3->GetComponent<Button>()->SetCallback(std::bind(&Button::DollSelectCapacity, doll_button3->GetComponent<Button>()));
		
		GameObject* launch_game_button = CreateButtonWithText(ButtonType, "launch_game_button", Maths::Vector2f((window_size.x / 2) - (window_size.x / 15), (window_size.y - window_size.y / 100 * 10)), sf::Color::Red, sf::Color::Black, sf::Color::Blue, sf::Color::Cyan, Maths::Vector2u(window_size.x / 15 *2, window_size.y / 100 *6), [this] {LauchGame(); }, nullptr, "Lancer", sf::Color::White, 30);
		launch_game_button->GetComponent<RectangleShapeRenderer>()->SetColor(sf::Color(128, 128, 128, 255));
		launch_game_button->GetComponent<Button>()->is_disabled = true;
		std::cout << launch_game_button->GetComponent<Button>()->is_disabled << std::endl;
	}

	void LauchGame() {
		Scene* scene = Engine::GetInstance()->GetModuleManager()->GetModule<SceneModule>()->GetMainScene();
		std::vector<Capacity> params;
		params.push_back(*scene->FindGameObject("doll_button1")->GetComponent<Button>()->has_select->GetComponent<Button>()->GetObject());
		params.push_back(*scene->FindGameObject("doll_button2")->GetComponent<Button>()->has_select->GetComponent<Button>()->GetObject());
		params.push_back(*scene->FindGameObject("doll_button3")->GetComponent<Button>()->has_select->GetComponent<Button>()->GetObject());
		Engine::GetInstance()->GetModuleManager()->GetModule<SceneModule>()->SetSceneWithParams<DefaultScene>(true, params);
	}
};