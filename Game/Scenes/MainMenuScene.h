
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
		SetTexture("background", "Assets/background/main_menu_background.png");
		SetBackground("background");

		SetTexture("texture_button_Play", "Assets/button/buttonPlay.png");
		SetTexture("texture_button_Options", "Assets/button/buttonOptions.png");
		SetTexture("texture_button_Credits", "Assets/button/buttonCredits.png");
		SetTexture("texture_button_Quit", "Assets/button/buttonQuit.png");

		sf::Vector2u window_size = Engine::GetInstance()->GetModuleManager()->GetModule<WindowModule>()->GetWindow()->getSize();

		//GameObject* play_game_button = CreateSpriteButtonWithText(ButtonType, "main_menu_play_button", Maths::Vector2f((window_size.x / 10) * 2, (window_size.y - window_size.y * 5 / 6)), Maths::Vector2f(window_size.x / 15 * 3, (((window_size.x / 15) * 3) * 168 / 448)), [this] {LaunchCapacityMenu(); }, nullptr, "texture_button", Maths::Vector2f(448, 168), Maths::Vector2f(0,24), "Jouer", sf::Color::Black, 50);
		//GameObject* option_game_button = CreateSpriteButtonWithText(ButtonType, "main_menu_option_button", Maths::Vector2f((window_size.x / 10) * 2, (window_size.y - window_size.y * 4 / 6)), Maths::Vector2f(window_size.x / 15 * 3, (((window_size.x / 15) * 3) * 168 / 448)), [] {}, nullptr, "texture_button", Maths::Vector2f(448, 168), Maths::Vector2f(0, 24), "Option", sf::Color::Black, 50);
		//GameObject* credit_game_button = CreateButtonWithText(ButtonType, "main_menu_credit_button", Maths::Vector2f((window_size.x / 2) - (window_size.x / 15), (window_size.y - window_size.y * 3 / 6)), sf::Color::Blue, sf::Color::Black, sf::Color::White, sf::Color::Cyan, Maths::Vector2u(window_size.x / 15 * 2, window_size.y / 10), [] {}, nullptr, "Credit", sf::Color::White, 30);
		//GameObject* quit_game_button = CreateButtonWithText(ButtonType, "main_menu_quit_button", Maths::Vector2f((window_size.x / 2) - (window_size.x / 15), (window_size.y - window_size.y * 1 / 6)), sf::Color::Red, sf::Color::Black, sf::Color::White, sf::Color::Cyan, Maths::Vector2u(window_size.x / 15 * 2, window_size.y / 10), [this] {Engine::GetInstance()->Quit(); }, nullptr, "Quit", sf::Color::White, 30);
	
		GameObject* play_game_button = CreateSpriteButton_forMainMenu(ButtonType, "main_menu_play_button", Maths::Vector2f((window_size.x / 10) * 2, (window_size.y - window_size.y * 5 / 6)), Maths::Vector2f(window_size.x / 15 * 3, (((window_size.x / 15) * 3) * 168 / 448)), [this] {LaunchCapacityMenu(); }, nullptr, "texture_button_Play", Maths::Vector2f(448, 168), Maths::Vector2f(0, 24));
		GameObject* option_game_button = CreateSpriteButton_forMainMenu(ButtonType, "main_menu_option_button", Maths::Vector2f((window_size.x / 10) * 2, (window_size.y - window_size.y * 4 / 6)), Maths::Vector2f(window_size.x / 15 * 3, (((window_size.x / 15) * 3) * 168 / 448)), [] {}, nullptr, "texture_button_Options", Maths::Vector2f(448, 168), Maths::Vector2f(0, 24));
		GameObject* credit_game_button = CreateSpriteButton_forMainMenu(ButtonType, "main_menu_credits_button", Maths::Vector2f((window_size.x / 10) * 2, (window_size.y - window_size.y * 3 / 6)), Maths::Vector2f(window_size.x / 15 * 3, (((window_size.x / 15) * 3) * 168 / 448)), [] {}, nullptr, "texture_button_Credits", Maths::Vector2f(448, 168), Maths::Vector2f(0, 24));
		GameObject* quit_game_button = CreateSpriteButton_forMainMenu(ButtonType, "main_menu_quit_button", Maths::Vector2f((window_size.x / 10) * 2, (window_size.y - window_size.y * 2 / 6)), Maths::Vector2f(window_size.x / 15 * 3, (((window_size.x / 15) * 3) * 168 / 448)), [this] {Engine::GetInstance()->Quit(); }, nullptr, "texture_button_Quit", Maths::Vector2f(448, 168), Maths::Vector2f(0, 24));
		
	
	}

	void LaunchCapacityMenu() {
		SceneModule* scene_module = Engine::GetInstance()->GetModuleManager()->GetModule<SceneModule>();
		scene_module->SetNextScene([scene_module] {scene_module->SetScene<SelectCapacityScene>(); });
	}

};