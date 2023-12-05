#include "Modules/WindowModule.h"

#include <imgui-SFML.h>
#include <iostream>
#include <SFML/Window/Event.hpp>

#include "Engine.h"

#include <Windows.h>

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
		else if (event.type == sf::Event::KeyPressed) {
			pressed[event.key.code] = true;
		}

		else if (event.type == sf::Event::KeyReleased) {
			pressed[event.key.code] = false;
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


sf::Vector2u WindowModule::GetWindowSize() {
	try
	{
		return window->getSize();
	}
	catch (const std::exception&)
	{
		return sf::Vector2u(0, 0);
	}
	
}
