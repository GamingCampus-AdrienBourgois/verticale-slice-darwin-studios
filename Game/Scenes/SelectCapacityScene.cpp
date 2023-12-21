#include "SelectCapacityScene.h"

#include "Engine.h"
#include "LaunchFunction.h"
#include "WindowModule.h"
#include <iostream>

#include "DefaultScene.h"
#include "MainMenuScene.h"
#include "MapScene.h"
#include "TransitionScene.h"

#include <fstream>
#include <sstream>

SelectCapacityScene::SelectCapacityScene() : Scene("SelectCapacityScene", [] {})
{
	Engine::SetMusicState(true);
	/*if (!music.openFromFile("Assets/Sons/musique_level_3.ogg")) {
		std::cout << "La musique ne charge pas" << std::endl;
	}

	music.setLoop(true);
	music.setVolume(100.f);
	music.play();*/

	SetTexture("background", "Assets/background/capacity_background.png");
	SetBackground("background");
	SetFont("Font/UkrainianPrincess.ttf");
	SetTexture("texture_launch_capacity_button", "Assets/button/capacity_launch_button.png");
	SetTexture("texture_zarya_button", "Assets/button/zarya_button.png");
	SetTexture("texture_zvezda_button", "Assets/button/zvezda_button.png");
	SetTexture("texture_zwezda_button", "Assets/button/zwezda_button.png");
	SetTexture("texture_map_button", "Assets/button/map_button.png");
	SetTexture("texture_return_button", "Assets/button/return_button.png");

	sf::Vector2f window_size = Engine::GetInstance()->GetModuleManager()->GetModule<WindowModule>()->GetWindowSize();

	GameObject* doll_button1 = CreateSpriteButton_forMainMenu(ButtonType, "doll_button1", Maths::Vector2f(window_size.x / 2 - (window_size.x / 10 * 2.5), (window_size.y / 2)), Maths::Vector2f(window_size.x / 10, (((window_size.x / 10) * 161) / 82)), [] {}, nullptr, "texture_zarya_button", Maths::Vector2f(82, 161), Maths::Vector2f(0, 15));
	doll_button1->GetComponent<Button>()->SetCallback(std::bind(&Button::DollSelectCapacity, doll_button1->GetComponent<Button>()));
	GameObject* doll_button2 = CreateSpriteButton_forMainMenu(ButtonType, "doll_button2", Maths::Vector2f((window_size.x / 2 - (window_size.x / 10 * 0.5)), (window_size.y / 2)), Maths::Vector2f(window_size.x / 10, (((window_size.x / 10) * 161) / 82)), [] {}, nullptr, "texture_zvezda_button", Maths::Vector2f(82, 161), Maths::Vector2f(0, 15));
	doll_button2->GetComponent<Button>()->SetCallback(std::bind(&Button::DollSelectCapacity, doll_button2->GetComponent<Button>()));
	GameObject* doll_button3 = CreateSpriteButton_forMainMenu(ButtonType, "doll_button3", Maths::Vector2f((window_size.x / 2 + (window_size.x / 10 * 1.5)), (window_size.y / 2)), Maths::Vector2f(window_size.x / 10, (((window_size.x / 10) * 161) / 82)), [] {}, nullptr, "texture_zwezda_button", Maths::Vector2f(82, 161), Maths::Vector2f(0, 15));
	doll_button3->GetComponent<Button>()->SetCallback(std::bind(&Button::DollSelectCapacity, doll_button3->GetComponent<Button>()));


	GameObject* launch_game_button = CreateSpriteButton_forMainMenu(ButtonType, "launch_game_button", Maths::Vector2f((window_size.x / 2) - (window_size.x / 15), (window_size.y - window_size.y / 100 * 15)), Maths::Vector2f(window_size.x / 15 * 2, ((((window_size.x / 15 * 2) * 168) / 448))), [this] {callbackPlayButton(); music.stop(); }, nullptr, "texture_launch_capacity_button", Maths::Vector2f(448, 168), Maths::Vector2f(0, 24));
	launch_game_button->GetComponent<RectangleShapeRenderer>()->SetColor(launch_game_button->GetComponent<RectangleShapeRenderer>()->GetDisabledColor());
	launch_game_button->GetComponent<Button>()->is_disabled = true;
	if (launch_game_button->GetComponent<SpriteRenderer>() != nullptr) {
		launch_game_button->GetComponent<SpriteRenderer>()->SetNextSpriteRect(3);
	}

	GameObject* map_button = CreateSpriteButton_forMainMenu(ButtonType, "map_button", Maths::Vector2f(window_size.x / 50, window_size.y / 50), Maths::Vector2f(window_size.x / 20, ((((window_size.x / 20) * 161) / 144))), [this] {LaunchFunction::LaunchScene<MapScene>(); }, nullptr, "texture_map_button", Maths::Vector2f(144, 161), Maths::Vector2f(0, 15));
	GameObject* return_button = CreateSpriteButton_forMainMenu(ButtonType, "return_button", Maths::Vector2f(window_size.x / 50, window_size.y - window_size.y / 50 - 144), Maths::Vector2f(window_size.x / 20, ((((window_size.x / 20) * 161) / 144))), [this] {LaunchFunction::LaunchScene<MainMenuScene>(); }, nullptr, "texture_return_button", Maths::Vector2f(144, 161), Maths::Vector2f(0, 15));



  if (!map_button || !return_button)
	{
		music.stop();
	}
}

