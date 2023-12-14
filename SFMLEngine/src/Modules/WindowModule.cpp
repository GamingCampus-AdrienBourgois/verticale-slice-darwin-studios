#include "Modules/WindowModule.h"
#include <SFML/Graphics.hpp>

#include <imgui-SFML.h>
#include <iostream>
#include <SFML/Window/Event.hpp>
#include <vector>

#include "Engine.h"
#include "Modules/SceneModule.h"
#include "Scene.h"

void WindowModule::Init()
{
	Module::Init();

	window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "SFML Engine", sf::Style::Fullscreen);
}

void WindowModule::Start()
{
	Module::Start();
}

void WindowModule::Update()
{
	Module::Update();
	Scene* scene = moduleManager->GetModule<SceneModule>()->GetMainScene();

	sf::Event event;
	while (window->pollEvent(event))
	{
		ImGui::SFML::ProcessEvent(*window, event);

		if (event.type == sf::Event::Closed)
		{
			Engine::GetInstance()->Quit();
		}
		if (event.type == sf::Event::KeyPressed) {
			pressed[event.key.code] = true;
		}

		if (event.type == sf::Event::KeyReleased) {
			pressed[event.key.code] = false;
		}

		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				sf::Vector2i mousePos = sf::Mouse::getPosition(*window);

				Scene* scene = moduleManager->GetModule<SceneModule>()->GetMainScene();

				for (GameObject* const& button : *scene->GetGameObjects()){
					if (button->GetType() == ButtonType) {
						if (button->GetComponent<RectangleShapeRenderer>()->GetShape()->getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)) && !button->GetComponent<Button>()->is_disabled)
						{
							RectangleShapeRenderer* rectangleShapeRenderer = button->GetComponent<RectangleShapeRenderer>();
							SpriteRenderer* spriteRenderer = button->GetComponent<SpriteRenderer>();
							if (button->GetComponent<Button>()->is_clicked) {
								button->GetComponent<Button>()->is_clicked = false;
								rectangleShapeRenderer->SetColor(rectangleShapeRenderer->GetDefaultColor());
								if (spriteRenderer != nullptr) {
									spriteRenderer->SetNextSpriteRect(0);
								}
							}
							else {
								button->GetComponent<Button>()->is_clicked = true;
								rectangleShapeRenderer->SetColor(rectangleShapeRenderer->GetClickColor());
								if (spriteRenderer != nullptr) {
									spriteRenderer->SetNextSpriteRect(2);
								}
							}
							if (button->GetName() == "capacity_button") {
								ResetButton(button, { "capacity_button" });
							}
							else if (button->GetName() == "doll_button1" || button->GetName() == "doll_button2" || button->GetName() == "doll_button3") {
								std::vector<std::string> _name = { "doll_button1", "doll_button2", "doll_button3" };
								ResetButton(button, _name);
							}
						}
					}
				}
			}if (event.mouseButton.button == sf::Mouse::Right) {
				mousePos.push_back(sf::Mouse::getPosition(*window));
				float sizeX = GetWindowSize().x / 100;
				float sizeY = GetWindowSize().y / 100;
				std::cout << "r = "<<  mousePos.size() <<std::endl;
				if(mousePos.size() % 2 == 0){
					std::cout << mousePos[0].x / sizeX << " " << mousePos[0].y / sizeY << " " << (mousePos[1].x - mousePos[0].x) / sizeX << " " << (mousePos[1].y - mousePos[0].y) / sizeY << std::endl;
				}
			}
		}
	}
}

void WindowModule::PreRender()
{
	Module::PreRender();

	window->clear(sf::Color::Black);
}

void WindowModule::Render()
{
	Module::Render();
}

void WindowModule::PostRender()
{
	Module::PostRender();

	window->display();
}

void WindowModule::Release()
{
	Module::Release();

	window->close();
}

void WindowModule::ResetButton(GameObject* button, std::vector<std::string> _name) {
	Scene* scene = moduleManager->GetModule<SceneModule>()->GetMainScene();
	for (GameObject* const& gameObject : *scene->GetGameObjects()) {
		for (std::string button_name : _name) {
			if (gameObject->GetType() == ButtonType && gameObject->GetName() == button_name && button != gameObject && !gameObject->GetComponent<Button>()->is_disabled) {
				gameObject->GetComponent<Button>()->is_clicked = false;
				gameObject->GetComponent<RectangleShapeRenderer>()->SetColor(gameObject->GetComponent<RectangleShapeRenderer>()->GetDefaultColor());
				if (gameObject->GetComponent<SpriteRenderer>() != nullptr) {
					gameObject->GetComponent<SpriteRenderer>()->SetNextSpriteRect(0);
				}
			}
		}
	}
}
