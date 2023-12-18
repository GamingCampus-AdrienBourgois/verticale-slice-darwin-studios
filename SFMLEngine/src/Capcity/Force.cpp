#include "Capacity/Force.h"
#include "Components/Player.h"
#include <Scene.h>
#include <Engine.h>
#include <Modules/SceneModule.h>
#include <iostream>

void Force::DeplaceObject(const float _delta_time, GameObject* player, GameObject* gameObjects)
{
	gameObjects->GetComponent<SquareCollider>()->SetCanMoving("up", false);
	gameObjects->GetComponent<SquareCollider>()->SetCanMoving("down", false);
	gameObjects->GetComponent<SquareCollider>()->SetCanMoving("left", true);
	gameObjects->GetComponent<SquareCollider>()->SetCanMoving("right", true);

	if (player->GetPosition().GetX() < gameObjects->GetPosition().GetX())
	{
		if (gameObjects->GetComponent<SquareCollider>()->GetCanMoving()["right"])
		{
			gameObjects->SetPosition(Maths::Vector2f(gameObjects->GetPosition().GetX() + (player->GetComponent<Player>()->GetSpeed() * _delta_time), gameObjects->GetPosition().GetY()));
		}
	}	
	else if (gameObjects->GetComponent<SquareCollider>()->GetCanMoving()["left"])
	{
		gameObjects->SetPosition(Maths::Vector2f(gameObjects->GetPosition().GetX() - (player->GetComponent<Player>()->GetSpeed() * _delta_time), gameObjects->GetPosition().GetY()));
	}
}

void Force::Update(const float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input)
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
			if (gameObject->GetType() != ObjectType::PlayerType && (gameObject->GetType() == MoveType || gameObject->GetType() == DollOffType)) {
				if (player->GetComponent<SquareCollider>()->IsColliding(*player->GetComponent<SquareCollider>(), *gameObject->GetComponent<SquareCollider>(), _delta_time))
				{
					DeplaceObject(_delta_time, player, gameObject);
				}
			}
		}
	}
}