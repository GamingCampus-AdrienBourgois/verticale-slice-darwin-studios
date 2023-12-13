#include "Components/Button.h"
#include <iostream>
#include <Engine.h>
#include "Modules/SceneModule.h"
#include <fstream>
#include <sstream>


void Button::Execute() {
	if (is_clicked) {
		callback();
	}
}


void Button::Update(const float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input) {
	CheckHover();
	Execute();
}

void Button::CheckHover() {
	sf::Vector2i mousePos = sf::Mouse::getPosition(*Engine::GetInstance()->GetModuleManager()->GetModule<WindowModule>()->GetWindow());
	RectangleShapeRenderer* rectangleShapeRenderer = GetOwner()->GetComponent<RectangleShapeRenderer>();

	if (!is_clicked && !is_disabled) {
		if (rectangleShapeRenderer->GetShape()->getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
			rectangleShapeRenderer->SetColor(rectangleShapeRenderer->GetHoverColor());
		}
		else {
			rectangleShapeRenderer->SetColor(rectangleShapeRenderer->GetDefaultColor());
		}
	}
}


void Button::DollSelectCapacity() {
	Scene* scene = Engine::GetInstance()->GetModuleManager()->GetModule<SceneModule>()->GetMainScene();
	bool have_capacity_button = false;
	for (GameObject* const& gameObject : *scene->GetGameObjects()) {
		if (gameObject->GetName() == "capacity_button") {
			have_capacity_button = true;
			break;
		}
	}
	if (!have_capacity_button) {
		sf::Vector2u window_size = Engine::GetInstance()->GetModuleManager()->GetModule<WindowModule>()->GetWindow()->getSize();

		std::ifstream file("capacity.csv");

		if (!file.is_open()) {
			std::cerr << "Error opening file." << std::endl;
		}

		int nb_ligne = 0;
		int num_capacity = 1;
		std::string line;

		while (std::getline(file, line)) {
			nb_ligne++;
		}

		file.clear();
		file.seekg(0, std::ios::beg);

		while (std::getline(file, line)) {
			std::vector<std::string> row;
			std::stringstream lineStream(line);
			std::string cell;

			while (std::getline(lineStream, cell, ',')) {
				row.push_back(cell);
			}

			Capacity* capacity = new Capacity();
			capacity->SetName(row[0]);
			capacity->SetDescription(row[1]);
			scene->SetTexture("icon_" + std::to_string(num_capacity), "Assets/icon_capacity/" + row[2]);
			GameObject* button = scene->CreateSpriteButton(ButtonType, "capacity_button", Maths::Vector2f((window_size.x / 2) - (window_size.x / 15 / 2 * (nb_ligne % 2)) - (window_size.x / 15 * (nb_ligne / 2)) - (((window_size.x / 15) / 2) * (nb_ligne - 1) / 2) + (window_size.x / 15 * (num_capacity - 1)) + ((window_size.x / 15) / 2 * (num_capacity - 1)), (window_size.y / 100 * 10)),
				sf::Color::White, sf::Color::Black, sf::Color::Green, sf::Color::Red,
				Maths::Vector2u(window_size.x / 15, window_size.x / 15), [] {}, capacity, "icon_" + std::to_string(num_capacity));
			button->GetComponent<Button>()->SetCallback(std::bind(&Button::SelectCapacity, button->GetComponent<Button>()));
			num_capacity++;
		}

		file.close();

		GameObject* text_for_capacacity_name = scene->CreateText(TextType, "text_for_capacity_name", Maths::Vector2f(window_size.x / 2 - window_size.x / 4, (window_size.y / 100 * 25)), sf::Color::White, Maths::Vector2u(window_size.x / 4 * 2, (window_size.y / 100 * 10)), 40);
		GameObject* text_for_capacacity_description = scene->CreateText(TextType, "text_for_capacity_description", Maths::Vector2f(window_size.x / 2 - window_size.x / 4, (window_size.y / 100 * 40)), sf::Color::White, Maths::Vector2u(window_size.x / 4 * 2, (window_size.y / 100 * 5)), 30);
	}
	else {
		for (GameObject* const& gameObject : *scene->GetGameObjects()) {
			if (gameObject->GetName() == "capacity_button") {
				if(gameObject->GetComponent<Button>()->is_selected_by != GetOwner() && gameObject->GetComponent<Button>()->is_selected_by != nullptr){
					gameObject->GetComponent<RectangleShapeRenderer>()->SetColor(sf::Color(128, 128, 128, 255));
					gameObject->GetComponent<Button>()->is_disabled = true;
				}
				else if(gameObject->GetComponent<Button>()->is_selected_by == GetOwner()){
					gameObject->GetComponent<RectangleShapeRenderer>()->SetColor(gameObject->GetComponent<RectangleShapeRenderer>()->GetClickColor());
					gameObject->GetComponent<Button>()->is_disabled = false;
				}
				else {
					/*gameObject->GetComponent<RectangleShapeRenderer>()->SetColor(gameObject->GetComponent<RectangleShapeRenderer>()->GetDefaultColor());*/
					gameObject->GetComponent<Button>()->is_disabled = false;
				}
			}
		}
	}
}

void Button::SelectCapacity() {
	if (is_selected_by == nullptr) {
		Scene* scene = Engine::GetInstance()->GetModuleManager()->GetModule<SceneModule>()->GetMainScene();
		scene->FindGameObject("text_for_capacity_name")->GetComponent<TextRenderer>()->SetString(GetObject()->GetName());
		scene->FindGameObject("text_for_capacity_description")->GetComponent<TextRenderer>()->SetString(GetObject()->GetDescription());
		int capacity_selected = 0;
		for (GameObject* const& gameObject : *scene->GetGameObjects()) {
			if ((gameObject->GetName() == "doll_button1" || gameObject->GetName() == "doll_button2" || gameObject->GetName() == "doll_button3")){
				if (gameObject->GetComponent<Button>()->is_clicked) {
					if (gameObject->GetComponent<Button>()->has_select != nullptr) {
						gameObject->GetComponent<Button>()->has_select->GetComponent<Button>()->is_selected_by = nullptr;
					}
					gameObject->GetComponent<Button>()->has_select = GetOwner();
					is_selected_by = gameObject;
				}
				if (gameObject->GetComponent<Button>()->has_select != nullptr) {
					capacity_selected++;
				}
			}
		}
		if (capacity_selected == 3) {
			scene->FindGameObject("launch_game_button")->GetComponent<Button>()->is_disabled = false;
		}
	}
}