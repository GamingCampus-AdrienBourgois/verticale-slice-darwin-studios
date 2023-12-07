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
						if (button->GetComponent<RectangleShapeRenderer>()->GetShape()->getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
						{
							if (button->GetComponent<Button>()->is_clicked) {
								button->GetComponent<Button>()->is_clicked = false;
							}
							else {
								button->GetComponent<Button>()->is_clicked = true;
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
				sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
				std::cout << mousePos.x << " " << mousePos.y << std::endl;
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
			if (gameObject->GetType() == ButtonType && gameObject->GetName() == button_name && button != gameObject) {
				gameObject->GetComponent<Button>()->is_clicked = false;
			}
		}
	}
}
