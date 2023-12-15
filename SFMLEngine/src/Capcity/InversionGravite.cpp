#include "Capacity/InversionGravite.h"
#include <Scene.h>
#include <Engine.h>
#include <Modules/SceneModule.h>
#include <Components/Player.h>
#include <iostream>

void InversionGravite::GraviteInversion(GameObject* player, const float _delta_time)
{
	if (count == 0)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		{
			if (!player->GetComponent<SquareCollider>()->GetCanMoving()["down"])
			{
					Inversion.restart();
					inversion = true;
			}
		}
	}
	else
	{
		inversion = false;
	}
	if (inversion == true && player->GetComponent<SquareCollider>()->GetCanMoving()["up"])
	{
		if (Inversion.getElapsedTime().asSeconds() <= 1) {
			GetOwner()->SetPosition(Maths::Vector2f(GetOwner()->GetPosition().GetX(), GetOwner()->GetPosition().GetY() - (500 * _delta_time)));
		}
		else if (Inversion.getElapsedTime().asSeconds() <= 2) {
			GetOwner()->SetPosition(Maths::Vector2f(GetOwner()->GetPosition().GetX(), GetOwner()->GetPosition().GetY() - (400 * _delta_time)));
		}
		else if (Inversion.getElapsedTime().asSeconds() <= 3) {
			GetOwner()->SetPosition(Maths::Vector2f(GetOwner()->GetPosition().GetX(), GetOwner()->GetPosition().GetY() - (300 * _delta_time)));
		}
		else if (Inversion.getElapsedTime().asSeconds() <= 4) {
			GetOwner()->SetPosition(Maths::Vector2f(GetOwner()->GetPosition().GetX(), GetOwner()->GetPosition().GetY() - (200 * _delta_time)));
		}
		else if (Inversion.getElapsedTime().asSeconds() <= 5) {
			GetOwner()->SetPosition(Maths::Vector2f(GetOwner()->GetPosition().GetX(), GetOwner()->GetPosition().GetY() - (150 * _delta_time)));
		}
		else if (Inversion.getElapsedTime().asSeconds() <= 6) {
			GetOwner()->SetPosition(Maths::Vector2f(GetOwner()->GetPosition().GetX(), GetOwner()->GetPosition().GetY() - (100 * _delta_time)));
		}
		else if (Inversion.getElapsedTime().asSeconds() <= 7) {
			GetOwner()->SetPosition(Maths::Vector2f(GetOwner()->GetPosition().GetX(), GetOwner()->GetPosition().GetY() - (75 * _delta_time)));
		}
		else if (Inversion.getElapsedTime().asSeconds() <= 8) {
			GetOwner()->SetPosition(Maths::Vector2f(GetOwner()->GetPosition().GetX(), GetOwner()->GetPosition().GetY() - (35 * _delta_time)));
		}
		else if (Inversion.getElapsedTime().asSeconds() <= 9) {
			GetOwner()->SetPosition(Maths::Vector2f(GetOwner()->GetPosition().GetX(), GetOwner()->GetPosition().GetY() - (0 * _delta_time)));
		}
		else if (Inversion.getElapsedTime().asSeconds() <= 10) {
			GetOwner()->SetPosition(Maths::Vector2f(GetOwner()->GetPosition().GetX(), GetOwner()->GetPosition().GetY() - (0 * _delta_time)));
			count = count + 1;
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