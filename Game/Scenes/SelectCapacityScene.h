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

		GameObject* doll_button1 = CreateButton(ButtonType, "doll_button1", Maths::Vector2f(window_size.x / 6, (window_size.y / 2)), sf::Color::Blue, Maths::Vector2u(window_size.x / 6, window_size.y / 3), nullptr);
		GameObject* doll_button2 = CreateButton(ButtonType, "doll_button2", Maths::Vector2f((window_size.x / 2) - (window_size.x / 6 / 2), (window_size.y / 2) ), sf::Color::Blue, Maths::Vector2u(window_size.x/6,window_size.y/3), nullptr);
		GameObject* doll_button3 = CreateButton(ButtonType, "doll_button3", Maths::Vector2f((window_size.x / 2) + (window_size.x / 6 ), (window_size.y / 2)), sf::Color::Blue, Maths::Vector2u(window_size.x / 6, window_size.y / 3), nullptr);
		
		GameObject* launch_game_button = CreateButtonWithText(ButtonType, "launch_game_button", Maths::Vector2f((window_size.x / 2) - (window_size.x / 15), (window_size.y - window_size.y / 100 * 10)), sf::Color::Red, Maths::Vector2u(window_size.x / 15 *2, window_size.y / 100 *6), nullptr, "Lancer", sf::Color::White, 30);
	}
};