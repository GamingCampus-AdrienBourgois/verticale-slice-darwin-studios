#include "Capacity/Dash.h"
#include "Components/Player.h"

void Dash::IsDashing(const float _delta_time, std::vector<GameObject*>* gameObjects)
{
	GameObject* player = nullptr;

	for (GameObject* const& gameObject : *gameObjects)
	{
		if (gameObject->GetType() == PlayerType)
		{
			player = gameObject;
			break;
		}
	}

	if (player != nullptr)
	{
		if ((speed_dash > 0 && !player->GetComponent<SquareCollider>()->GetCanMoving()["right"]) || (speed_dash < 0 && !player->GetComponent<SquareCollider>()->GetCanMoving()["left"]) || (StartClockDurationDash.getElapsedTime().asMilliseconds() >= timeDash && is_dashing))
		{
			is_dashing = false;
			StartClockCooldownDash.restart();
		}

		// Si le dash est possible et n'est pas en cours
		if (StartClockCooldownDash.getElapsedTime().asMilliseconds() >= CooldownDash && !is_dashing)
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && player->GetComponent<SquareCollider>()->GetCanMoving()["right"])
				{
					speed_dash = 3;
					is_dashing = true;
					StartClockDurationDash.restart(); // Redémarre le temps du dash
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && player->GetComponent<SquareCollider>()->GetCanMoving()["left"])
				{
					speed_dash = -3;
					is_dashing = true;
					StartClockDurationDash.restart(); // Redémarre le temps du dash
				}
			}
		}

		// Si le dash est en cours et le cooldown dépasse 5 secondes
		if (is_dashing)
		{
			player->SetPosition(Maths::Vector2f(player->GetPosition().GetX() + speed_dash, player->GetPosition().GetY()));
		}
	}
}

void Dash::Update(const float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input)
{
	std::vector<GameObject*>* gameObjects = Engine::GetInstance()->GetModuleManager()->GetModule<SceneModule>()->GetMainScene()->GetGameObjects();
	IsDashing(_delta_time, gameObjects);
}
