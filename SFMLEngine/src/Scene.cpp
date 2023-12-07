#include "Scene.h"
#include <unordered_map>
#include <SFML/Window/Event.hpp>

#include <SFML/Graphics/RenderWindow.hpp>

Scene::Scene(const std::string& _name) : name(_name) {}


void Scene::Update(const float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input) const
{
	for (GameObject* const& game_object : gameObjects)
	{
		game_object->Update(_delta_time, pressed_input);
	}
}

void Scene::Render(sf::RenderWindow* _window) const
{
	for (GameObject* const& game_object : gameObjects)
	{
		game_object->Render(_window);
	}
}


std::string Scene::GetName() const {
	return name;
}

GameObject* Scene::CreateGameObject(const ObjectName& _name)
{
	GameObject* const game_object = new GameObject();
	game_object->SetName(_name);
	gameObjects.push_back(game_object);
	return game_object;
}

void Scene::DestroyGameObject(const GameObject* _game_object)
{
	for (std::vector<GameObject*>::iterator it = gameObjects.begin(); it != gameObjects.end(); ++it)
	{
		if (*it == _game_object)
		{
			gameObjects.erase(it);
			delete _game_object;
			return;
		}
	}
}

GameObject* Scene::FindGameObject(const ObjectName& _name) const
{
	for (GameObject* const& game_object : gameObjects)
	{
		if (game_object->GetName() == _name)
		{
			return game_object;
		}
	}
	return nullptr;
}