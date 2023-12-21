#include "MapScene.h"

#include "LaunchFunction.h"
#include "SelectCapacityScene.h"

MapScene::MapScene() : Scene("MapScene")
{
	SetTexture("texture_return_button", "Assets/button/return_button.png");
	SetTexture("texture_livre", "Assets/Object/livre.png");
	SetTexture("background", "Assets/background/Level3.map.png");
	SetBackground("background");

	sf::Vector2f window_size = Engine::GetInstance()->GetModuleManager()->GetModule<WindowModule>()->GetWindowSize();

	float sizeX = window_size.x / 100;
	float sizeY = window_size.y / 100;

	//GameObject* livre = CreateObject(this, MoveType, "LivreMove", Maths::Vector2f(sizeX * 39.7412, sizeY * 40.9), Maths::Vector2f(sizeX * 1.73684, sizeY * 13.7), "texture_livre", Maths::Vector2f(0, 0), Maths::Vector2f(0, 0));

	GameObject* return_button = CreateSpriteButton_forMainMenu(ButtonType, "return_button", Maths::Vector2f(window_size.x / 50, window_size.y - window_size.y / 50 - 144), Maths::Vector2f(window_size.x / 20, ((((window_size.x / 20) * 161) / 144))), [this] {LaunchFunction::LaunchScene<SelectCapacityScene>();; }, nullptr, "texture_return_button", Maths::Vector2f(144, 161), Maths::Vector2f(0, 15));
}