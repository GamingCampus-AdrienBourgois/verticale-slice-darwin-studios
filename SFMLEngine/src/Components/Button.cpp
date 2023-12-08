#include "Components/Button.h"
#include <iostream>
#include <Engine.h>
#include "Modules/SceneModule.h"
#include <fstream>


void Button::Execute() {
	if (is_clicked) {
		Scene* scene = Engine::GetInstance()->GetModuleManager()->GetModule<SceneModule>()->GetMainScene();
		if (GetOwner()->GetName() == "main_menu_play_button") {
			Scene* scene = Engine::GetInstance()->GetModuleManager()->GetModule<SceneModule>()->GetScene("SelectCapacityScene");
			Engine::GetInstance()->GetModuleManager()->GetModule<SceneModule>()->SetNextScene(scene);
		}
		else if (GetOwner()->GetName() == "main_menu_quit_button") {
			Engine::GetInstance()->Quit();
		}
		else if (GetOwner()->GetName() == "doll_button1" || GetOwner()->GetName() == "doll_button2" || GetOwner()->GetName() == "doll_button3") {
			bool have_capacity_button = false;
			for (GameObject* const& gameObject : *scene->GetGameObjects()) {
				if (gameObject->GetName() == "capacity_button") {
					have_capacity_button = true;
					break;
				}
			}
			if (!have_capacity_button) {
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

					while (std::getline(ifstrm, ligne))
					{
						size_t position = 0;
						size_t position_delimiter = ligne.find(delimiter);
						Capacity* capacity = new Capacity();
						capacity->SetName(ligne.substr(position, position_delimiter - 1));
						capacity->SetDescription(ligne.substr(position_delimiter + 2, ligne.find(std::string::npos)));
						scene->CreateButton(ButtonType, "capacity_button", Maths::Vector2f((window_size.x / (nb_ligne * 2 + nb_ligne - 1 + 16) * capacity_position), (window_size.y / 100 * 10)), sf::Color::Green,
							Maths::Vector2u(window_size.x / (nb_ligne * 2 + nb_ligne - 1 + 16) * 2, window_size.x / (nb_ligne * 2 + nb_ligne - 1 + 16) * 2), capacity);
						capacity_position += 3;
					}
					ifstrm.close();
				}
				else
				{
					std::cout << "failed to open the file" << std::endl;
				}

				GameObject* text_for_capacacity_name = scene->CreateText(TextType, "text_for_capacity_name", Maths::Vector2f(window_size.x / 2 - window_size.x / 4, (window_size.y / 100 * 25)), sf::Color::White, Maths::Vector2u(window_size.x / 4 * 2, (window_size.y / 100 * 5)), 40);
				GameObject* text_for_capacacity_description = scene->CreateText(TextType, "text_for_capacity_description", Maths::Vector2f(window_size.x / 2 - window_size.x / 4, (window_size.y / 100 * 40)), sf::Color::White, Maths::Vector2u(window_size.x / 4 * 2, (window_size.y / 100 * 5)), 30);
			}
		}
		else if (GetOwner()->GetName() == "capacity_button") {
			scene->FindGameObject("text_for_capacity_name")->GetComponent<TextRenderer>()->SetString(GetObject()->GetName());
			scene->FindGameObject("text_for_capacity_description")->GetComponent<TextRenderer>()->SetString(GetObject()->GetDescription());
		}
		else if (GetOwner()->GetName() == "launch_game_button") {
			Scene* scene = Engine::GetInstance()->GetModuleManager()->GetModule<SceneModule>()->GetScene("DefaultScene");
			Engine::GetInstance()->GetModuleManager()->GetModule<SceneModule>()->SetNextScene(scene);
		}
	}
}


void Button::Update(const float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input) {
	Execute();
}