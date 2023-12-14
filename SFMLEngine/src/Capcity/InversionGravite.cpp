#include "Capacity/InversionGravite.h"
#include <Scene.h>
#include <Engine.h>
#include <Modules/SceneModule.h>
#include <Components/Player.h>
#include <iostream>

void InversionGravite::GraviteInversion(GameObject* player, const float _delta_time, std::vector<GameObject*>* gameObjects)
{
	gravite = player->GetComponent<Player>()->GetGravity();
	inversionGravite = inversionGravite - gravite;

	if (StartClockDurationInversion.getElapsedTime().asSeconds() >= timeInversion && inversion && count == 1)
	{
		inversion = false;
		active = false;
	}
	std::cout << count << std::endl;
	if (count == 0)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		{
			active = true;
			if (active == true)
			{
				if (!player->GetComponent<SquareCollider>()->GetCanMoving()["up"] || !player->GetComponent<SquareCollider>()->GetCanMoving()["down"])
				{
					StartClockDurationInversion.restart();
					player->GetComponent<Player>()->SetGravity(inversionGravite);
					inversion = true;
				}
				count = count + 1;
			}
		}
	}
	else
	{
		inversion = false;
	}
	
	if (inversion == true)
	{
		player->SetPosition(Maths::Vector2f(player->GetPosition().GetX(), (player->GetPosition().GetY() + (inversionGravite * _delta_time))));
	}
}

void InversionGravite::Update(const float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input)
{
	Scene* scene = Engine::GetInstance()->GetModuleManager()->GetModule<SceneModule>()->GetMainScene();
	GameObject* player = nullptr;

	for (GameObject* const& gameObject : *scene->GetGameObjects())
	{
		if (gameObject->GetType() == PlayerType)
		{
			player = gameObject;
		}
		if (player != nullptr)
		{
			GraviteInversion(player, _delta_time, scene->GetGameObjects());
		}
	}
	
}