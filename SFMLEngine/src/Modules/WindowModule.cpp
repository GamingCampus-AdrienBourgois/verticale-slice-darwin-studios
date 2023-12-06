#include "Modules/WindowModule.h"
#include <SFML/Graphics.hpp>

#include <imgui-SFML.h>
#include <iostream>
#include <SFML/Window/Event.hpp>
#include <vector>

#include "Engine.h"
#include "Modules/SceneModule.h"
#include "Components/RectangleShapeRenderer.h"

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
					// Vérification si le clic de souris est dans la zone du bouton
					if (button->GetComponent<RectangleShapeRenderer>()->GetShape()->getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
					{
						std::cout << "Bouton clique !" << std::endl;
						// Ajoutez ici le code que vous souhaitez exécuter lorsque le bouton est cliqué
					}
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
