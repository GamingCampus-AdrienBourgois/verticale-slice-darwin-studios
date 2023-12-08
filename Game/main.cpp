#include "Engine.h"
#include "SceneModule.h"
#include "Scenes/DefaultScene.h"
#include "Scenes/SelectCapacityScene.h"
#include "Scenes/MainMenuScene.h"

int main()
{
	const Engine* engine = Engine::GetInstance();

	engine->Init();

	SceneModule* scene_module = engine->GetModuleManager()->GetModule<SceneModule>();
	scene_module->SetScene<MainMenuScene>();
	scene_module->SetScene<SelectCapacityScene>(false);
	scene_module->SetScene<DefaultScene>(false);

	engine->Run();

	return 0;
}
