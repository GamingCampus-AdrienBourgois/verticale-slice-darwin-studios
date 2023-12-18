#pragma once
#include "Scene.h"
#include "Engine.h"
#include "WindowModule.h"
#include <functional>

class CreditsScene final : public Scene
{
public:
	CreditsScene() : Scene("CreditsScene")
	{
		SetTexture("background", "Assets/background/main_menu_background.png");
		SetBackground("background");

		SetTexture("texture_button_Quit", "Assets/button/buttonQuit.png");

		sf::Vector2u window_size = Engine::GetInstance()->GetModuleManager()->GetModule<WindowModule>()->GetWindow()->getSize();

		GameObject* quit_game_button = CreateSpriteButton_forMainMenu(ButtonType, "texture_button_Quit", Maths::Vector2f((window_size.x / 10) * 2, (window_size.y - window_size.y * 2 / 6)), Maths::Vector2f(window_size.x / 15 * 3, (((window_size.x / 15) * 3) * 168 / 448)), [this] {Engine::GetInstance()->Quit(); }, nullptr, "texture_button_Quit", Maths::Vector2f(448, 168), Maths::Vector2f(0, 24));
	}
};
