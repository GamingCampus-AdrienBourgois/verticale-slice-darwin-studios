#pragma once
#include "Scene.h"
#include "RectangleShapeRenderer.h"
#include "Engine.h"
#include "WindowModule.h"

#include <functional>

#include "MainMenuScene.h"



class EndLevelScene final : public Scene
{
public:



	sf::Vector2f window_size = Engine::GetInstance()->GetModuleManager()->GetModule<WindowModule>()->GetWindowSize();
	float button_size_x = window_size.x / 15 * 3;
	float button_size_y = (((window_size.x / 15) * 3) * 168 / 448);


	EndLevelScene() : Scene("EndLevelScene") {

		SetFont("Font/UkrainianPrincess.ttf");
		SetTexture("texture_button", "Assets/button/button.png"); 

		GameObject* shapeBackground = CreateShapeAlone(ShapeType, "BackgroundScene", Maths::Vector2f(0, 0), sf::Color(128, 128, 128, 128), window_size);
		GameObject* endLevelText = CreateText(TextType, "textEndLevel", Maths::Vector2f(window_size.x / 2 - window_size.x / 4, (window_size.y / 100 * 25)), sf::Color::White, Maths::Vector2u(window_size.x / 4 * 2, (window_size.y / 100 * 10)), 40);
		GameObject* nextLevelEndScene = CreateSpriteButtonWithText(ButtonType, "NextLevelButton", Maths::Vector2f(((window_size.x / 2) - (button_size_x / 2)), window_size.y * 4 / 6), Maths::Vector2f(button_size_x, button_size_y), [] {}, nullptr, "texture_button", Maths::Vector2f(448, 168), Maths::Vector2f(0, 24), "Prochain niveau", sf::Color::Black, 30);
		GameObject* menuButtonEndScene = CreateSpriteButtonWithText(ButtonType, "QuitButton", Maths::Vector2f(((window_size.x / 2) - (button_size_x / 2)), window_size.y * 3 / 6), Maths::Vector2f(button_size_x, button_size_y), [this] {LaunchMainMenu(); }, nullptr, "texture_button", Maths::Vector2f(448, 168), Maths::Vector2f(0, 24), "Retour Menu", sf::Color::Black, 30);

		endLevelText->GetComponent<TextRenderer>()->SetString("Vous avez termin� le niveau 3 !");

		nextLevelEndScene->GetComponent<Button>()->is_disabled = true;
		if (nextLevelEndScene->GetComponent<Button>()->is_disabled)
		{
			nextLevelEndScene->GetComponent<SpriteRenderer>()->SetNextSpriteRect(3);
		}
 	}

private:
	void LaunchMainMenu() {
		SceneModule* scene_module = Engine::GetInstance()->GetModuleManager()->GetModule<SceneModule>();
		scene_module->SetNextScene([scene_module] {scene_module->SetScene<MainMenuScene>(); });
	}
};