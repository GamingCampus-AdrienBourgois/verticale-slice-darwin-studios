#include "Capacity/InversionGravite.h"
#include <Scene.h>
#include <Engine.h>
#include <Modules/SceneModule.h>

void InversionGravite::GraviteInversion()
{

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
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		inversion = true;
		if (inversion)
		{
			GraviteInversion();
		}
	}
}