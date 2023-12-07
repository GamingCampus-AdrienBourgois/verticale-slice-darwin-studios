#pragma once
#include "Scene.h"

#include "Engine.h"
#include "WindowModule.h"

class MainMenuScene final : public Scene
{
public:
	MainMenuScene() : Scene("MainMenuScene")
	{
		sf::Vector2u window_size = Engine::GetInstance()->GetModuleManager()->GetModule<WindowModule>()->GetWindow()->getSize();

		GameObject* play_game_button = CreateButton(ButtonName, Maths::Vector2f((window_size.x / 2) - (window_size.x / 15), (window_size.y - window_size.y * 5/6)), sf::Color::Green, Maths::Vector2u(window_size.x / 15 * 2, window_size.y / 10), "play_game_button", "Play");
		GameObject* option_game_button = CreateButton(ButtonName, Maths::Vector2f((window_size.x / 2) - (window_size.x / 15), (window_size.y - window_size.y * 4 / 6)), sf::Color::Blue, Maths::Vector2u(window_size.x / 15 * 2, window_size.y / 10), "option_game_button", "Option");
		GameObject* credit_game_button = CreateButton(ButtonName, Maths::Vector2f((window_size.x / 2) - (window_size.x / 15), (window_size.y - window_size.y * 3 / 6)), sf::Color::Blue, Maths::Vector2u(window_size.x / 15 * 2, window_size.y / 10), "credit_game_button", "Credit");
		GameObject* quit_game_button = CreateButton(ButtonName, Maths::Vector2f((window_size.x / 2) - (window_size.x / 15), (window_size.y - window_size.y * 1 / 6)), sf::Color::Red, Maths::Vector2u(window_size.x / 15 * 2, window_size.y / 10), "quit_game_button", "Quit");
	}
};