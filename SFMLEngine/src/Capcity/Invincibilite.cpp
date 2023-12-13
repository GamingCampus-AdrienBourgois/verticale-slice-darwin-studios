#include "Capacity/Invincibilite.h"
#include <Scene.h>
#include <Engine.h>
#include <Modules/SceneModule.h>
#include <Components/Player.h>
#include <iostream>

void Invincibilite::Immortel(GameObject* player)
{
	StartClockInvincibilite.restart();
	int immortel = 10000000;
	int hp_actuel = player->GetComponent<Player>()->GetHp();

	if (StartClockInvincibilite.getElapsedTime().asSeconds() <= 10 && onOff == true)
	{
		player->GetComponent<Player>()->SetHp(immortel);
		//std::cout << "ta vie " << player->GetComponent<Player>()->GetHp() << std::endl;
	}

	player->GetComponent<Player>()->SetHp(hp_actuel);
	onOff = false;
}

void Invincibilite::Update(const float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input)
{
	Scene* scene = Engine::GetInstance()->GetModuleManager()->GetModule<SceneModule>()->GetMainScene();
	GameObject* player = nullptr;
	std::cout << onOff << std::endl;

	for (GameObject* const& gameObject : *scene->GetGameObjects())
	{
		if (gameObject->GetType() == PlayerType)
		{
			player = gameObject;
		}
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		onOff = true;
		if (onOff == true)
		{
			std::cout << onOff << std::endl;
			Immortel(player);
		}
	}
}