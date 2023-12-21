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

void SetSettingsOnFile() {

	const std::string nomFichier = "settings.csv";
	SceneModule* scene_module = Engine::GetInstance()->GetModuleManager()->GetModule<SceneModule>();

	std::ofstream fichierCSV(nomFichier);

	if (!fichierCSV.is_open()) {
		std::cerr << "Erreur : Impossible d'ouvrir le fichier " << nomFichier << std::endl;
	}

	fichierCSV << "Volume," << std::to_string(scene_module->GetSoundVolume()) << "," << std::endl;
	fichierCSV << ",," << std::endl;

	std::map<std::string, Input*>* controls = Engine::GetInstance()->GetModuleManager()->GetModule<InputModule>()->GetControls();
	for (auto& entry_pair : *controls) {
		Input* entry = controls->at(entry_pair.first);
		fichierCSV << entry_pair.first << "," << entry->GetName() << "," << std::to_string(entry->GetEntry()) << std::endl;
	}

	fichierCSV.close();
}
