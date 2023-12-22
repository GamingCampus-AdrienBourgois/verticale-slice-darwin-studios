#include "Engine.h"

#include <imgui.h>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Modules/SceneModule.h"


#include <iostream>


Engine* Engine::instance = nullptr;
sf::Music Engine::music;

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



	if (!music.openFromFile("Game_files/Assets/Sons/musique_level_3.ogg")) {
		std::cout << "La musique ne charge pas" << std::endl;
	}
	music.setLoop(true);
	music.setVolume(100.f);
	music.play();
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


void Engine::SetMusicState(bool _state) {
	if (_state && music.getStatus() != sf::Sound::Playing)
	{
		music.stop();
		music.play();
	}
	else if (!_state && music.getStatus() == sf::SoundSource::Playing)
	{
		//Faire une descente progressive du son ?
		music.pause();
		//au lieu de mettre ne pause on peut mettre une autre musique maybe ? / Faire une fonction à appeler dans TransitionScene ou Default
		music.setVolume(100.f);
	}
	
}
