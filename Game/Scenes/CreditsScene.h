#pragma once
#include "Scene.h"
#include "Engine.h"
#include "WindowModule.h"
#include <functional>
#include "Components/TextRenderer.h"
#include "GameObject.h"
#include <fstream>
#include <sstream>

#include "LaunchFunction.h"


class CreditsScene final : public Scene
{
public:

	LaunchFunction* launchFunction;


	CreditsScene() : Scene("CreditsScene")
	{
		launchFunction = new LaunchFunction();
		Scene* scene = Engine::GetInstance()->GetModuleManager()->GetModule<SceneModule>()->GetMainScene();
		SetTexture("background", "Assets/background/main_menu_background.png");
		SetTexture("texture_return_button", "Assets/button/return_button.png");
		SetBackground("background");

		SetFont("Font/UkrainianPrincess.ttf");

		sf::Vector2u window_size = Engine::GetInstance()->GetModuleManager()->GetModule<WindowModule>()->GetWindow()->getSize();

		std::ifstream file("credits.csv");

		int nb_ligne = 0;
		std::string line;
		float verticalOffset = 55.0f; // Ajuste l'espacement vertical entre les lignes

		file.clear();
		file.seekg(0, std::ios::beg);

		while (std::getline(file, line) && nb_ligne < 6) { // Limite à 6 lignes pour l'exemple
			GameObject* text_credits = scene->CreateText(TextType, "text_credits", Maths::Vector2f(window_size.x / 2 - window_size.x / 4, (window_size.y / 100 * 25) + (nb_ligne * verticalOffset)), sf::Color::Black, Maths::Vector2u(window_size.x / 4 * 2, (window_size.y / 100 * 10)), 40);
			text_credits->GetComponent<TextRenderer>()->SetString(line);
			nb_ligne++;
		}
		file.close();


		GameObject* return_button = CreateSpriteButton_forMainMenu(ButtonType, "return_button", Maths::Vector2f(window_size.x / 50, window_size.y - window_size.y / 50), Maths::Vector2f(window_size.x / 20, ((((window_size.x / 20) * 161) / 144))), [this] {launchFunction->LaunchMainMenu(); }, nullptr, "texture_return_button", Maths::Vector2f(144, 161), Maths::Vector2f(0, 15));
	}

	~CreditsScene() { delete launchFunction; }
};