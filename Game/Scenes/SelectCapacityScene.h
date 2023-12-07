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
			ifstrm.clear(); // Effacer les indicateurs d'état
			ifstrm.seekg(0, std::ios::beg);

			ligne = "";
			std::string delimiter = ":";
		
			while (std::getline(ifstrm,ligne))
			{
				size_t position = 0;
				size_t position_delimiter = ligne.find(delimiter);
				CreateButton(ButtonName, Maths::Vector2f((window_size.x / (nb_ligne*2 + nb_ligne-1 + 16) * capacity_position), (window_size.y / 100 *10)), sf::Color::Green, Maths::Vector2u(window_size.x / (nb_ligne * 2 + nb_ligne - 1 + 16)*2, window_size.x / (nb_ligne * 2 + nb_ligne - 1 + 16) * 2), "capacity_button", "");
				capacity_position += 3;
			}
			ifstrm.close();
		}
		else
		{
			std::cout << "failed to open the file"<< std::endl;
		}

		GameObject* doll_button1 = CreateButton(ButtonName, Maths::Vector2f(window_size.x / 6, (window_size.y / 2)), sf::Color::Blue, Maths::Vector2u(window_size.x / 6, window_size.y / 3), "doll_button1", "");
		GameObject* doll_button2 = CreateButton(ButtonName, Maths::Vector2f((window_size.x / 2) - (window_size.x / 6 / 2), (window_size.y / 2) ), sf::Color::Blue, Maths::Vector2u(window_size.x/6,window_size.y/3), "doll_button2", "");
		GameObject* doll_button3 = CreateButton(ButtonName, Maths::Vector2f((window_size.x / 2) + (window_size.x / 6 ), (window_size.y / 2)), sf::Color::Blue, Maths::Vector2u(window_size.x / 6, window_size.y / 3), "doll_button3", "");
		
		GameObject* launch_game_button = CreateButton(ButtonName, Maths::Vector2f((window_size.x / 2) - (window_size.x / 15), (window_size.y - window_size.y / 100 * 10)), sf::Color::Red, Maths::Vector2u(window_size.x / 15 *2, window_size.y / 100 *6), "launch_game_button", "Lancer");
	}
};