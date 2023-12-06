#pragma once
#include "RectangleShapeRenderer.h"
#include "Scene.h"
#include "SquareCollider.h"
#include "Button.h"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>

class SelectCapacityScene final : public Scene
{
public:
	SelectCapacityScene() : Scene("SelectCapacityScene")
	{
		SetFont("Font/arial.ttf");

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

	GameObject* CreateButton(const ObjectName& _name, Maths::Vector2f _position, const sf::Color _color, Maths::Vector2u size, std::string button_name, std::string button_text)
	{
		GameObject* game_object = CreateGameObject(_name);
		game_object->SetPosition( _position);

		SquareCollider* square_collider = game_object->CreateComponent<SquareCollider>();
		square_collider->SetWidth(20.f);
		square_collider->SetHeight(20.f);

		RectangleShapeRenderer* shape_renderer = game_object->CreateComponent<RectangleShapeRenderer>();
		shape_renderer->SetColor(_color);
		shape_renderer->SetSize(Maths::Vector2f(size.x, size.y));

		Button* button = game_object->CreateComponent<Button>();
		button->SetName(button_name);
		button->SetText(button_text);

		return game_object;
	}

	int SetFont(std::string chemin_font) {
		if (!GetFont()->loadFromFile(chemin_font)) {
			return 0;
		}
		return 1;
	}
};