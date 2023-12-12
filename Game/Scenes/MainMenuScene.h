#pragma once
#include "Scene.h"

#include "Engine.h"
#include "WindowModule.h"
#include <functional>


class MainMenuScene final : public Scene
{
public:
	MainMenuScene() : Scene("MainMenuScene")
	{
		SetTexture("background", "Assets/background.png");
		SetBackground("background");

		sf::Vector2u window_size = Engine::GetInstance()->GetModuleManager()->GetModule<WindowModule>()->GetWindow()->getSize();

		GameObject* play_game_button = CreateButtonWithText(ButtonType, "main_menu_play_button", Maths::Vector2f((window_size.x / 2) - (window_size.x / 15), (window_size.y - window_size.y * 5 / 6)), sf::Color::Green, sf::Color::Black, sf::Color::White, sf::Color::Cyan, Maths::Vector2u(window_size.x / 15 * 2, window_size.y / 10), [this] {LaunchCapacityMenu(); }, nullptr, "Play", sf::Color::White, 30);
		GameObject* option_game_button = CreateButtonWithText(ButtonType, "main_menu_option_button", Maths::Vector2f((window_size.x / 2) - (window_size.x / 15), (window_size.y - window_size.y * 4 / 6)), sf::Color::Blue, sf::Color::Black, sf::Color::White, sf::Color::Cyan, Maths::Vector2u(window_size.x / 15 * 2, window_size.y / 10), [this] {LaunchCapacityMenu(); }, nullptr, "Option", sf::Color::White, 30);
		GameObject* credit_game_button = CreateButtonWithText(ButtonType, "main_menu_credit_button", Maths::Vector2f((window_size.x / 2) - (window_size.x / 15), (window_size.y - window_size.y * 3 / 6)), sf::Color::Blue, sf::Color::Black, sf::Color::White, sf::Color::Cyan, Maths::Vector2u(window_size.x / 15 * 2, window_size.y / 10), [this] {LaunchCapacityMenu(); }, nullptr, "Credit", sf::Color::White, 30);
		GameObject* quit_game_button = CreateButtonWithText(ButtonType, "main_menu_quit_button", Maths::Vector2f((window_size.x / 2) - (window_size.x / 15), (window_size.y - window_size.y * 1 / 6)), sf::Color::Red, sf::Color::Black, sf::Color::White, sf::Color::Cyan, Maths::Vector2u(window_size.x / 15 * 2, window_size.y / 10), [this] {Engine::GetInstance()->Quit(); }, nullptr, "Quit", sf::Color::White, 30);
	}

	void LaunchCapacityMenu() {
		Engine::GetInstance()->GetModuleManager()->GetModule<SceneModule>()->SetScene<SelectCapacityScene>();
	}

};