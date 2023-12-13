#include "Capacity/Invincibilite.h"
#include <Scene.h>
#include <Engine.h>
#include <Modules/SceneModule.h>
#include <Components/Player.h>
#include <iostream>

void Invincibilite::Immortel(GameObject* player)
{
	StartClockInvincibilite.restart();
	int immortel = 5 ^ 10;
	int hp_actuel = player->GetComponent<Player>()->GetHp();

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && StartClockInvincibilite.getElapsedTime().asSeconds() < 10)
	{
		player->GetComponent<Player>()->SetHp(immortel);
		std::cout << "Vie player immortel " << player->GetComponent<Player>()->GetHp() << std::endl;
	}

	player->GetComponent<Player>()->SetHp(hp_actuel);
}

void Invincibilite::Update(const float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input)
{
	Scene* scene = Engine::GetInstance()->GetModuleManager()->GetModule<SceneModule>()->GetMainScene();
	GameObject* player = nullptr;

	for (GameObject* const& gameObject : *scene->GetGameObjects())
	{
		if (gameObject->GetType() == PlayerType)
		{
			player = gameObject;
		}
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		Immortel(player);
	}
}