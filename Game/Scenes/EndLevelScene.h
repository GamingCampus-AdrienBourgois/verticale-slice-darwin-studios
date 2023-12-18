#pragma once
#include "Scene.h"
#include "RectangleShapeRenderer.h"
#include "Engine.h"
#include "WindowModule.h"

class EndLevelScene final : public Scene
{
public:
	sf::Vector2f window_size = Engine::GetInstance()->GetModuleManager()->GetModule<WindowModule>()->GetWindowSize();


	EndLevelScene() : Scene("EndLevelScene") {
		CreateShapeAlone(ShapeType, "BackgroundScene", Maths::Vector2f(0, 0), sf::Color(128, 128, 128, 12), window_size);

		GameObject* main_menu_button = CreateButtonWithText(ButtonType, "main-menu_button", Maths::Vector2f(120, 120), sf::Color::Blue, sf::Color::Yellow, sf::Color::Yellow, sf::Color::Magenta, Maths::Vector2u(150, 120), [this] {Engine::GetInstance()->Quit(); }, nullptr, "main_menu", sf::Color::Red, 3);
		GameObject* next_level_button = CreateButtonWithText(ButtonType, "main-next_level_button", Maths::Vector2f(220, 220), sf::Color::Blue, sf::Color::Yellow, sf::Color::Yellow, sf::Color::Magenta, Maths::Vector2u(150, 120), [this] {Engine::GetInstance()->Quit(); }, nullptr, "next_level", sf::Color::Red, 3);

 	}
};