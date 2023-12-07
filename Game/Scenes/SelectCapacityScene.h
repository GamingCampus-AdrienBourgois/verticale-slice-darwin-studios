#pragma once

#include "Scene.h"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>

class SelectCapacityScene final : public Scene
{
public:
	SelectCapacityScene() : Scene("SelectCapacityScene")
	{
		sf::Vector2u window_size = Engine::GetInstance()->GetModuleManager()->GetModule<WindowModule>()->GetWindow()->getSize();

		std::string filename = "capacity.txt";
		std::ifstream ifstrm(filename);
		int nb_ligne = 0;
		int capacity_position = 8;

		if (ifstrm.is_open())
		{
			std::string ligne;
			while (std::getline(ifstrm, ligne)) {
				nb_ligne++;
			}
			ifstrm.clear();
			ifstrm.seekg(0, std::ios::beg);

			ligne = "";
			std::string delimiter = ":";
		
			while (std::getline(ifstrm,ligne))
			{
				size_t position = 0;
				size_t position_delimiter = ligne.find(delimiter);
				Capacity* capacity = new Capacity();
				capacity->SetName(ligne.substr(position, position_delimiter - 1));
				capacity->SetDescription(ligne.substr(position_delimiter + 2, ligne.find(std::string::npos)));
				CreateButton(ButtonType, "capacity_button", Maths::Vector2f((window_size.x / (nb_ligne * 2 + nb_ligne - 1 + 16) * capacity_position), (window_size.y / 100 * 10)), sf::Color::Green,
					Maths::Vector2u(window_size.x / (nb_ligne * 2 + nb_ligne - 1 + 16)*2, window_size.x / (nb_ligne * 2 + nb_ligne - 1 + 16) * 2), "", capacity);
				capacity_position += 3;
			}
			ifstrm.close();
		}
		else
		{
			std::cout << "failed to open the file"<< std::endl;
		}

		GameObject* text_for_capacacity_name = CreateText(TextType, "text_for_capacity_name", Maths::Vector2f(window_size.x / 2 - window_size.x / 4, (window_size.y / 100 * 25)), sf::Color::White, Maths::Vector2u(window_size.x / 4 * 2, (window_size.y / 100 * 5)), 40);
		GameObject* text_for_capacacity_description = CreateText(TextType, "text_for_capacity_description", Maths::Vector2f(window_size.x / 2 - window_size.x / 4, (window_size.y / 100 * 40)), sf::Color::White, Maths::Vector2u(window_size.x / 4 * 2, (window_size.y / 100 * 5)), 30);

		GameObject* doll_button1 = CreateButton(ButtonType, "doll_button1", Maths::Vector2f(window_size.x / 6, (window_size.y / 2)), sf::Color::Blue, Maths::Vector2u(window_size.x / 6, window_size.y / 3), "", nullptr);
		GameObject* doll_button2 = CreateButton(ButtonType, "doll_button2", Maths::Vector2f((window_size.x / 2) - (window_size.x / 6 / 2), (window_size.y / 2) ), sf::Color::Blue, Maths::Vector2u(window_size.x/6,window_size.y/3), "", nullptr);
		GameObject* doll_button3 = CreateButton(ButtonType, "doll_button3", Maths::Vector2f((window_size.x / 2) + (window_size.x / 6 ), (window_size.y / 2)), sf::Color::Blue, Maths::Vector2u(window_size.x / 6, window_size.y / 3), "", nullptr);
		
		GameObject* launch_game_button = CreateButton(ButtonType, "launch_game_button", Maths::Vector2f((window_size.x / 2) - (window_size.x / 15), (window_size.y - window_size.y / 100 * 10)), sf::Color::Red, Maths::Vector2u(window_size.x / 15 *2, window_size.y / 100 *6), "Lancer", nullptr);
	}
};