void SelectCapacityScene::callbackPlayButton() {

	std::vector<Capacity> capacities;
	capacities.push_back(*FindGameObject("doll_button1")->GetComponent<Button>()->has_select->GetComponent<Button>()->GetObject());
	capacities.push_back(*FindGameObject("doll_button2")->GetComponent<Button>()->has_select->GetComponent<Button>()->GetObject());
	capacities.push_back(*FindGameObject("doll_button3")->GetComponent<Button>()->has_select->GetComponent<Button>()->GetObject());

	LaunchFunction::LaunchSceneParams<TransitionScene>(capacities);
}


//SelectCapacityScene::SelectCapacityScene(int num_poupee, std::vector<Capacity> _capacitys) : Scene("SelectCapacityScene", [] {})
//{
//	SetTexture("background", "Assets/background/capacity_background.png");
//	SetBackground("background");
//	SetFont("Font/UkrainianPrincess.ttf");
//	SetTexture("texture_launch_capacity_button", "Assets/button/capacity_launch_button.png");
//	SetTexture("texture_zarya_button", "Assets/button/zarya_button.png");
//	SetTexture("texture_zvezda_button", "Assets/button/zvezda_button.png");
//	SetTexture("texture_zwezda_button", "Assets/button/zwezda_button.png");
//	SetTexture("texture_map_button", "Assets/button/map_button.png");
//	SetTexture("texture_return_button", "Assets/button/return_button.png");
//
//	sf::Vector2u window_size = Engine::GetInstance()->GetModuleManager()->GetModule<WindowModule>()->GetWindow()->getSize();
//
//	GameObject* doll_button1 = CreateSpriteButton_forMainMenu(ButtonType, "doll_button1", Maths::Vector2f(window_size.x / 2 - (window_size.x / 10 * 2.5), (window_size.y / 2)), Maths::Vector2f(window_size.x / 10, (((window_size.x / 10) * 161) / 82)), [] {}, nullptr, "texture_zarya_button", Maths::Vector2f(82, 161), Maths::Vector2f(0, 15));
//	doll_button1->GetComponent<Button>()->SetCallback(std::bind(&Button::DollSelectCapacity, doll_button1->GetComponent<Button>()));
//	GameObject* doll_button2 = CreateSpriteButton_forMainMenu(ButtonType, "doll_button2", Maths::Vector2f((window_size.x / 2 - (window_size.x / 10 * 0.5)), (window_size.y / 2)), Maths::Vector2f(window_size.x / 10, (((window_size.x / 10) * 161) / 82)), [] {}, nullptr, "texture_zvezda_button", Maths::Vector2f(82, 161), Maths::Vector2f(0, 15));
//	doll_button2->GetComponent<Button>()->SetCallback(std::bind(&Button::DollSelectCapacity, doll_button2->GetComponent<Button>()));
//	GameObject* doll_button3 = CreateSpriteButton_forMainMenu(ButtonType, "doll_button3", Maths::Vector2f((window_size.x / 2 + (window_size.x / 10 * 1.5)), (window_size.y / 2)), Maths::Vector2f(window_size.x / 10, (((window_size.x / 10) * 161) / 82)), [] {}, nullptr, "texture_zwezda_button", Maths::Vector2f(82, 161), Maths::Vector2f(0, 15));
//	doll_button3->GetComponent<Button>()->SetCallback(std::bind(&Button::DollSelectCapacity, doll_button3->GetComponent<Button>()));
//
//	GameObject* launch_game_button = CreateSpriteButton_forMainMenu(ButtonType, "launch_game_button", Maths::Vector2f((window_size.x / 2) - (window_size.x / 15), (window_size.y - window_size.y / 100 * 15)), Maths::Vector2f(window_size.x / 15 * 2, ((((window_size.x / 15 * 2) * 168) / 448))), [this] {LaunchFunction::LauchGame(); }, nullptr, "texture_launch_capacity_button", Maths::Vector2f(448, 168), Maths::Vector2f(0, 24));
//	launch_game_button->GetComponent<RectangleShapeRenderer>()->SetColor(launch_game_button->GetComponent<RectangleShapeRenderer>()->GetDisabledColor());
//	launch_game_button->GetComponent<Button>()->is_disabled = true;
//	if (launch_game_button->GetComponent<SpriteRenderer>() != nullptr) {
//		launch_game_button->GetComponent<SpriteRenderer>()->SetNextSpriteRect(3);
//	}
//
//	std::ifstream file("capacity.csv");
//
//	if (!file.is_open()) {
//		std::cerr << "Error opening file." << std::endl;
//	}
//
//	int nb_ligne = 0;
//	int num_capacity = 1;
//	std::string line;
//
//	while (std::getline(file, line)) {
//		nb_ligne++;
//	}
//
//	file.clear();
//	file.seekg(0, std::ios::beg);
//
//	while (std::getline(file, line)) {
//		std::vector<std::string> row;
//		std::stringstream lineStream(line);
//		std::string cell;
//
//		while (std::getline(lineStream, cell, ',')) {
//			row.push_back(cell);
//		}
//
//		Capacity* capacity = new Capacity();
//		capacity->SetName(row[0]);
//		capacity->SetDescription(row[1]);
//		SetTexture("texture_capacity_button_" + std::to_string(num_capacity), "Assets/button/" + row[2]);
//		GameObject* button = CreateSpriteButton_forMainMenu(ButtonType, "capacity_button", Maths::Vector2f((window_size.x / 2) - (window_size.x / 15 / 2 * (nb_ligne % 2)) - (window_size.x / 15 * (nb_ligne / 2)) - (((window_size.x / 15) / 2) * (nb_ligne - 1) / 2) + (window_size.x / 15 * (num_capacity - 1)) + ((window_size.x / 15) / 2 * (num_capacity - 1)), (window_size.y / 100 * 10)),
//			Maths::Vector2f(window_size.x / 15, window_size.x / 15), [] {}, capacity, "texture_capacity_button_" + std::to_string(num_capacity), Maths::Vector2f(144, 161), Maths::Vector2f(0, 15));
//		button->GetComponent<Button>()->SetCallback(std::bind(&Button::SelectCapacity, button->GetComponent<Button>()));
//		num_capacity++;
//	}
//
//	file.close();
//
//	GameObject* text_for_capacity_name = CreateText(TextType, "text_for_capacity_name", Maths::Vector2f(window_size.x / 2 - window_size.x / 4, (window_size.y / 100 * 25)), sf::Color::White, Maths::Vector2u(window_size.x / 4 * 2, (window_size.y / 100 * 10)), 40);
//	GameObject* text_for_capacity_description = CreateText(TextType, "text_for_capacity_description", Maths::Vector2f(window_size.x / 2 - window_size.x / 4, (window_size.y / 100 * 40)), sf::Color::White, Maths::Vector2u(window_size.x / 4 * 2, (window_size.y / 100 * 5)), 30);
//
//	for (int i = 0; i < GetGameObjects()->size(); i++) {
//		GameObject* game_object = (*GetGameObjects())[i];
//		if (game_object->GetName() == "capacity_button") {
//			if (game_object->GetComponent<Button>()->GetObject()->GetName() == _capacitys[0].GetName()) {
//				doll_button1->GetComponent<Button>()->has_select = game_object;
//				game_object->GetComponent<Button>()->is_selected_by = doll_button1;
//			}
//			else if (game_object->GetComponent<Button>()->GetObject()->GetName() == _capacitys[1].GetName()) {
//				doll_button2->GetComponent<Button>()->has_select = game_object;
//				game_object->GetComponent<Button>()->is_selected_by = doll_button2;
//			}
//			else if (game_object->GetComponent<Button>()->GetObject()->GetName() == _capacitys[2].GetName()) {
//				doll_button3->GetComponent<Button>()->has_select = game_object;
//				game_object->GetComponent<Button>()->is_selected_by = doll_button3;
//			}
//		}
//	}
//
//	if (num_poupee == 2) {
//		doll_button1->GetComponent<Button>()->is_disabled = true;
//		doll_button1->GetComponent<SpriteRenderer>()->SetNextSpriteRect(3);
//	}
//	else if (num_poupee == 3) {
//		doll_button1->GetComponent<Button>()->is_disabled = true;
//		doll_button1->GetComponent<SpriteRenderer>()->SetNextSpriteRect(3);
//		doll_button2->GetComponent<Button>()->is_disabled = true;
//		doll_button2->GetComponent<SpriteRenderer>()->SetNextSpriteRect(3);
//	}
//}