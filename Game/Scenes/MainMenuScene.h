#pragma once
#include "Scene.h"

#include "Engine.h"
#include "WindowModule.h"

class MainMenuScene final : public Scene
{
public:
	MainMenuScene() : Scene("MainMenuScene")
	{
		SetTexture("background", "Assets/bg_MainMenu.png");
		SetBackground("background");
		SetFont("Font/UkrainianPrincess.ttf");


		sf::Vector2u window_size = Engine::GetInstance()->GetModuleManager()->GetModule<WindowModule>()->GetWindow()->getSize();

		GameObject* play_game_button = CreateButtonWithText(ButtonType, "main_menu_play_button", Maths::Vector2f((window_size.x / 2) - (window_size.x / 15), (window_size.y - window_size.y * 4/6)), sf::Color::Green, Maths::Vector2u(window_size.x / 15 * 2, window_size.y / 10), nullptr, "Play", sf::Color::White, 30);
		GameObject* option_game_button = CreateButtonWithText(ButtonType, "main_menu_option_button", Maths::Vector2f((window_size.x / 2) - (window_size.x / 15), (window_size.y - window_size.y * 3 / 6)), sf::Color::Blue, Maths::Vector2u(window_size.x / 15 * 2, window_size.y / 10), nullptr, "Option", sf::Color::White, 30);
		GameObject* credit_game_button = CreateButtonWithText(ButtonType, "main_menu_credit_button", Maths::Vector2f((window_size.x / 2) - (window_size.x / 15), (window_size.y - window_size.y * 2 / 6)), sf::Color::Blue, Maths::Vector2u(window_size.x / 15 * 2, window_size.y / 10), nullptr, "CREdit", sf::Color::White, 30);
		GameObject* quit_game_button = CreateButtonWithText(ButtonType, "main_menu_quit_button", Maths::Vector2f((window_size.x / 2) - (window_size.x / 15), (window_size.y - window_size.y * 1 / 6)), sf::Color::Red, Maths::Vector2u(window_size.x / 15 * 2, window_size.y / 10), nullptr, "Quit", sf::Color::White, 30);
	}
};