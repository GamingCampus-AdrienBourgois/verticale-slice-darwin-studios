#include "OptionsScene.h"

#include <fstream>
#include <iostream>
#include "Engine.h"
#include "LaunchFunction.h"
#include "MainMenuScene.h"
#include "SceneModule.h"
#include "WindowModule.h"

OptionsScene::OptionsScene() : Scene("OptionsScene")
{
	SetTexture("background", "Assets/background/main_menu_background.png");
	SetTexture("texture_return_button", "Assets/button/return_button.png");
	SetBackground("background");

	SetFont("Font/UkrainianPrincess.ttf");

    sf::Vector2u window_size = Engine::GetInstance()->GetModuleManager()->GetModule<WindowModule>()->GetWindow()->getSize();
    sf::RenderWindow* window = Engine::GetInstance()->GetModuleManager()->GetModule<WindowModule>()->GetWindow();

    WindowModule* windowModule = Engine::GetInstance()->GetModuleManager()->GetModule<WindowModule>();
    if (windowModule) {
        sf::Vector2i mousePos = windowModule->GetMousePosition();
        GameObject* sliderButton = CreateSliderButton(ButtonType, "slider_button", Maths::Vector2f(window_size.x / 10, window_size.y - 500), Maths::Vector2f(window_size.x / 20, ((((window_size.x / 20) * 161) / 144))), [this] { LaunchFunction::LaunchScene<MainMenuScene>(); }, nullptr, "texture_return_button", Maths::Vector2f(144, 161), Maths::Vector2f(0, 15));
        sliderButton->SetPosition(Maths::Vector2f(mousePos.x, sliderButton->GetPosition().y));
    }

	GameObject* slider_button = CreateSliderButton(ButtonType, "slider_button", Maths::Vector2f(window_size.x / 10, window_size.y - 500), Maths::Vector2f(window_size.x / 20, ((((window_size.x / 20) * 161) / 144))), [this] { LaunchFunction::LaunchScene<MainMenuScene>(); }, nullptr, "texture_return_button", Maths::Vector2f(144, 161), Maths::Vector2f(0, 15));
	GameObject* return_button = CreateSpriteButton_forMainMenu(ButtonType, "return_button", Maths::Vector2f(window_size.x / 50, window_size.y - window_size.y / 50 - 144), Maths::Vector2f(window_size.x / 20, ((((window_size.x / 20) * 161) / 144))), [this] { LaunchFunction::LaunchScene<MainMenuScene>(); }, nullptr, "texture_return_button", Maths::Vector2f(144, 161), Maths::Vector2f(0, 15));
}