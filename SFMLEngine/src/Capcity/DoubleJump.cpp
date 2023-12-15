#include "Capacity/DoubleJump.h"
#include "Engine.h"
#include "Scene.h"
#include "Modules/SceneModule.h"
#include "Components/Player.h"

void DoubleJump::SetDoubleJump(bool _can_double_jump) {
	/*Scene* scene = Engine::GetInstance()->GetModuleManager()->GetModule<SceneModule>()->GetMainScene();
	GameObject* player = nullptr;
	for (int i = 0; i < scene->GetGameObjects()->size(); i++)
	{
		if ((*scene->GetGameObjects())[i]->GetType() == PlayerType) {
			player = (*scene->GetGameObjects())[i];
		}
	}*/
	GetOwner()->GetComponent<Player>()->SetCanDoubleJump(_can_double_jump);
}