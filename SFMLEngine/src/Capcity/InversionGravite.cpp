#include "Capacity/InversionGravite.h"
#include <Scene.h>
#include <Engine.h>
#include <Modules/SceneModule.h>
#include <Components/Player.h>
#include <iostream>

void InversionGravite::GraviteInversion(GameObject* player, const float _delta_time)
{
	gravity = player->GetComponent<Player>()->GetGravity();

	if (count == 0)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		{
			if (!player->GetComponent<SquareCollider>()->GetCanMoving()["down"])
			{
				inversionClock.restart();
				inversion = true;
				count = 1;
			}
		}
	}
	if (inversion == true && player->GetComponent<SquareCollider>()->GetCanMoving()["up"])
	{
		if (inversionClock.getElapsedTime().asSeconds() <= 1) {
			GetCapacityOwner()->GetComponent<Player>()->SetGravity(-200);
		}
		else if (inversionClock.getElapsedTime().asSeconds() <= 2) {
			GetCapacityOwner()->GetComponent<Player>()->SetGravity(-200);
		}
		else if (inversionClock.getElapsedTime().asSeconds() <= 3) {
			GetCapacityOwner()->GetComponent<Player>()->SetGravity(-200);
		}
		else if (inversionClock.getElapsedTime().asSeconds() <= 4) {
			GetCapacityOwner()->GetComponent<Player>()->SetGravity(-300);
		}
		else if (inversionClock.getElapsedTime().asSeconds() <= 5) {
			GetCapacityOwner()->GetComponent<Player>()->SetGravity(-300);
		}
		else if (inversionClock.getElapsedTime().asSeconds() <= 6) {
			GetCapacityOwner()->GetComponent<Player>()->SetGravity(-400);
		}
		else if (inversionClock.getElapsedTime().asSeconds() <= 7) {
			GetCapacityOwner()->GetComponent<Player>()->SetGravity(-400);
		}
		else if (inversionClock.getElapsedTime().asSeconds() <= 8) {
			GetCapacityOwner()->GetComponent<Player>()->SetGravity(-500);
			std::cout << "te la" << std::endl;
		}
		else {
			inversion = false;
			GetCapacityOwner()->GetComponent<Player>()->SetGravity(gravity);
		}
		
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