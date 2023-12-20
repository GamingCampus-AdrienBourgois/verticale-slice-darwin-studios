#pragma once
#include "Scene.h"
#include "Engine.h"
#include <vector>

#include "WindowModule.h"
#include "SceneModule.h"


class SelectCapacityScene;
class MainMenuScene;

class PauseScene final : public Scene {
public:

	sf::Vector2f window_size = Engine::GetInstance()->GetModuleManager()->GetModule<WindowModule>()->GetWindowSize();
	float button_size_x = window_size.x / 15 * 3;
	float button_size_y = (((window_size.x / 15) * 3) * 168 / 448);


	PauseScene() : Scene("PauseScene") {
		SetFont("Font/UkrainianPrincess.ttf");
		SetTexture("texture_button", "Assets/button/button.png");

		GameObject* shapeBackground = CreateShapeAlone(ShapeType, "BackgroundScene", Maths::Vector2f(0, 0), sf::Color(128, 128, 128, 128), window_size);
		GameObject* textPause = CreateText(TextType, "textPause", Maths::Vector2f(window_size.x / 2 - window_size.x / 4, (window_size.y / 100 * 25)), sf::Color::White, Maths::Vector2u(window_size.x / 4 * 2, (window_size.y / 100 * 10)), 40);
		GameObject* resumeButton = CreateSpriteButtonWithText(ButtonType, "resume_button", Maths::Vector2f(((window_size.x / 2) - (button_size_x / 2)), window_size.y * 5 / 6), Maths::Vector2f(button_size_x, button_size_y), [this] {resumeGame(); }, nullptr, "texture_button", Maths::Vector2f(448, 168), Maths::Vector2f(0, 24), "Retour au jeu", sf::Color::Black, 30);
		GameObject* restartButton = CreateSpriteButtonWithText(ButtonType, "restart_button", Maths::Vector2f(((window_size.x / 2) - (button_size_x / 2)), window_size.y * 4 / 6), Maths::Vector2f(button_size_x, button_size_y), [this] {launchRestart(); }, nullptr, "texture_button", Maths::Vector2f(448, 168), Maths::Vector2f(0, 24), "Recommencer la partie", sf::Color::Black, 30);
		GameObject* quitButton = CreateSpriteButtonWithText(ButtonType, "quit_button", Maths::Vector2f(((window_size.x / 2) - (button_size_x / 2)), window_size.y * 3 / 6), Maths::Vector2f(button_size_x, button_size_y), [this] {LaunchMainMenu(); }, nullptr, "texture_button", Maths::Vector2f(448, 168), Maths::Vector2f(0, 24), "Retour au menu", sf::Color::Black, 30);
	
		textPause->GetComponent<TextRenderer>()->SetString("Pause");	
	}

private:
	void launchRestart() {
		SceneModule* scene_module = Engine::GetInstance()->GetModuleManager()->GetModule<SceneModule>();
		scene_module->SetNextScene([scene_module] {scene_module->SetScene<SelectCapacityScene>(); });
	}

	void LaunchMainMenu() {
		SceneModule* scene_module = Engine::GetInstance()->GetModuleManager()->GetModule<SceneModule>();
		scene_module->SetNextScene([scene_module] {scene_module->SetScene<MainMenuScene>(); }); 
	}

	void resumeGame() {
		SceneModule* scene_module = Engine::GetInstance()->GetModuleManager()->GetModule<SceneModule>();

		std::vector<Scene*>* scenes = scene_module->GetScenesVector();
		scene_module->SetMainScene((*scenes)[scenes->size() - 2]);
		scenes->erase(scenes->end() - 1);
	}
};