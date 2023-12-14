#include "Capacity/InversionGravite.h"
#include <Scene.h>
#include <Engine.h>
#include <Modules/SceneModule.h>
#include <Components/Player.h>
#include <iostream>

void InversionGravite::GraviteInversion(GameObject* player, const float _delta_time)
{
	gravite = player->GetComponent<Player>()->GetGravity();
	inversionGravite = inversionGravite - gravite;

	if (StartClockDurationInversion.getElapsedTime().asSeconds() >= timeInversion && inversion && count == 1)
	{
		std::cout << "tu tombe" << std::endl;
		inversion = false;
		active = false;
		player->GetComponent<Player>()->SetGravity(gravite);
		player->SetPosition(Maths::Vector2f(player->GetPosition().GetX(), (player->GetPosition().GetY() + (gravite * _delta_time))));
	}
	if (count == 0)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		{
			active = true;
			if (active == true)
			{
				if (!player->GetComponent<SquareCollider>()->GetCanMoving()["down"])
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
	
	if (inversion == true && !player->GetComponent<SquareCollider>()->GetCanMoving()["up"])
	{
		player->SetPosition(Maths::Vector2f(player->GetPosition().GetX(), (player->GetPosition().GetY() - inversionGravite)));
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
			GraviteInversion(player, _delta_time);
		}
	}
	
}