#include "Engine.h"

#include <imgui.h>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Modules/SceneModule.h"

Engine* Engine::instance = nullptr;

Engine* Engine::GetInstance()
{
	if (instance == nullptr)
		instance = new Engine();

	return instance;
}

void Engine::Init() const
{
	moduleManager->CreateDefaultModules();
	moduleManager->Init();
}

void Engine::Run() const
{
	moduleManager->Start();

	while (!shouldQuit)
	{
		moduleManager->Update();
		moduleManager->PreRender();
		moduleManager->Render();
		moduleManager->PostRender();
		if (moduleManager->GetModule<SceneModule>()->GetNextScene()) {
			moduleManager->GetModule<SceneModule>()->GetNextScene()();
			moduleManager->GetModule<SceneModule>()->SetNextScene([] {});
		}
	}

	moduleManager->Release();
	moduleManager->Finalize();
}
