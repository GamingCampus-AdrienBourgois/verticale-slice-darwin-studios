#include "Scene.h"

#include "Modules/SceneModule.h" 
#include "Engine.h"


#include "Components/Button.h"

#include <unordered_map>
#include <SFML/Window/Event.hpp>

#include <SFML/Graphics/RenderWindow.hpp>

Scene::Scene(const std::string& _name)
{
	name = _name;
	//font_scene = Engine::GetInstance()->GetModuleManager()->GetModule<SceneModule>()->GetFont();

	Engine* engine = Engine::GetInstance();
	ModuleManager* moduleManager = engine->GetModuleManager();
	SceneModule* sceneModule = moduleManager->GetModule<SceneModule>();
	font_scene = sceneModule->GetFont();
}

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

std::string Scene::GetName() const
{
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


GameObject* Scene::CreateButton(const ObjectName& _name, Maths::Vector2f _position, const sf::Color _color, Maths::Vector2u size, std::string button_name, std::string button_text)
{
	GameObject* game_object = CreateGameObject(_name);
	game_object->SetPosition(_position);

	SquareCollider* square_collider = game_object->CreateComponent<SquareCollider>();
	square_collider->SetWidth(20.f);
	square_collider->SetHeight(20.f);

	RectangleShapeRenderer* shape_renderer = game_object->CreateComponent<RectangleShapeRenderer>();
	shape_renderer->SetColor(_color);
	shape_renderer->SetSize(Maths::Vector2f(size.x, size.y));

	Button* button = game_object->CreateComponent<Button>();
	button->SetName(button_name);
	button->SetText(button_text);

	return game_object;
}
